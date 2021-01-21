import React, { Component } from 'react'
import './style.css'
import Game from './game'
import Stage, { StageStatus } from './stage'
import Actor, { ActorStatus, ActorType, Orientation, Coord } from './actor'
import Levels, {Level} from './level'
import Map, { FinderType } from './map'
import LoopAudio from './audio'

export default class index extends Component {

    componentDidMount() {
        initGame();
    }

    render() {
        return (
            <div className="canvas">
            	<canvas id="canvas" width="700" height="480">当前浏览器不支持画布</canvas>
            </div>
        )
    }
}

enum NPC { 
    Blinky = '#F00',
    Clyde = '#F93',
    Linky = '#0CF',
    Pinky = '#F9C',
}
let _COS = [1, 0,-1, 0],
    _SIN = [0, 1, 0,-1],
    _LIFE = 5,
    _SCORE = 0;

function initGame(){
    var game = new Game('canvas');
    welcomeStage(game);
    levelsStage(game);
    finishStage(game);
    game.init();
}

function levelsStage(game:Game){
    Levels.forEach((level, index)=>{
        let stage = setupLevelStage(game, index+1);
        let map = setupStageMap(stage, level);
        setupStageBeans(stage, level);
        setupStagePlayer(stage);
        setupStageNPC(stage, 0, NPC.Blinky);
        setupStageNPC(stage, 1, NPC.Clyde);
        setupStageNPC(stage, 2, NPC.Linky);
        setupStageNPC(stage, 3, NPC.Pinky);
        setupStageUtils(stage);
        setupStageEvents(stage);
        levelUpStage(game);
    });
}

function setupStageEvents(stage:Stage):void{
    let player:Actor = stage.getActorsByType(ActorType.Player)[0];
    return stage.bind('keydown', function(this:Stage, e){
        switch((e as KeyboardEvent).key){
            case 'Enter':
            case ' ':
            if(this.status === StageStatus.Pause) {
                this.status = StageStatus.Normal;
                LoopAudio.perform('BGM');
            }else{
                this.status = StageStatus.Pause;
                LoopAudio.muteAll();
            }
            break;
            case 'ArrowRight':
            case 'd':
            player.control = {orientation: Orientation.Right};
            LoopAudio.perform('Hit3', false);
            break;
            case 'ArrowDown':
            case 's':
            player.control = {orientation: Orientation.Down};
            LoopAudio.perform('Hit3', false);
            break;
            case 'ArrowLeft':
            case 'a':
            player.control = {orientation: Orientation.Left};
            LoopAudio.perform('Hit3', false);
            break;
            case 'ArrowUp':
            case 'w':
            player.control = {orientation: Orientation.Up};
            LoopAudio.perform('Hit3', false);
            break;
        }
    });
}

function setupStageUtils(stage:Stage):Actor[]{
    return [
    // Scores
    stage.createActor({
        x:690,
        y:80,
        draw:function(this:Actor, context:CanvasRenderingContext2D){
            context.font = 'bold 26px Helvetica';
            context.textAlign = 'left';
            context.textBaseline = 'bottom';
            context.fillStyle = '#C33';
            context.fillText('SCORE',this.x,this.y);
            context.font = '26px Helvetica';
            context.textAlign = 'left';
            context.textBaseline = 'top';
            context.fillStyle = '#FFF';
            context.fillText(_SCORE+'', this.x+12,this.y);
            context.font = 'bold 26px Helvetica';
            context.textAlign = 'left';
            context.textBaseline = 'bottom';
            context.fillStyle = '#C33';
            context.fillText('LEVEL',this.x,this.y+72);
            context.font = '26px Helvetica';
            context.textAlign = 'left';
            context.textBaseline = 'top';
            context.fillStyle = '#FFF';
            context.fillText(stage.index+'',this.x+12,this.y+72);
        }
    }),
    // Staus text
    stage.createActor({
        x:690,
        y:285,
        frames:25,
        draw:function(this:Actor, context:CanvasRenderingContext2D){
            if(stage.status === StageStatus.Pause && this.times%2){
                context.font = '24px Helvetica';
                context.textAlign = 'left';
                context.textBaseline = 'middle';
                context.fillStyle = '#FFF';
                context.fillText('PAUSE', this.x, this.y);
            }
        }
    }),
    // Lifebar
    stage.createActor({
        x:705,
        y:510,
        width:30,
        height:30,
        draw:function(this:Actor, context:CanvasRenderingContext2D){
            var max = Math.min(_LIFE-1,5);
            for(var i=0;i<max; i++){
                var x = this.x+40*i, y = this.y;
                context.fillStyle = '#FFE600';
                context.beginPath();
                context.arc(x, y,this.width/2,.15*Math.PI,-.15*Math.PI,false);
                context.lineTo(x, y);
                context.closePath();
                context.fill();
                context.fillStyle = '#000';
                context.beginPath();
                context.arc(x+2, y-7, 3, 0, 2*Math.PI, false);
                context.font = 'bold 12px Helvetica';
                context.fillText('O', x - 4, y - 13);
                context.closePath();
                context.fill();
            }
            context.font = '26px Helvetica';
            context.textAlign = 'left';
            context.textBaseline = 'middle';
            context.fillStyle = '#FFF';
            context.fillText('X '+(_LIFE-1),this.x-15,this.y+30);
        }
    })];
}

