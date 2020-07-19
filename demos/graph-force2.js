// <!DOCTYPE html>
// <html style="height: 100%">
//    <head>
//        <meta charset="utf-8">
//    </head>
//    <body style="height: 100%; margin: 0">
//        <div id="container" style="height: 100%"></div>
//        <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts/dist/echarts.min.js"></script>
//        <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts-gl/dist/echarts-gl.min.js"></script>
//        <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts-stat/dist/ecStat.min.js"></script>
//        <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts/dist/extension/dataTool.min.js"></script>
//        <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts/map/js/china.js"></script>
//        <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts/map/js/world.js"></script>
//        <script type="text/javascript" src="https://api.map.baidu.com/api?v=2.0&ak=xfhhaTThl11qYVrqLZii6w8qE5ggnhrY&__ec_v__=20190126"></script>
//        <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts/dist/extension/bmap.min.js"></script>
//        <script type="text/javascript">
var dom = document.getElementById("container");
var myChart = echarts.init(dom);
var app = {};
option = null;
app.title = '力引导布局';

function createNodes(count) {
    var nodes = [];
    for (var i = 0; i < count; i++) {
        nodes.push({
            id: i
        });
    }
    return nodes;
}

function createEdges(count) {
    var edges = [];
    if (count === 2) {
        return [[0, 1]];
    }
    for (var i = 0; i < count; i++) {
        edges.push([i, (i + 1) % count]);
    }
    return edges;
}

var datas = [];
for (var i = 0; i < 16; i++) {
    datas.push({
        nodes: createNodes(i + 2),
        edges: createEdges(i + 2)
    });
}

option = {
    series: datas.map(function (item, idx) {
        return {
            type: 'graph',
            layout: 'force',
            animation: false,
            data: item.nodes,
            left: (idx % 4) * 25 + '%',
            top: Math.floor(idx / 4) * 25 + '%',
            width: '25%',
            height: '25%',
            force: {
                // initLayout: 'circular'
                // gravity: 0
                repulsion: 60,
                edgeLength: 2
            },
            edges: item.edges.map(function (e) {
                return {
                    source: e[0],
                    target: e[1]
                };
            })
        };
    })
};
;
if (option && typeof option === "object") {
    myChart.setOption(option, true);
}
//        </script>
//    </body>
// </html>