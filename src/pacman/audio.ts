import Stage from './stage'
import Map, { Step } from './map'
import Game, { EventMap } from './game'

const Loop = require('./pacman10_looped.mp3')
const LoopRegular = require('./pacman10_regular.mp3')

export enum LoopEvent {
    BGM1,
    BGM2,
    BGM3,
    BGM,
    Kill,
    Power,
    Welcome,
    LevelUp,
    LevelUp2,
    Annihilate,
    Dead,
    Hit1,
    Hit2,
    Hit3,
    PowerUp,
    Dings,
    Waves
}
/**
 * This is equivalent to:
 * type LoopName = 'BGM' | 'Kill' | 'Power' ... ;
 */
export type LoopName = keyof typeof LoopEvent;

export interface Loop {
    start: number
    end: number
}

export interface LoopConfig {
    src: string
    loops: { [event in LoopName]?: { start: number, end: number } }
}

class LoopAudio {

    params: LoopConfig[]
    loops: { [name in LoopName]?: Loop } = {}
    audios: { [name: string]: HTMLAudioElement } = {}
    sentinel: { [name: string]: number } = {}
    notify: { [name in LoopName]?: (event: string) => void } = {}

    constructor(params: LoopConfig[]) {
        this.params = params;
        for (let idx in params) {
            let config = params[idx];
            for (let event in config.loops) {
                let name = event as LoopName;
                this.loops[name] = config.loops[name];
                let audio = new Audio(config.src);
                audio.id = event;
                audio.src = config.src;
                audio.autoplay = false;
                this.audios[event] = audio;
                audio.addEventListener("playing", (e) => {
                    // console.log(e);
                });
                audio.addEventListener("pause", (e) => {
                    // console.log(e);
                });
                audio.addEventListener("seeking", (e) => {
                    // console.log(e);
                });
                audio.addEventListener("progress", (e) => {
                    // console.log(e);
                });
            }
        }
    }

    muteAll() {
        for (let name in this.audios) {
            this.audios[name].pause();
            this.mute(name as LoopName);
        }
    }
    mute(name: LoopName) {
        let audio = this.audios[name]
        audio.pause()
        if (this.sentinel[name]) clearTimeout(this.sentinel[name])
    }

    tick(name: LoopName, audio: HTMLAudioElement, loop: boolean) {
        audio.pause();
        // console.log(name, audio, this);
        if (loop) {
            this.perform(name);
        } else {
            let notify = this.notify[name];
            if (notify) notify("stop");
            delete this.notify[name];
        }
    }

    perform(name: LoopName, loop: boolean = true, onStop = (e: string) => { }) {
        let audio = this.audios[name];
        let lp = this.loops[name];
        // console.log("LoopName", name, lp);
        this.notify[name] = onStop;
        if (lp) {
            let elapse = lp.end - lp.start;
            audio.currentTime = lp.start / 1000;
            if (this.sentinel[name]) clearTimeout(this.sentinel[name]);
            this.sentinel[name] = setTimeout(this.tick.bind(this), elapse, name, audio, loop);
        }
        audio.play();
    }

}

export default new LoopAudio([{
    src: Loop.default,
    loops: {
        BGM1: { start: 0, end: 440 },
        BGM2: { start: 1400, end: 1800 },
        BGM3: { start: 2730, end: 3070 },
        BGM: { start: 4030, end: 4330 },
        Kill: { start: 5300, end: 5600 },
        Power: { start: 6560, end: 7130 },
        Welcome: { start: 8100, end: 13350 + 300 },
        LevelUp: { start: 14350, end: 18560 },
        LevelUp2: { start: 19500, end: 23745 },
    }
}, {
    src: LoopRegular.default,
    loops: {
        Annihilate: { start: 70, end: 1230 },
        Dead: { start: 2580, end: 4120 },
        Hit1: { start: 5170, end: 5330 + 300 },
        Hit2: { start: 6300, end: 6470 + 300 },
        Hit3: { start: 7430, end: 7660 + 300 },
        PowerUp: { start: 8660, end: 9240 },
        Dings: { start: 10250, end: 12300 },
        Waves: { start: 13300, end: 13790 },
    }
}
]);