function setupStageNPC(stage:Stage, index:number, npcColor: NPC):Actor{
    return stage.createActor({
        width:30,
        height:30,
        orientation:3,
        color: npcColor,
        location: stage.maps[0],
        coord:{x:12 + index, y:14},
        vector:{x:12 + index, y:14},
        type:2,
        frames:10,
        speed:1,
        timeout:Math.floor(Math.random()*120),
        update:function(this:Actor){
            let new_map:number[][];
            let map = stage.maps[0];
            let items = stage.getActorsByType(ActorType.NPC);
            let player = stage.getActorsByType(ActorType.Player)[0];
            if(this.status === ActorStatus.Timing && !this.timeout){
                this.status = ActorStatus.Normal;
            }
            
            if(!this.coord.offset){
                if(this.status===ActorStatus.Normal){
                    if(!this.timeout){
                        new_map = JSON.parse(JSON.stringify(map.data).replace(/2/g, '0'));
                        // 正常状态的 NPC 不可穿透
                        items.forEach((item)=>{
                            if(item.id !== this.id && item.status === ActorStatus.Normal){
                                new_map[item.coord.y][item.coord.x]=1;
                            }
                        });
                        this.path = map.finder({
                            map: new_map,
                            start: this.coord,
                            end: player.coord,
                            type: FinderType.Path,
                        });
                        if(this.path.length){
                            this.vector = this.path[0];
                        }
                    }
                }else if(this.status===ActorStatus.Timing){
                    new_map = JSON.parse(JSON.stringify(map.data).replace(/2/g, '0'));
                    items.forEach((item)=>{
                        if(item.id!==this.id){
                            new_map[item.coord.y][item.coord.x]=1;
                        }
                    });
                    this.path = map.finder({
                        map:new_map,
                        start:player.coord,
                        end:this.coord,
                        type: FinderType.Next
                    });
                    if(this.path.length){
                        this.vector = this.path[Math.floor(Math.random()*this.path.length)];
                    }
                }else if(this.status === ActorStatus.Error){
                    new_map = JSON.parse(JSON.stringify(map.data).replace(/2/g, '0'));
                    this.path = map.finder({
                        map:new_map,
                        start:this.coord,
                        end: this.params.coord||{} as Coord,
                        type: FinderType.Path,
                    });
                    if(this.path.length){
                        this.vector = this.path[0];
                    }else{
                        this.status = ActorStatus.Normal;
                    }
                }
                
                if(this.vector.change){
                    this.coord.x = this.vector.x;
                    this.coord.y = this.vector.y;
                    var pos = map.coord2position(this.coord.x,this.coord.y);
                    this.x = pos.x;
                    this.y = pos.y;
                }
                
                if(this.vector.x>this.coord.x){
                    this.orientation = Orientation.Right;
                }else if(this.vector.x<this.coord.x){
                    this.orientation = Orientation.Left;
                }else if(this.vector.y>this.coord.y){
                    this.orientation = Orientation.Down;
                }else if(this.vector.y<this.coord.y){
                    this.orientation = Orientation.Up;
                }
            }
            this.x += this.speed*_COS[this.orientation];
            this.y += this.speed*_SIN[this.orientation];
        },
        draw:function(this:Actor, context){
            var isSick = false;
            if(this.status===ActorStatus.Timing){
                isSick = this.timeout>80 || this.times%2? true:false;
            }
            if(this.status!==ActorStatus.Error){
                context.fillStyle = isSick?'#8A8A8A':this.color;
                context.beginPath();
                context.arc(this.x,this.y,this.width*.5,0,Math.PI,true);
                switch(this.times%2){
                    case 0:
                    context.lineTo(this.x-this.width*.5,this.y+this.height*.4);
                    context.quadraticCurveTo(this.x-this.width*.4,this.y+this.height*.5,this.x-this.width*.2,this.y+this.height*.3);
                    context.quadraticCurveTo(this.x,this.y+this.height*.5,this.x+this.width*.2,this.y+this.height*.3);
                    context.quadraticCurveTo(this.x+this.width*.4,this.y+this.height*.5,this.x+this.width*.5,this.y+this.height*.4);
                    break;
                    case 1:
                    context.lineTo(this.x-this.width*.5,this.y+this.height*.3);
                    context.quadraticCurveTo(this.x-this.width*.25,this.y+this.height*.5,this.x,this.y+this.height*.3);
                    context.quadraticCurveTo(this.x+this.width*.25,this.y+this.height*.5,this.x+this.width*.5,this.y+this.height*.3);
                    break;
                }
                context.fill();
                context.closePath();
            }
            context.fillStyle = '#FFF';
            if(isSick){
                context.beginPath();
                context.arc(this.x-this.width*.15,this.y-this.height*.21,this.width*.08,0,2*Math.PI,false);
                context.arc(this.x+this.width*.15,this.y-this.height*.21,this.width*.08,0,2*Math.PI,false);
                context.fill();
                context.closePath();
            }else{
                context.beginPath();
                context.arc(this.x-this.width*.15,this.y-this.height*.21,this.width*.12,0,2*Math.PI,false);
                context.arc(this.x+this.width*.15,this.y-this.height*.21,this.width*.12,0,2*Math.PI,false);
                context.fill();
                context.closePath();
                context.fillStyle = '#000';
                context.beginPath();
                context.arc(this.x-this.width*(.15-.04*_COS[this.orientation]),this.y-this.height*(.21-.04*_SIN[this.orientation]),this.width*.07,0,2*Math.PI,false);
                context.arc(this.x+this.width*(.15+.04*_COS[this.orientation]),this.y-this.height*(.21-.04*_SIN[this.orientation]),this.width*.07,0,2*Math.PI,false);
                context.fill();
                context.closePath();
            }
        }
    });
}

