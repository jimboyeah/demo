import Stage from './stage'
import Map, { Step } from './map'
import Game, { EventMap } from './game'
// import {...} from './index.d'

export enum Orientation {
    Right,  // 0 表示右
    Down,   // 1 表示下
    Left,   // 2 表示左
    Up      // 3 表示上
}

export enum ActorType {
    General,    // 0 表示普通对象(不与地图绑定)
    Player,     // 1 表示玩家控制对象
    NPC,        // 2 Non-Player Character 非玩家角色
    Enemy       // 3 敌对势力角色
}

export enum ActorStatus {
    Silent, // 0 表示未激活/结束
    Normal, // 1 表示正常
    Pause,  // 2 表示暂停
    Timing, // 3 表示临时状态，如触发能量球
    Error,  // 4 表示异常
    Dead
}

// 地图格子坐标对象，offset 为坐标点的像素偏移
export interface Coord {
    x: number
    y: number
    offset?: number
}

export interface ControlCache {
    orientation?: number
}

export default class Actor {
    params: Partial<Actor>
    stage: Stage
    game: Game
    canvas: HTMLCanvasElement
    id: number = 0
    x: number = 0
    y: number = 0
    width: number = 20
    height: number = 20
    type = ActorType.General
    color: string = '#F00'
    status = ActorStatus.Normal
    orientation = Orientation.Right
    speed: number = 0
    events: EventMap = {}

    location: Map | undefined
    coord: Coord = { x: 0, y: 0 }
    vector: Step = { x: 0, y: 0 }
    path: Step[] = []

    frames: number = 1   //速度等级，周期计数 times 按此帧值变化一次
    times: number = 0    //内部周期计数，用于循环动画状态判断
    timeout: number = 0  //倒计时(用于过程动画状态判断)
    control: ControlCache = {} //控制缓存,到达定位点时处理
    update: () => void = () => { }
    draw: (context: CanvasRenderingContext2D) => void = () => { }

    constructor(game: Game, stage: Stage, params: Partial<Actor>) {
        this.params = params || {};
        this.canvas = game.canvas;
        this.events = game.events;
        this.stage = stage;
        this.game = game;
        Object.assign(this, this.params);
    }
}
