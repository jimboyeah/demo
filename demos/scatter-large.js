<!DOCTYPE html>
<html style="height: 100%">
   <head>
       <meta charset="utf-8">
   </head>
   <body style="height: 100%; margin: 0">
       <div id="container" style="height: 100%"></div>
       <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts/dist/echarts.min.js"></script>
       <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts-gl/dist/echarts-gl.min.js"></script>
       <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts-stat/dist/ecStat.min.js"></script>
       <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts/dist/extension/dataTool.min.js"></script>
       <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts/map/js/china.js"></script>
       <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts/map/js/world.js"></script>
       <script type="text/javascript" src="https://api.map.baidu.com/api?v=2.0&ak=xfhhaTThl11qYVrqLZii6w8qE5ggnhrY&__ec_v__=20190126"></script>
       <script type="text/javascript" src="https://cdn.jsdelivr.net/npm/echarts/dist/extension/bmap.min.js"></script>
       <script type="text/javascript">
var dom = document.getElementById("container");
var myChart = echarts.init(dom);
var app = {};
option = null;
function genData(len, offset) {
    var lngRange = [-10.781327, 131.48];
    var latRange = [18.252847, 52.33];

    var arr = new Float32Array(len * 2);
    var off = 0;

    for (var i = 0; i < len; i++) {
        var x = +Math.random() * 10;
        var y = +Math.sin(x) - x * (len % 2 ? 0.1 : -0.1) * Math.random() + (offset || 0) / 10;
        arr[off++] = x;
        arr[off++] = y;
    }
    return arr;
}

var data1 = genData(5e5);
var data2 = genData(5e5, 10);

option = {
    title: {
        text: echarts.format.addCommas(data1.length / 2 + data2.length / 2) + ' Points'
    },
    tooltip: {},
    toolbox: {
        left: 'center',
        feature: {
            dataZoom: {}
        }
    },
    legend: {
        orient: 'vertical',
        right: 10
    },
    xAxis: [{
    }],
    yAxis: [{
    }],
    dataZoom: [{
        type: 'inside'
    }, {
        type: 'slider'
    }],
    animation: false,
    series : [{
        name: 'A',
        type: 'scatter',
        data: data1,
        dimensions: ['x', 'y'],
        symbolSize: 3,
        itemStyle: {
            opacity: 0.4
        },
        large: true
    }, {
        name: 'B',
        type: 'scatter',
        data: data2,
        dimensions: ['x', 'y'],
        symbolSize: 3,
        itemStyle: {
            opacity: 0.4
        },
        large: true
    }]
};

;
if (option && typeof option === "object") {
    myChart.setOption(option, true);
}
       </script>
   </body>
</html>