function setupStagePlayer(stage:Stage):Actor{
    return stage.createActor({
        width:30,
        height:30,
        type:1,
        location: stage.maps[0],
        coord:{x:13.5, y:23},
        orientation:2,
        speed:2.5,
        frames:10,
        update:function(this:Actor){
            let map = this.location;
            let coord = this.coord;
            let beans = stage.beans[0];
            let bonus = beans.rawData.bonus;
            let items = stage.getActorsByType(ActorType.NPC);
            
            if(!coord.offset && map){
                if(this.control.orientation !== undefined){
                    if(!map.get(coord.x+_COS[this.control.orientation],coord.y+_SIN[this.control.orientation])){
                        this.orientation = this.control.orientation;
                    }
                }
                let terrain = map.get(coord.x+_COS[this.orientation], coord.y+_SIN[this.orientation]);
            
                if(terrain === 0){
                    this.x += this.speed*_COS[this.orientation];
                    this.y += this.speed*_SIN[this.orientation];
                }else if(terrain<0){
                    this.x -= map.size*(map.xLength-1)*_COS[this.orientation];
                    this.y -= map.size*(map.yLength-1)*_SIN[this.orientation];
                }
            }else{
                if(!beans.get(this.coord.x, this.coord.y)){
                    _SCORE++;
                    LoopAudio.perform('Hit2', false);
                    beans.set(this.coord.x,this.coord.y, 1);
                    if(bonus[this.coord.x+','+this.coord.y]){
                        LoopAudio.perform('PowerUp', false);
                        items.forEach(function(item){
                            if(item.status === ActorStatus.Normal){
                                item.timeout = 450;
                                item.status = ActorStatus.Timing;
                            }
                        });
                    }
                }
                this.x += this.speed*_COS[this.orientation];
                this.y += this.speed*_SIN[this.orientation];
            }
        },
        draw:function(this:Actor, context){
            let x = this.x, y = this.y, half = this.width/2;
            if(stage.status !== StageStatus.Timing){
                context.fillStyle = '#FFE600';
                context.beginPath();
                if(this.times%2){
                    context.arc(x, y, half,(.5*this.orientation+.20)*Math.PI,(.5*this.orientation-.20)*Math.PI,false);
                }else{
                    context.arc(x, y, half,(.5*this.orientation+.01)*Math.PI,(.5*this.orientation-.01)*Math.PI,false);
                }
                context.lineTo(x, y);
                context.closePath();
                context.fill();
    
                let dx = _COS[this.orientation], dxa = dx<0? -dx:dx;
                let dy = _SIN[this.orientation];
    
                context.fillStyle = '#fff';
                context.beginPath();
                context.arc(this.x+this.width*(.3*dy + .13*dx),this.y-this.height*(0.3*dxa-.2*dy),this.width*.14,0,2*Math.PI,false);
                context.closePath();
                context.fill();
                context.fillStyle = '#000';
                context.beginPath();
                context.arc(this.x+this.width*(.27*dy + .08*dx),this.y-this.height*(0.27*dxa-.2*dy),this.width*.08,0,2*Math.PI,false);
                context.closePath();
                context.fill();
            }else if(stage.status === StageStatus.Timing && stage.timeout){	// ActorStatus.Dead
                context.fillStyle = '#FFE600';
                context.beginPath();
                context.arc(x, y, half,(.5*this.orientation+1-.02*stage.timeout)*Math.PI,(.5*this.orientation-1+.02*stage.timeout)*Math.PI,false);
                context.lineTo(x, y);
                context.closePath();
                context.fill();
            }

        }
    });
}

