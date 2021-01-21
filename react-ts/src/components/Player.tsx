import { stringify } from 'querystring';
import React from 'react';
// import muxjs from 'mux.js';
import {get, fetch} from './Fetch';

declare global {
    interface Window {
        proxy: string;
    }
}

interface Props {
    avatar: string
    nick: string
    video: string
    music: string
    cover: string
}
export default class VideoPlayer extends React.Component
{
  state: Props;
  data: Props;

  constructor(props: any){
    super(props);
    this.state = this.data = {
        avatar: "",
        nick: "",
        video: "",
        music: "",
        cover: "",
    };
  }

  loadVideoInfo()
  {
    fetch(`${window.proxy}https://v.douyin.com/JYNyMo6/`)
    .then((res: Response)=>{
      console.log("return url", res.url);
      let match = /video\/(\d+)\//.exec(res.url);
      if(match !== null) this.loadVideo(match[1]);
    })
  }
  loadVideo(id: string)
  {
    let api = `${window.proxy}https://www.iesdouyin.com/web/api/v2/aweme/iteminfo/?item_ids=${id}`;
    // get("/love/iteminfo.json", {mode: "no-cors"})
    get(api)
    .then((body: any)=>{
      console.log("douyin video", body);
      this.parseItem(body);
    })
  }
  
  parseItem(body: any) {
        let item = body.item_list[0];
        let nick = item.author.nickname;
        let avatar = item.author.avatar_larger.url_list[0];
        let video = item.video.play_addr.url_list[0];
        let music = item.music.play_url.uri;
        let cover = item.video.dynamic_cover.url_list[0];
        this.data = ({avatar, nick, video, music, cover});
        this.setState(this.data);
    }

  componentDidMount()
  {
    console.log("componentDidMount", this.data, window.proxy);
    this.loadVideoInfo();
  }

  render(){
    return (
    <div className="card" title={this.state.music}>
        <div className="avatar" title={this.state.nick} style={{background: this.state.avatar}}>
        <a href={this.state.video} rel="noreferrer" target="_blank"><img src={this.state.avatar} /></a>
        </div>
        <video width="720" controls={true} autoPlay={false}>
            <source src={this.state.video} type="video/mp4" />
        </video>
    </div>
    )
  }
}
            // <source src={"https://jimbowhy.gitee.io/assets/2018-12-02-112213751m.mkv"} type="video/mp4" />
        // <audio controls={true} src={"https://jimbowhy.gitee.io/assets/if-rym.mp3"}></audio>
