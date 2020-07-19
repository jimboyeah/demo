let hash = decodeURI(location.hash.replace("#", ""));
let ext = hash.split(".").pop();
if (ext == "jsx" || ext == "js") {
    // let a = String.fromCharCode(60);
    var js = document.createElement("script");
    js.type = "text/babel";
    js.src = hash;
    document.body.appendChild(js);
    mountNode.parentNode.appendChild(js);
}


function demo(src) {
    // location.hash = src;
    location = "./demos.html#"+src;
    console.log(location);
    setTimeout(()=>{
        location.reload();
    }, 300);
}
var olo = window.onload? window.onload:function(){};

window.onload = function(e) {
    olo(e);
    console.log("onload...")

    function makeDom(id, tag, className, text) {
        tag = tag || "div"
        id = id || Math.random().toString(16).replace("0.", "dom");
        className = className || id;
        let el = document.createElement(tag);
        el.id = id;
        el.className = className;
        if (text) el.innerHTML = text;
        return el;
    }


    let toolbox = makeDom("toolbox");
    let wrap = makeDom("toolbox-wrap", "div", "wrap");
    toolbox.appendChild(wrap);

    var demos = [
        { id: "close", text: "Close Server", class: "gtitle button", click: (e) => { location = "/close"; } },
{ text:"Arc", click: (e)=>{location = "Arc.html#Arc"; } },
{ text:"Arcpolar", click: (e)=>{location = "Arcpolar.html#Arcpolar"; } },
{ text:"Arearangeline", click: (e)=>{location = "Arearangeline.html#Arearangeline"; } },
{ text:"Bardiverge", click: (e)=>{location = "Bardiverge.html#Bardiverge"; } },
{ text:"basic", click: (e)=>{location = "basic.html#basic"; } },
{ text:"bubbleimage", click: (e)=>{location = "bubbleimage.html#bubbleimage"; } },
{ text:"bubbletext", click: (e)=>{location = "bubbletext.html#bubbletext"; } },
{ text:"Chord", click: (e)=>{location = "Chord.html#Chord"; } },
{ text:"Clusteredstacked", click: (e)=>{location = "Clusteredstacked.html#Clusteredstacked"; } },
{ text:"Columnanimated", click: (e)=>{location = "Columnanimated.html#Columnanimated"; } },
{ text:"Cutomizelegend", click: (e)=>{location = "Cutomizelegend.html#Cutomizelegend"; } },
{ text:"dashboard", click: (e)=>{location = "dashboard.html#dashboard"; } },
{ text:"Donut", click: (e)=>{location = "Donut.html#Donut"; } },
{ text:"Edges", click: (e)=>{location = "Edges.html#Edges"; } },
{ text:"GaugeTick", click: (e)=>{location = "GaugeTick.html#GaugeTick"; } },
{ text:"geom_shape", click: (e)=>{location = "geom_shape.html#geom_shape"; } },
{ text:"Heatmap", click: (e)=>{location = "Heatmap.html#Heatmap"; } },
{ text:"Histogramstacked", click: (e)=>{location = "Histogramstacked.html#Histogramstacked"; } },
{ text:"index", click: (e)=>{location = "index.html#index"; } },
{ text:"Innerlabel", click: (e)=>{location = "Innerlabel.html#Innerlabel"; } },
{ text:"intervalDodge", click: (e)=>{location = "intervalDodge.html#intervalDodge"; } },
{ text:"Labelline", click: (e)=>{location = "Labelline.html#Labelline"; } },
{ text:"Map-Beecomb", click: (e)=>{location = "Map-Beecomb.html#Map-Beecomb"; } },
{ text:"map", click: (e)=>{location = "map.html#map"; } },
{ text:"PieDemo", click: (e)=>{location = "PieDemo.html#PieDemo"; } },
{ text:"Piemultidonuts", click: (e)=>{location = "Piemultidonuts.html#Piemultidonuts"; } },
{ text:"Points", click: (e)=>{location = "Points.html#Points"; } },
{ text:"Polar", click: (e)=>{location = "Polar.html#Polar"; } },
{ text:"Polygon", click: (e)=>{location = "Polygon.html#Polygon"; } },
{ text:"RadarFlowerLine", click: (e)=>{location = "RadarFlowerLine.html#RadarFlowerLine"; } },
{ text:"ring", click: (e)=>{location = "ring.html#ring"; } },
{ text:"stack", click: (e)=>{location = "stack.html#stack"; } },
{ text:"Stacked", click: (e)=>{location = "Stacked.html#Stacked"; } },
{ text:"StackedPercentage-Area", click: (e)=>{location = "StackedPercentage-Area.html#StackedPercentage-Area"; } },
{ text:"StackedPercentage-Lines", click: (e)=>{location = "StackedPercentage-Lines.html#StackedPercentage-Lines"; } },
{ text:"StackedPercentage-Points", click: (e)=>{location = "StackedPercentage-Points.html#StackedPercentage-Points"; } },
{ text:"StackedPercentage", click: (e)=>{location = "StackedPercentage.html#StackedPercentage"; } },
{ text:"stock", click: (e)=>{location = "stock.html#stock"; } },
{ text:"Sunburst", click: (e)=>{location = "Sunburst.html#Sunburst"; } },
{ text:"Tree", click: (e)=>{location = "Tree.html#Tree"; } },
{ text:"Waterfall", click: (e)=>{location = "Waterfall.html#Waterfall"; } },
{ text:"Waterwave", click: (e)=>{location = "Waterwave.html#Waterwave"; } },
        { id: "useful", text: "Echarts Demos", class: "gtitle button", click: (e) => { location = "#Switch"; } },
    ];
    let MENUS = window.MENUS || demos;
    for (var i = MENUS.length - 1; i >= 0; i--) {
        var it = MENUS[i];
        var cls = (it.class || "button") + (hash.indexOf(it.text) >= 0 || hash == it.id ? " active" : "");
        var btn = makeDom(it.id, it.tag, cls, it.text);
        btn.onclick = it.click;
        wrap.appendChild(btn);
    }
    var btn = makeDom("exit", "a", "button exit", "Exit");
    btn.href = "/close";
    // btn.href = "javascript:alert('Bye!');location='/close';";
    wrap.appendChild(btn);

    document.body.appendChild(toolbox);
    // console.log(e,toolbox);
}