function setupLevelStage(game:Game, index:number):Stage{
    return game.createStage({
        index: index,
        onOpen:()=>{
            LoopAudio.perform('Dings', false, (e)=>{
                LoopAudio.perform('BGM');
            });
        },
        onClose: ()=>{
            LoopAudio.mute('BGM');
            LoopAudio.mute('BGM1');
        },
        update:function(this:Stage){
            var stage = this;
            let beans = this.beans[0];
            if(stage.status === StageStatus.Normal){
                let map = this.maps[0];
                let player:Actor = stage.getActorsByType(ActorType.Player)[0];
                let items = stage.getActorsByType(ActorType.NPC);
                items.forEach(function(item){
                    if(map && !map.get(item.coord.x,item.coord.y) && !map.get(player.coord.x, player.coord.y)){
                        var dx = item.x-player.x;
                        var dy = item.y-player.y;
                        if(dx*dx+dy*dy<750 && item.status !== ActorStatus.Error){
                            if(item.status === ActorStatus.Timing){
                                item.status = ActorStatus.Error;
                                _SCORE += 10;
                                LoopAudio.perform('Annihilate', false);
                            }else{
                                // player.status = ActorStatus.Dead;
                                LoopAudio.perform('Dead', false);
                                LoopAudio.mute('BGM');
                                LoopAudio.mute('BGM1');
                                stage.status = StageStatus.Timing;
                                stage.timeout = 30;
                            }
                        }
                    }
                });
                if(JSON.stringify(beans.data).indexOf('0')<0){
                    game.nextStage();
                }
            }else if(stage.status === StageStatus.Timing){
                if(!stage.timeout){
                    _LIFE--;
                    if(_LIFE){
                        // game.nextStage();
                        LoopAudio.perform('BGM1');
                        stage.resetActors();
                    }else{
                        var stages = game.getStages();
                        game.setStage(stages.length-1);
                        return false;
                    }
                }
            }
            return true;
        }
    });
}

