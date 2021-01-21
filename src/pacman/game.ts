import Stage, { StageStatus } from './stage'
import Actor, { ActorStatus } from './actor'

declare global {
    interface Window {
        mozRequestAnimationFrame?: () => {};
        oRequestAnimationFrame?: () => {};
        msRequestAnimationFrame?: () => {};
    }
}

if (typeof Object.assign != 'function') {
    Object.assign = function (target: any) {
        'use strict';
        if (target == null) {
            throw new TypeError('Cannot convert undefined or null to object');
        }

        target = Object(target);
        for (var index = 1; index < arguments.length; index++) {
            var source = arguments[index];
            if (source != null) {
                for (var key in source) {
                    if (Object.prototype.hasOwnProperty.call(source, key)) {
                        target[key] = source[key];
                    }
                }
            }
        }
        return target;
    };
}

// requestID = window.requestAnimationFrame(callback);
window.requestAnimationFrame = (function () {
    if (!window.cancelAnimationFrame) {
        window.cancelAnimationFrame = function (id) {
            clearTimeout(id);
        };
    }
    return window.requestAnimationFrame ||
        window.webkitRequestAnimationFrame ||
        window.mozRequestAnimationFrame ||
        window.oRequestAnimationFrame ||
        window.msRequestAnimationFrame ||
        function (callback) {
            window.setTimeout(callback, 1000 / 60);
        };
})();

export interface EventMap {
    [type: string]: { [event: string]: (e: Event) => void };
}

export default class Game {

    width: number = 960
    height: number = 640
    canvas: HTMLCanvasElement
    context: CanvasRenderingContext2D
    stages: Stage[] = []
    events: EventMap = {}
    stageIndex = 0
    animationHander: number = 0

    constructor(id: string, props = {}) {
        Object.assign(this, props);
        let canvas = document.getElementById(id) as HTMLCanvasElement;
        canvas.width = this.width;
        canvas.height = this.height;
        this.canvas = canvas;
        this.context = canvas.getContext('2d') || new CanvasRenderingContext2D();
    }

    start() {
        var fs = 0;
        let context = this.context;
        var fn = () => {
            let stage = this.stages[this.stageIndex];
            context.clearRect(0, 0, this.width, this.height);
            context.fillStyle = '#000000';
            context.fillRect(0, 0, this.width, this.height);
            fs++;
            if (stage.timeout) {
                stage.timeout--;
            }
            if (stage.update() !== false) {
                stage.maps.forEach((map) => {
                    if (!(fs % map.frames)) {
                        map.times = fs / map.frames;
                    }
                    if (map.cache) {
                        if (!map.imageData) {
                            context.save();
                            map.draw(context);
                            map.imageData = context.getImageData(0, 0, this.width, this.height);
                            context.restore();
                        } else {
                            context.putImageData(map.imageData, 0, 0);
                        }
                    } else {
                        map.update();
                        map.draw(context);
                    }
                });
                stage.items.forEach((item: Actor) => {
                    if (!(fs % item.frames)) {
                        item.times = fs / item.frames;
                    }
                    if (stage.status === StageStatus.Normal && item.status !== ActorStatus.Pause) {
                        if (item.location) {
                            item.coord = item.location.position2coord(item.x, item.y);
                        }
                        if (item.timeout) {
                            item.timeout--;
                        }
                        item.update();
                    }
                    item.draw(this.context);
                });
            }
            this.animationHander = requestAnimationFrame(fn);
        };
        this.animationHander = requestAnimationFrame(fn);
    }

    stop() {
        this.animationHander && cancelAnimationFrame(this.animationHander);
    };

    getPosition(e: MouseEvent) {
        var box = this.canvas.getBoundingClientRect();
        return {
            x: e.clientX - box.left * (this.width / box.width),
            y: e.clientY - box.top * (this.height / box.height)
        };
    }

    createStage(options: Partial<Stage> = {}) {
        var stage = new Stage(this, options);
        stage.index = this.stages.length;
        this.stages.push(stage);
        stage.onInit();
        return stage;
    };

    setStage(index: number) {
        this.stages[this.stageIndex].status = StageStatus.Closed;
        this.stages[this.stageIndex].onClose();
        this.stageIndex = index;
        this.stages[index].status = StageStatus.Normal;
        this.stages[index].reset();
        this.stages[index].onOpen();
        return this.stages[index];
    };

    nextStage() {
        if (this.stageIndex < this.stages.length - 1) {
            return this.setStage(1 + this.stageIndex);
        } else {
            throw new Error('No more stage.');
        }
    };

    getStages() {
        return this.stages;
    };

    init() {
        this.stageIndex = 0;
        this.stages[0].onOpen();
        this.start();
    };

}
