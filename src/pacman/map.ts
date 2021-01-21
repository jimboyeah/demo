import Stage from './stage'
import { Level } from './level'

export interface Step {
    x: number
    y: number
    change?: boolean // 指示是否要转向
}
export interface FinderParam {
    map: number[][]
    start: Step
    end: Step
    type: FinderType
}

export enum FinderType {
    Path,
    Next
}

export default class Map {

    params: Partial<Map>
    stage: Stage
    rawData: Level
    data: number[][] = []
    id: number = 0

    x: number = 0       // 地图像素坐标
    y: number = 0
    xLength: number = 0 // 地图格子长度
    yLength: number = 0
    size: number = 20   // 地图格子单元宽度

    frames: number = 1   //速度等级 内部计算器times多少帧变化一次
    times: number = 0    //刷新画布计数(用于循环动画状态判断)
    cache: boolean = false
    imageData?: ImageData
    update: () => void = () => { }
    draw: (context: CanvasRenderingContext2D) => void = () => { }

    constructor(stage: Stage, params: Partial<Map>) {
        this.params = params || {};
        this.stage = stage;
        this.rawData = {} as Level;
        Object.assign(this, this.params);
        this.yLength = this.data.length;
        this.xLength = this.data[0].length;
    }

    get(x: number, y: number) {
        if (this.data[y] && typeof this.data[y][x] != 'undefined') {
            return this.data[y][x];
        }
        return -1;
    };

    set(x: number, y: number, value: number) {
        if (this.data[y]) {
            this.data[y][x] = value;
        }
    };
    // 画布坐标<=>地图坐标
    coord2position(cx: number, cy: number) {
        let half = this.size / 2;
        return {
            x: this.x + cx * this.size + half,
            y: this.y + cy * this.size + half
        };
    };

    position2coord(x: number, y: number) {
        let half = this.size / 2;
        var fx = Math.abs(x - this.x) % this.size - half;
        var fy = Math.abs(y - this.y) % this.size - half;
        return {
            x: Math.floor((x - this.x) / this.size),
            y: Math.floor((y - this.y) / this.size),
            offset: Math.sqrt(fx * fx + fy * fy)
        };
    };

    //寻路算法
    finder(params: FinderParam) {
        var defaults = {
            map: null,
            start: {},
            end: {},
            type: FinderType.Path
        };
        var options: FinderParam = Object.assign({}, defaults, params);
        if (options.map[options.start.y][options.start.x] || options.map[options.end.y][options.end.x]) {
            //当起点或终点设置在墙上
            return [];
        }
        var finded = false;
        var result = [];
        var y_length = options.map.length;
        var x_length = options.map[0].length;
        var steps: Step[][] = [];
        for (var y = y_length; y--;) {
            steps[y] = new Array(x_length).fill(0);
        }
        var _getValue = function (x: number, y: number) {
            if (options.map[y] && typeof options.map[y][x] != 'undefined') {
                return options.map[y][x];
            }
            return -1;
        };
        var _next = function (to: Step) { //判定是否可走,可走放入列表
            var value = _getValue(to.x, to.y);
            if (value < 1) {
                if (value === -1) {
                    to.x = (to.x + x_length) % x_length;
                    to.y = (to.y + y_length) % y_length;
                    to.change = true;
                }
                if (!steps[to.y][to.x]) {
                    result.push(to);
                }
            }
        };
        var _render = function (list: Step[]) {//找线路
            var new_list: Step[] = [];
            var next = function (from: Step, to: Step) {
                var value = _getValue(to.x, to.y);
                if (value < 1) {	//当前点是否可以走
                    if (value === -1) {
                        to.x = (to.x + x_length) % x_length;
                        to.y = (to.y + y_length) % y_length;
                        to.change = true;
                    }
                    if (to.x === options.end.x && to.y === options.end.y) {
                        steps[to.y][to.x] = from;
                        finded = true;
                    } else if (!steps[to.y][to.x]) {
                        steps[to.y][to.x] = from;
                        new_list.push(to);
                    }
                }
            };
            list.forEach(function (current) {
                next(current, { y: current.y + 1, x: current.x });
                next(current, { y: current.y, x: current.x + 1 });
                next(current, { y: current.y - 1, x: current.x });
                next(current, { y: current.y, x: current.x - 1 });
            });
            if (!finded && new_list.length) {
                _render(new_list);
            }
        };
        _render([options.start]);
        if (finded) {
            var current = options.end;
            if (options.type === FinderType.Path) {
                while (current.x !== options.start.x || current.y !== options.start.y) {
                    result.unshift(current);
                    current = steps[current.y][current.x];
                }
            } else if (options.type === FinderType.Next) {
                _next({ x: current.x + 1, y: current.y });
                _next({ x: current.x, y: current.y + 1 });
                _next({ x: current.x - 1, y: current.y });
                _next({ x: current.x, y: current.y - 1 });
            }
        }
        return result;
    }
}