function setupStageMap(stage:Stage, level:Level):Map{
    return stage.createMap({
        x:60,
        y:10,
        data: level.map,
        cache:true,
        draw:function(this:Map, context){
            context.lineWidth = 2;
            for(var j=0; j<this.yLength; j++){
                for(var i=0; i<this.xLength; i++){
                    var value = this.get(i,j);
                    if(value){
                        var code = [0,0,0,0];
                        if(this.get(i+1,j)&&!(this.get(i+1,j-1)&&this.get(i+1,j+1)&&this.get(i,j-1)&&this.get(i,j+1))){
                            code[0]=1;
                        }
                        if(this.get(i,j+1)&&!(this.get(i-1,j+1)&&this.get(i+1,j+1)&&this.get(i-1,j)&&this.get(i+1,j))){
                            code[1]=1;
                        }
                        if(this.get(i-1,j)&&!(this.get(i-1,j-1)&&this.get(i-1,j+1)&&this.get(i,j-1)&&this.get(i,j+1))){
                            code[2]=1;
                        }
                        if(this.get(i,j-1)&&!(this.get(i-1,j-1)&&this.get(i+1,j-1)&&this.get(i-1,j)&&this.get(i+1,j))){
                            code[3]=1;
                        }
                        if(code.indexOf(1)>-1){
                            context.strokeStyle = value===2?"#FFF": level.wallColor;
                            var pos = this.coord2position(i,j);
                            let radius = this.size/2;
                            switch(code.join('')){
                                case '1100': // LeftTopCorner
                                    context.beginPath();
                                    context.arc(pos.x+radius, pos.y+radius, radius, Math.PI, 1.5*Math.PI, false);
                                    context.stroke();
                                    context.closePath();
                                    break;
                                case '0110': // RightTopCorner
                                    context.beginPath();
                                    context.arc(pos.x-radius, pos.y+radius, radius, 1.5*Math.PI, 2*Math.PI, false);
                                    context.stroke();
                                    context.closePath();
                                    break;
                                case '0011': // RightBottomCorner
                                    context.beginPath();
                                    context.arc(pos.x-radius, pos.y-radius, radius, 0, .5*Math.PI, false);
                                    context.stroke();
                                    context.closePath();
                                    break;
                                case '1001': // LeftBottomCorner
                                    context.beginPath();
                                    context.arc(pos.x+radius, pos.y-radius, radius, .5*Math.PI, 1*Math.PI, false);
                                    context.stroke();
                                    context.closePath();
                                    break;
                                default:
                                    var dist = radius; 
                                    code.forEach(function(v, index){
                                        if(v){
                                            context.beginPath();
                                            context.moveTo(pos.x, pos.y);
                                            context.lineTo(pos.x-_COS[index]*dist, pos.y-_SIN[index]*dist);
                                            context.stroke();
                                            context.closePath();							
                                        }
                                    });
                            }
                        }
                    }
                }
            }
        }
    });
}

function setupStageBeans(stage:Stage, level:Level):Map{
    return stage.createBeanMap({
        x:60,
        y:10,
        data: level.map,
        rawData: level,
        frames:8,
        update: function(this:Map){
            // console.log(this.x, this.y);
        },
        draw:function(this:Map, context){
            for(var j=0; j<this.yLength; j++){
                for(var i=0; i<this.xLength; i++){
                    if(!this.get(i,j)){
                        var pos = this.coord2position(i,j);
                        context.fillStyle = "#65AF6C";
                        if(level.bonus[i+','+j]){
                            context.beginPath();
                            context.arc(pos.x, pos.y,3+this.times%2, 0, 2*Math.PI,true);
                            context.fill();
                            context.closePath();
                        }else{
                            context.fillRect(pos.x-2,pos.y-2,4,4);
                        }
                    }
                }
            }
        }
    });
}

