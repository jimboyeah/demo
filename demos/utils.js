function load(url){
    if(url) {
        location = url;
        console.log(url+", "+location)
        setTimeout(()=>location.reload(), 100);
    }
    let hash = decodeURI(location.hash.replace("#", ""));
    let ext = hash.split(".").pop();
    if (ext == "jsx" || ext == "js") {
        // let a = String.fromCharCode(60);
        var js = document.createElement("script");
        js.type = "text/"+{"jsx":"babel", "js":"javascript"}[ext];
        js.src = hash;
        var res = document.body.appendChild(js)
        // mountNode.parentNode.appendChild(js);
    }
}

window.onload = function(e) {
    load()
    function makeDom(id, tag, className, text) {
        tag = tag || "div"
        id = id || text; // Math.random().toString(16).replace("0.", "dom");
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
{ text: "Air Quality - Baidu Map", click: (e)=>{ location="Air Quality - Baidu Map.html#Air Quality - Baidu Map"; } },
{ text: "areaStyle", click: (e)=>{ location="areaStyle.html#areaStyle"; } },
{ text: "bar-animation-delay", click: (e)=>{ location="bar-animation-delay.html#bar-animation-delay"; } },
{ text: "bar-negative", click: (e)=>{ location="bar-negative.html#bar-negative"; } },
{ text: "bar-negative2", click: (e)=>{ location="bar-negative2.html#bar-negative2"; } },
{ text: "bar-rich-text", click: (e)=>{ location="bar-rich-text.html#bar-rich-text"; } },
{ text: "bar3d-punch-card", click: (e)=>{ location="bar3d-punch-card.html#bar3d-punch-card"; } },
{ text: "Bar3d", click: (e)=>{ location="Bar3d.html#Bar3d"; } },
{ text: "Bubble Chart", click: (e)=>{ location="Bubble Chart.html#Bubble Chart"; } },
{ text: "dataset-link", click: (e)=>{ location="dataset-link.html#dataset-link"; } },
{ text: "demo", click: (e)=>{ location="demo.html#demo"; } },
{ text: "Donut", click: (e)=>{ location="Donut.html#Donut"; } },
{ text: "EffectScartterBMap", click: (e)=>{ location="EffectScartterBMap.html#EffectScartterBMap"; } },
{ text: "Events", click: (e)=>{ location="Events.html#Events"; } },
{ text: "global-wind-visualization", click: (e)=>{ location="global-wind-visualization.html#global-wind-visualization"; } },
{ text: "graphgl-large-internet", click: (e)=>{ location="graphgl-large-internet.html#graphgl-large-internet"; } },
{ text: "grid-multiple", click: (e)=>{ location="grid-multiple.html#grid-multiple"; } },
{ text: "demos", click: (e)=>{ location="demos.html#demos"; } },
{ text: "line-easing", click: (e)=>{ location="line-easing.html#line-easing"; } },
{ text: "map-polygon", click: (e)=>{ location="map-polygon.html#map-polygon"; } },
{ text: "Map", click: (e)=>{ location="Map.html#Map"; } },
{ text: "Migratory", click: (e)=>{ location="Migratory.html#Migratory"; } },
{ text: "mix-zoom-on-value", click: (e)=>{ location="mix-zoom-on-value.html#mix-zoom-on-value"; } },
{ text: "multiple-x-axis", click: (e)=>{ location="multiple-x-axis.html#multiple-x-axis"; } },
{ text: "multiple-y-axis", click: (e)=>{ location="multiple-y-axis.html#multiple-y-axis"; } },
{ text: "Nested Pies", click: (e)=>{ location="Nested Pies.html#Nested Pies"; } },
{ text: "Nightingale", click: (e)=>{ location="Nightingale.html#Nightingale"; } },
{ text: "Pie with Scrollable Legend", click: (e)=>{ location="Pie with Scrollable Legend.html#Pie with Scrollable Legend"; } },
{ text: "Pie", click: (e)=>{ location="Pie.html#Pie"; } },
{ text: "Pies", click: (e)=>{ location="Pies.html#Pies"; } },
{ text: "renderItem", click: (e)=>{ location="renderItem.html#renderItem"; } },
{ text: "scatter-anscombe-quartet", click: (e)=>{ location="scatter-anscombe-quartet.html#scatter-anscombe-quartet"; } },
{ text: "Velocity of Christmas Reindeers", click: (e)=>{ location="Velocity of Christmas Reindeers.html#Velocity of Christmas Reindeers"; } },
{ text: "watermark", click: (e)=>{ location="watermark.html#watermark"; } },
        { id: "useful", text: "Echarts Demos", class: "gtitle button", click: (e) => { location = "#Switch"; } },


        { id: "useful", text: "散点图 Scatter", class: "gtitle button" },

        { id: "useful", text: "GL 关系图 Graph GL", class: "gtitle button" },

        { id: "useful", text: "GL 矢量场图 Flow GL", class: "gtitle button" },

        { id: "useful", text: "GL 路径图 Lines GL", class: "gtitle button" },

        { id: "useful", text: "GL 散点图 Scatter GL", class: "gtitle button" },

        { id: "useful", text: "3D 折线图 3D Line", class: "gtitle button" },

        { id: "useful", text: "3D 路径图 3D Lines", class: "gtitle button" },

        { id: "useful", text: "3D 地图 3D Map", class: "gtitle button" },

        { id: "useful", text: "3D 曲面 3D Surface", class: "gtitle button" },

        { id: "useful", text: "3D 散点图 3D Scatter", class: "gtitle button" },

        { id: "useful", text: "3D 柱状图 3D Bar", class: "gtitle button" },

{ text: "ref", click: (e)=>{ load("demos.html#ref"); } },
        { id: "useful", text: "3D 地球 3D Globe", class: "gtitle button" },

{ text: "pie-rich-text.js", click: (e)=>{ load("demos.html#pie-rich-text.js"); } },
{ text: "pie-nest.js", click: (e)=>{ load("demos.html#pie-nest.js"); } },
{ text: "bar-rich-text.js", click: (e)=>{ load("demos.html#bar-rich-text.js"); } },
        { id: "useful", text: "富文本 Rich Text", class: "gtitle button" },

{ text: "line-draggable.js", click: (e)=>{ load("demos.html#line-draggable.js"); } },
{ text: "custom-gantt-flight.js", click: (e)=>{ load("demos.html#custom-gantt-flight.js"); } },
        { id: "useful", text: "拖拽 Drag", class: "gtitle button" },

        { id: "useful", text: "数据区域缩放 DataZoom", class: "gtitle button" },

{ text: "dataset-simple0.js", click: (e)=>{ load("demos.html#dataset-simple0.js"); } },
{ text: "dataset-simple1.js", click: (e)=>{ load("demos.html#dataset-simple1.js"); } },
{ text: "dataset-default.js", click: (e)=>{ load("demos.html#dataset-default.js"); } },
{ text: "dataset-encode0.js", click: (e)=>{ load("demos.html#dataset-encode0.js"); } },
{ text: "dataset-series-layout-by.js", click: (e)=>{ load("demos.html#dataset-series-layout-by.js"); } },
{ text: "dataset-encode1.js", click: (e)=>{ load("demos.html#dataset-encode1.js"); } },
{ text: "dataset-link.js", click: (e)=>{ load("demos.html#dataset-link.js"); } },
        { id: "useful", text: "数据集 Dataset", class: "gtitle button" },

        { id: "useful", text: "自定义系列 Custom", class: "gtitle button" },

        { id: "useful", text: "日历坐标系 Calendar", class: "gtitle button" },

        { id: "useful", text: "主题河流图 ThemeRiver", class: "gtitle button" },

        { id: "useful", text: "象形柱图 PictorialBar", class: "gtitle button" },

        { id: "useful", text: "漏斗图 Funnel", class: "gtitle button" },

        { id: "useful", text: "桑基图 Sankey", class: "gtitle button" },

        { id: "useful", text: "平行坐标系 Parallel", class: "gtitle button" },

        { id: "useful", text: "旭日图 Sunburst", class: "gtitle button" },

        { id: "useful", text: "矩形树图 Treemap", class: "gtitle button" },

{ text: "tree-basic.js", click: (e)=>{ load("demos.html#tree-basic.js"); } },
{ text: "tree-legend.js", click: (e)=>{ load("demos.html#tree-legend.js"); } },
{ text: "tree-orient-right-left.js", click: (e)=>{ load("demos.html#tree-orient-right-left.js"); } },
{ text: "tree-radial.js", click: (e)=>{ load("demos.html#tree-radial.js"); } },
{ text: "tree-vertical.js", click: (e)=>{ load("demos.html#tree-vertical.js"); } },
        { id: "useful", text: "树图 Tree", class: "gtitle button" },

{ text: "lines-bmap.js", click: (e)=>{ load("maps.html#lines-bmap.js"); } },
{ text: "lines-bmap-bus.js", click: (e)=>{ load("maps.html#lines-bmap-bus.js"); } },
{ text: "lines-bmap-effect.js", click: (e)=>{ load("maps.html#lines-bmap-effect.js"); } },
{ text: "lines-ny.js", click: (e)=>{ load("maps.html#lines-ny.js"); } },
        { id: "useful", text: "路径图 Lines", class: "gtitle button" },

{ text: "calendar-graph.js", click: (e)=>{ load("demos.html#calendar-graph.js"); } },
{ text: "graph-webkit-dep.js", click: (e)=>{ load("demos.html#graph-webkit-dep.js"); } },
{ text: "graph-simple.js", click: (e)=>{ load("demos.html#graph-simple.js"); } },
{ text: "graph-npm.js", click: (e)=>{ load("demos.html#graph-npm.js"); } },
{ text: "graph-life-expectancy.js", click: (e)=>{ load("demos.html#graph-life-expectancy.js"); } },
{ text: "graph-grid.js", click: (e)=>{ load("demos.html#graph-grid.js"); } },
{ text: "graph-force2.js", click: (e)=>{ load("demos.html#graph-force2.js"); } },
{ text: "graph-force-dynamic.js", click: (e)=>{ load("demos.html#graph-force-dynamic.js"); } },
{ text: "graph-force.js", click: (e)=>{ load("demos.html#graph-force.js"); } },
{ text: "graph-circular-layout.js", click: (e)=>{ load("demos.html#graph-circular-layout.js"); } },
{ text: "graph.js", click: (e)=>{ load("demos.html#graph.js"); } },
        { id: "useful", text: "关系图 Graph", class: "gtitle button" },

{ text: "ref", click: (e)=>{ load("demos.html#ref"); } },
        { id: "useful", text: "热力图 Heatmap", class: "gtitle button" },

{ text: "ref", click: (e)=>{ load("demos.html#ref"); } },
        { id: "useful", text: "盒须图 Boxplot", class: "gtitle button" },

{ text: "radar.js", click: (e)=>{ load("demos.html#radar.js"); } },
{ text: "radar-aqi.js", click: (e)=>{ load("demos.html#radar-aqi.js"); } },
{ text: "radar-custom.js", click: (e)=>{ load("demos.html#radar-custom.js"); } },
{ text: "radar-aqi.js", click: (e)=>{ load("demos.html#radar-aqi.js"); } },
{ text: "radar-multiple.js", click: (e)=>{ load("demos.html#radar-multiple.js"); } },
{ text: "radar2.js", click: (e)=>{ load("demos.html#radar2.js"); } },
        { id: "useful", text: "雷达图 Radar", class: "gtitle button" },

{ text: "map-bin.js", click: (e)=>{ load("maps.html#map-bin.js"); } },
{ text: "map-polygon.js", click: (e)=>{ load("maps.html#map-polygon.js"); } },
{ text: "map-usa.js", click: (e)=>{ load("maps.html#map-usa.js"); } },
{ text: "custom-hexbin.js", click: (e)=>{ load("maps.html#custom-hexbin.js"); } },
{ text: "effectScatter-bmap.js", click: (e)=>{ load("maps.html#effectScatter-bmap.js"); } },
{ text: "map-parallel-prices.js", click: (e)=>{ load("maps.html#map-parallel-prices.js"); } },
        { id: "useful", text: "地理坐标/地图 GEO/Map", class: "gtitle button" },

{ text: "scatter-matrix.js", click: (e)=>{ load("demos.html#scatter-matrix.js"); } },
{ text: "calendar-charts.js", click: (e)=>{ load("demos.html#calendar-charts.js"); } },
{ text: "scatter-weight.js", click: (e)=>{ load("demos.html#scatter-weight.js"); } },
{ text: "scatter-stream-visual.js", click: (e)=>{ load("demos.html#scatter-stream-visual.js"); } },
{ text: "scatter-single-axis.js", click: (e)=>{ load("demos.html#scatter-single-axis.js"); } },
{ text: "scatter-punchCard.js", click: (e)=>{ load("demos.html#scatter-punchCard.js"); } },
{ text: "scatter-polynomial-regression.js", click: (e)=>{ load("demos.html#scatter-polynomial-regression.js"); } },
{ text: "scatter-polar-punchCard.js", click: (e)=>{ load("demos.html#scatter-polar-punchCard.js"); } },
{ text: "scatter-painter-choice.js", click: (e)=>{ load("demos.html#scatter-painter-choice.js"); } },
{ text: "scatter-nutrients-matrix.js", click: (e)=>{ load("demos.html#scatter-nutrients-matrix.js"); } },
{ text: "scatter-nutrients.js", click: (e)=>{ load("demos.html#scatter-nutrients.js"); } },
{ text: "scatter-logarithmic-regression.js", click: (e)=>{ load("demos.html#scatter-logarithmic-regression.js"); } },
{ text: "scatter-linear-regression.js", click: (e)=>{ load("demos.html#scatter-linear-regression.js"); } },
{ text: "scatter-life-expectancy-timeline.js", click: (e)=>{ load("demos.html#scatter-life-expectancy-timeline.js"); } },
{ text: "scatter-large.js", click: (e)=>{ load("demos.html#scatter-large.js"); } },
{ text: "scatter-exponential-regression.js", click: (e)=>{ load("demos.html#scatter-exponential-regression.js"); } },
{ text: "scatter-effect.js", click: (e)=>{ load("demos.html#scatter-effect.js"); } },
{ text: "scatter-clustering-process.js", click: (e)=>{ load("demos.html#scatter-clustering-process.js"); } },
{ text: "scatter-aqi-color.js", click: (e)=>{ load("demos.html#scatter-aqi-color.js"); } },
{ text: "scatter-anscombe-quartet.js", click: (e)=>{ load("demos.html#scatter-anscombe-quartet.js"); } },
{ text: "bubble-gradient.js", click: (e)=>{ load("demos.html#bubble-gradient.js"); } },
{ text: "scatter-simple.js", click: (e)=>{ load("demos.html#scatter-simple.js"); } },
        { id: "useful", text: "散点图 Scatter", class: "gtitle button" },
        
{ text: "calendar-pie.js", click: (e)=>{ load("demos.html#calendar-pie.js"); } },
{ text: "pie-simple.js", click: (e)=>{ load("demos.html#pie-simple.js"); } },
{ text: "pie-roseType.js", click: (e)=>{ load("demos.html#pie-roseType.js"); } },
{ text: "pie-pattern.js", click: (e)=>{ load("demos.html#pie-pattern.js"); } },
{ text: "pie-legend.js", click: (e)=>{ load("demos.html#pie-legend.js"); } },
{ text: "pie-doughnut.js", click: (e)=>{ load("demos.html#pie-doughnut.js"); } },
{ text: "pie-custom.js", click: (e)=>{ load("demos.html#pie-custom.js"); } },
        { id: "useful", text: "饼图 Pie", class: "gtitle button" },

{ text: "line-polar.js", click: (e)=>{ load("demos.html#line-polar.js"); } },
{ text: "line-polar2.js", click: (e)=>{ load("demos.html#line-polar2.js"); } },
{ text: "bar-polar-real-estate.js", click: (e)=>{ load("demos.html#bar-polar-real-estate.js"); } },
{ text: "bar-polar-stack.js", click: (e)=>{ load("demos.html#bar-polar-stack.js"); } },
{ text: "bar-polar-stack-radial.js", click: (e)=>{ load("demos.html#bar-polar-stack-radial.js"); } },
        { id: "useful", text: "极坐标 Polar", class: "gtitle button" },

{ text: "watermark.js", click: (e)=>{ load("demos.html#watermark.js"); } },
{ text: "multiple-y-axis.js", click: (e)=>{ load("demos.html#multiple-y-axis.js"); } },
{ text: "mix-zoom-on-value.js", click: (e)=>{ load("demos.html#mix-zoom-on-value.js"); } },
{ text: "mix-timeline-finance.js", click: (e)=>{ load("demos.html#mix-timeline-finance.js"); } },
{ text: "dynamic-data.js", click: (e)=>{ load("demos.html#dynamic-data.js"); } },
{ text: "mix-line-bar.js", click: (e)=>{ load("demos.html#mix-line-bar.js"); } },
{ text: "bar1.js", click: (e)=>{ load("demos.html#bar1.js"); } },
{ text: "bar-y-category-stack.js", click: (e)=>{ load("demos.html#bar-y-category-stack.js"); } },
{ text: "bar-y-category.js", click: (e)=>{ load("demos.html#bar-y-category.js"); } },
{ text: "bar-waterfall2.js", click: (e)=>{ load("demos.html#bar-waterfall2.js"); } },
{ text: "bar-waterfall.js", click: (e)=>{ load("demos.html#bar-waterfall.js"); } },
{ text: "bar-tick-align.js", click: (e)=>{ load("demos.html#bar-tick-align.js"); } },
{ text: "bar-stack.js", click: (e)=>{ load("demos.html#bar-stack.js"); } },
{ text: "bar-simple.js", click: (e)=>{ load("demos.html#bar-simple.js"); } },
{ text: "bar-negative2.js", click: (e)=>{ load("demos.html#bar-negative2.js"); } },
{ text: "bar-negative.js", click: (e)=>{ load("demos.html#bar-negative.js"); } },
{ text: "bar-large.js", click: (e)=>{ load("demos.html#bar-large.js"); } },
{ text: "bar-gradient.js", click: (e)=>{ load("demos.html#bar-gradient.js"); } },
{ text: "bar-brush", click: (e)=>{ load("demos.html#bar-brush"); } },
{ text: "bar-animation-delay.js", click: (e)=>{ load("demos.html#bar-animation-delay.js"); } },
        { id: "useful", text: "柱状图 Bar", class: "gtitle button" },

{ text: "multiple-x-axis.js", click: (e)=>{ load("demos.html#multiple-x-axis.js"); } },
{ text: "line-y-category.js", click: (e)=>{ load("demos.html#line-y-category.js"); } },
{ text: "line-style.js", click: (e)=>{ load("demos.html#line-style.js"); } },
{ text: "line-step.js", click: (e)=>{ load("demos.html#line-step.js"); } },
{ text: "line-sections.js", click: (e)=>{ load("demos.html#line-sections.js"); } },
{ text: "line-pen.js", click: (e)=>{ load("demos.html#line-pen.js"); } },
{ text: "line-marker.js", click: (e)=>{ load("demos.html#line-marker.js"); } },
{ text: "line-log.js", click: (e)=>{ load("demos.html#line-log.js"); } },
{ text: "line-in-cartesian-coordinate-system.js", click: (e)=>{ load("demos.html#line-in-cartesian-coordinate-system.js"); } },
{ text: "line-graphic.js", click: (e)=>{ load("demos.html#line-graphic.js"); } },
{ text: "line-gradient.js", click: (e)=>{ load("demos.html#line-gradient.js"); } },
{ text: "line-easing.js", click: (e)=>{ load("demos.html#line-easing.js"); } },
{ text: "line-aqi.js", click: (e)=>{ load("demos.html#line-aqi.js"); } },
{ text: "dynamic-data2.js", click: (e)=>{ load("demos.html#dynamic-data2.js"); } },
{ text: "confidence-band.js", click: (e)=>{ load("demos.html#confidence-band.js"); } },
{ text: "area-simple.js", click: (e)=>{ load("demos.html#area-simple.js"); } },
{ text: "area-rainfall.js", click: (e)=>{ load("demos.html#area-rainfall.js"); } },
{ text: "line-stack.js", click: (e)=>{ load("demos.html#line-stack.js"); } },
{ text: "area-stack.js", click: (e)=>{ load("demos.html#area-stack.js"); } },
{ text: "line-smooth.js", click: (e)=>{ load("demos.html#line-smooth.js"); } },
{ text: "area-basic.js", click: (e)=>{ load("demos.html#area-basic.js"); } },
{ text: "line-simple.js", click: (e)=>{ load("demos.html#line-simple.js"); } },
        { id: "useful", text: "折线图 Line", class: "gtitle button" },

{ text: "candlestick-simple.js", click: (e)=>{ load("demos.html#candlestick-simple.js"); } },
{ text: "candlestick-touch.js", click: (e)=>{ load("demos.html#candlestick-touch.js"); } },
{ text: "custom-ohlc.js", click: (e)=>{ load("demos.html#custom-ohlc.js"); } },
{ text: "candlestick-large.js", click: (e)=>{ load("demos.html#candlestick-large.js"); } },
{ text: "candlestick-sh-2015.js", click: (e)=>{ load("demos.html#candlestick-sh-2015.js"); } },
{ text: "candlestick-brush.js", click: (e)=>{ load("demos.html#candlestick-brush.js"); } },
{ text: "candlestick-sh.js", click: (e)=>{ load("demos.html#candlestick-sh.js"); } },
        { id: "candlestick", text: "K 线图 Candlestick", class: "gtitle button" },

{ text: "gauge.js", click: (e)=>{ load("demos.html#gauge.js"); } },
{ text: "gauge-car.js", click: (e)=>{ load("demos.html#gauge-car.js"); } },
{ text: "gauge-car-dark.js", click: (e)=>{ load("demos.html#gauge-car-dark.js"); } },
        { id: "gauge", text: "时速表 仪表盘 Gauge", class: "gtitle button" },

    ];
    let MENUS = window.MENUS || demos;
    let hash = decodeURI(location.hash.replace("#", ""));

    for (var i = MENUS.length - 1; i >= 0; i--) {
        var it = MENUS[i];
        var cls = (it.class || "button") + (hash==it.text || hash == it.id ? " active" : "");
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