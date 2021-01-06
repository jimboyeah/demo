// import React, {Component} from 'react';
import Media from "react-media";
/* 
Usage:
    import {MobileRender, NormalRender} from './components/MobileMedia';

    <MobileRender><h1>MobileRender</h1></MobileRender>
    <NormalRender><h1>NormalRender</h1></NormalRender>
 */

function Mobile({ children }: { children: any }) {
    // return Media({query: "(max-width:800px)", children});
    return <Media query="(max-width:800px)" children={children} />;
}
function MobileRender({ children }: { children: any }) {
    return <Mobile>
    {(isMobile: boolean) => {
        // console.log("MobileRender isMobile", isMobile);
        return isMobile? children:<br />;
    }}
    </Mobile>
}
function NormalRender({ children }: { children: any }) {
    return <Mobile>
    {(isMobile: boolean) => {
        // console.log("NormalRender isMobile", isMobile);
        return isMobile? <br />:children;
    }}
    </Mobile>
}
export default Mobile;
export {MobileRender, NormalRender};