function welcomeStage(game:Game) {
    let stage = game.createStage({onOpen:()=>{
        LoopAudio.perform('Welcome', false);
    }});
    stage.createActor({
        x:game.width/2,
        y:game.height*.45,
        width:100,
        height:100,
        frames:3,
        draw:function(this:Actor, context:CanvasRenderingContext2D){
            var t = Math.abs(5-this.times%10);
            context.fillStyle = '#FFE600';
            context.beginPath();
            context.arc(this.x, this.y, this.width/2, t*.04*Math.PI, (2-t*.04)*Math.PI, false);
            context.lineTo(this.x, this.y);
            context.closePath();
            context.fill();
            
            context.fillStyle = '#fff';
            context.beginPath();
            context.arc(this.x+this.width*.15,this.y-this.height*.31,this.width*.10,0,2*Math.PI,false);
            context.fill();
            context.closePath();
            context.fillStyle = '#000';
            context.beginPath();
            context.arc(this.x+this.width*(.14),this.y-this.height*(.29),this.width*.07,0,2*Math.PI,false);
            context.fill();
            context.closePath();

            // context.fillStyle = '#000';
            // context.beginPath();
            // context.arc(this.x+5, this.y-27, 7, 0, 2*Math.PI, false);
            // context.font = 'bold 36px Helvetica';
            // context.fillText('O', this.x + 3, this.y - 28);
            // context.closePath();
            // context.fill();
        }
    });
    stage.createActor({
        x:game.width/2,
        y:game.height*.6,
        draw:function(this:Actor, context:CanvasRenderingContext2D){
            context.font = 'bold 42px Helvetica';
            context.textAlign = 'center';
            context.textBaseline = 'middle';
            context.fillStyle = '#FFF';
            context.fillText('Pac-Man', this.x, this.y);
        }
    });
    stage.createActor({
        x:game.width/2,
        y:game.height*.7,
        draw:function(this:Actor, context:CanvasRenderingContext2D){
            context.font = '14px Helvetica';
            context.textAlign = 'center';
            context.textBaseline = 'middle';
            context.fillStyle = '#AAA';
            context.fillText('Press [SPACE] to continue...', this.x, this.y);
        }
    });
    stage.bind('keydown',(e)=>{
        console.log(e, (e as KeyboardEvent).key);
        switch((e as KeyboardEvent).key){
            case '1': LoopAudio.perform('BGM1'); break;
            case '2': LoopAudio.perform('BGM2'); break;
            case '3': LoopAudio.perform('BGM3'); break;
            case '4': LoopAudio.perform('BGM'); break;
            case '5': LoopAudio.perform('Kill', false); break;
            case '6': LoopAudio.perform('Power', false); break;
            case '7': LoopAudio.perform('Welcome', false); break;
            case '8': LoopAudio.perform('LevelUp', false); break;
            case '9': LoopAudio.perform('LevelUp2', false); break;
            case '!': LoopAudio.perform('Annihilate', false); break;
            case '@': LoopAudio.perform('Dead', false); break;
            case '#': LoopAudio.perform('Hit1', false); break;
            case '$': LoopAudio.perform('Hit2', false); break;
            case '%': LoopAudio.perform('Hit3', false); break;
            case '^': LoopAudio.perform('PowerUp', false); break;
            case '&': LoopAudio.perform('Dings', false); break;
            case '*': LoopAudio.perform('Waves', false); break;
            case 'm':
            LoopAudio.muteAll();
            break;
            case 'Enter':
            case ' ':
            LoopAudio.muteAll();
            game.setStage(1);
            break;
        }
    });
}

function levelUpStage(game:Game){
    let stage = game.createStage({onOpen:()=>{
        LoopAudio.perform('LevelUp', false);
    }});
    stage.createActor({
		x:game.width/2,
		y:game.height*.35,
		draw:function(this:Actor, context){
			context.fillStyle = '#FA6';
			context.font = 'bold 48px Helvetica';
			context.textAlign = 'center';
			context.textBaseline = 'middle';
			context.fillText('Level up!', this.x, this.y);
		}
	});
	stage.createActor({
        x:game.width/2,
		y:game.height*.5,
		draw:function(this:Actor, context){
            context.fillStyle = '#FFF';
			context.font = '20px Helvetica';
			context.textAlign = 'center';
			context.textBaseline = 'middle';
			context.fillText('TOTAL SCORE: '+_SCORE, this.x, this.y);
            context.fillText('Press [SPACE] to continue...', this.x, this.y + 48);
		}
	});
	stage.bind('keydown',function(e){
		switch((e as KeyboardEvent).key){
			case 'Enter':
			case ' ':
            game.nextStage();
			break;
		}
	});
}

function finishStage(game:Game){
    let stage = game.createStage({onOpen:()=>{
        LoopAudio.perform('LevelUp2', false);
    }});
    stage.createActor({
		x:game.width/2,
		y:game.height*.35,
		draw:function(this:Actor, context){
			context.fillStyle = '#FFF';
			context.font = 'bold 48px Helvetica';
			context.textAlign = 'center';
			context.textBaseline = 'middle';
			context.fillText(_LIFE?'YOU WIN!':'GAME OVER',this.x,this.y);
		}
	});
	stage.createActor({
		x:game.width/2,
		y:game.height*.5,
		draw:function(this:Actor, context){
			context.fillStyle = '#FFF';
			context.font = '20px Helvetica';
			context.textAlign = 'center';
			context.textBaseline = 'middle';
			context.fillText('FINAL SCORE: '+(_SCORE+50*Math.max(_LIFE-1,0)),this.x,this.y);
		}
	});
	stage.bind('keydown',function(e){
		switch((e as KeyboardEvent).key){
			case 'Enter':
			case ' ':
			_SCORE = 0;
			_LIFE = 5;
			game.setStage(0);
			break;
		}
	});
}