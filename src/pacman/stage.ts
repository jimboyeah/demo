import Map from './map'
import Actor, { ActorType } from './actor'
import Game, { EventMap } from './game'

export enum StageStatus {
    Closed, // 0 表示未激活/结束
    Normal, // 1 表示正常
    Pause,  // 2 表示暂停
    Timing  // 3 玩家中招，进入临时状态
}

export default class Stage {

    params: Partial<Stage>
    settings: Partial<Stage>
    game: Game
    status: StageStatus = StageStatus.Closed
    index: number = 0
    maps: Map[] = []
    beans: Map[] = []
    audio: object[] = []
    images: object[] = []
    items: Actor[] = []
    players: Actor[] = []
    timeout: number = 0
    events: EventMap
    onInit: () => void = () => { }
    onOpen: () => void = () => { }
    onClose: () => void = () => { }
    update: () => boolean = () => true

    constructor(game: Game, params: Partial<Stage> = {}) {
        this.params = params || {};
        this.settings = {};
        this.game = game;
        this.events = game.events;
        Object.assign(this, this.settings, this.params);
    }

    createActor(options: Partial<Actor>) {
        var item = new Actor(this.game, this, options);
        if (item.location) {
            Object.assign(item, item.location.coord2position(item.coord.x, item.coord.y));
        }
        item.id = this.items.length;
        this.items.push(item);
        if (options.type === ActorType.Player) this.players.push(item);
        return item;
    }

    resetActors() {
        this.status = StageStatus.Normal;
        this.items.forEach(function (item, index) {
            Object.assign(item, item.params);
            item.control = {};
            if (item.location) {
                Object.assign(item, item.location.coord2position(item.coord.x, item.coord.y));
            }
        });
    }

    getActorsByType(type: ActorType) {
        return this.items.filter(function (item) {
            return (item.type === type);
        });
    }

    createMap(options: Partial<Map>) {
        var map = new Map(this, options);
        map.data = JSON.parse(JSON.stringify(map.params.data));
        map.imageData = undefined;
        map.id = this.maps.length;
        this.maps.push(map);
        return map;
    }

    createBeanMap(options: Partial<Map>) {
        let map = this.createMap(options);
        this.beans.push(map);
        return map;
    }

    resetMaps() {
        this.status = StageStatus.Normal;
        this.maps.forEach(function (map) {
            Object.assign(map, map.params);
            map.data = JSON.parse(JSON.stringify(map.params.data));
            map.yLength = map.data.length;
            map.xLength = map.data[0].length;
            map.imageData = undefined;
        });
    };

    reset() {
        Object.assign(this, this.params);
        this.resetActors();
        this.resetMaps();
    };
    // 绑定事件到相关舞台
    bind(eventType: string, callback: (e: Event) => void) {
        if (!this.events[eventType]) {
            this.events[eventType] = {};
            window.addEventListener(eventType, (e: Event) => {
                var key = 's' + this.game.stageIndex;
                if (this.events[eventType][key]) {
                    this.events[eventType][key](e);
                }
                e.preventDefault();
            });
        }
        this.events[eventType]['s' + this.index] = callback.bind(this);
    };
}
