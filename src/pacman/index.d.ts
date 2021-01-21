
export declare enum Orientation {
    Right,  // 0 表示右
    Down,   // 1 表示下
    Left,   // 2 表示左
    Up,     // 3 表示上
}

export declare enum ActorType {
    General,    // 0 表示普通对象(不与地图绑定)
    Player,     // 1 表示玩家控制对象
    NPC,        // 2 Non-Player Character 非玩家角色
    Enemy,      // 3 敌对势力角色
}

export declare enum ActorStatus {
    Silent, // 0 表示未激活/结束
    Normal, // 1 表示正常
    Pause,  // 2 表示暂停
    Timing, // 3 表示临时
    Error,  // 4 表示异常
}

export declare interface Coord {
    x:number
    y:number
}

export declare interface EventMap {
    [type: string]: {[event: string]: ()=>void};
}
// export declare type EventMap = { string ?: ()=>{} }
