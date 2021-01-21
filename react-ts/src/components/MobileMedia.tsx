import React from 'react';
import Media from "react-media";
/* 
Usage:
    import {MobileRender, NormalRender, Portrait, Lanscape, Orientation}} from './components/MobileMedia';

    <MobileRender><h1>MobileRender</h1></MobileRender>
    <NormalRender><h1>NormalRender</h1></NormalRender>

    <Lanscape><h3>Lanscape Render</h3></Lanscape>
    <Portrait><h3>Portrait Render</h3></Portrait>
    <Orientation><h3>Orientation Render</h3></Orientation>
    <Orientation>{
        ori => <h1>{ori}</h1>
    }</Orientation>

Ref:

    isMobile() {
        let flag = navigator.userAgent.match(/(phone|pad|pod|iPhone|iPod|ios|iPad|Android|Mobile|BlackBerry|IEMobile|MQQBrowser|JUC|Fennec|wOSBrowser|BrowserNG|WebOS|Symbian|Windows Phone)/i);
        return flag;
    }

    window.addEventListener('orientationchange', ev=>{
        console.log('onResize', window.orientation);
    }, false);
    window.addEventListener('resize', this.onResize);

    window.matchMedia("(min-width: 800px)");
    MediaQueryList {media: "(min-width: 800px)", matches: true, onchange: null}

    @media screen and (max-width: 768px) {
        .el-dialog { width: 375px; }
    }
    @media screen and (min-width: 768px) and (max-width: 992px) {
        .el-dialog { width: 500px; }
    }

    @media screen and (orientation: portrait) { }
    @media screen and (orientation: landscape) { }

 */

enum Orient { Default, Lanscape, Portrait };

function Orientation(props: {
    orient?: Orient, 
    children?: object | ((arg:Orient)=>{})}
) {
    console.log('Orientation', props, window.orientation);
    let ori = window.orientation;
    let query = props?.orient;
    let orient = Orient.Default;
    if(ori === 180 || ori === 0) orient = Orient.Portrait;
    if(ori === 90 || ori === -90) orient = Orient.Lanscape;
    let children = props.children;
    if(typeof children == 'function') return children(orient);
    if(ori === undefined && (query === undefined || query === Orient.Default)) return children;
    return (query == orient)? children:"";
}

function MobileRender(props: {query?:string | undefined, children:object}) {
    let query = props.query || "(max-width:600px)";
    return <Media query={query}>
    {(isMobile: boolean) => {
        // console.log("MobileRender isMobile", isMobile);
        return isMobile? props.children:"";
    }}
    </Media>
}
function NormalRender(props: {query?:string | undefined, children:object}) {
    let query = props.query || "(max-width:600px)";
    return <Media query={query}>
    {(isMobile: boolean) => {
        // console.log("NormalRender isMobile", isMobile);
        return isMobile? "":props.children;
    }}
    </Media>
}
function Lanscape({  children }: { children: any }) {
    return <Orientation orient={Orient.Lanscape}>{children}</Orientation>;
}
function Portrait({  children }: { children: any }) {
    return <Orientation orient={Orient.Portrait}>{children}</Orientation>;
}

export default Media;
export {MobileRender, NormalRender, Portrait, Lanscape, Orientation};

