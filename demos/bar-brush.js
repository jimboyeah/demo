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
app.title = '柱状图框选';

var xAxisData = [];
var data1 = [];
var data2 = [];
var data3 = [];
var data4 = [];

for (var i = 0; i < 10; i++) {
    xAxisData.push('Class' + i);
    data1.push((Math.random() * 2).toFixed(2));
    data2.push(-Math.random().toFixed(2));
    data3.push((Math.random() * 5).toFixed(2));
    data4.push((Math.random() + 0.3).toFixed(2));
}

var itemStyle = {
    normal: {
    },
    emphasis: {
        barBorderWidth: 1,
        shadowBlur: 10,
        shadowOffsetX: 0,
        shadowOffsetY: 0,
        shadowColor: 'rgba(0,0,0,0.5)'
    }
};

option = {
    backgroundColor: '#eee',
    legend: {
        data: ['bar', 'bar2', 'bar3', 'bar4'],
        align: 'left',
        left: 10
    },
    brush: {
        toolbox: ['rect', 'polygon', 'lineX', 'lineY', 'keep', 'clear'],
        xAxisIndex: 0
    },
    toolbox: {
        feature: {
            magicType: {
                type: ['stack', 'tiled']
            },
            dataView: {}
        }
    },
    tooltip: {},
    xAxis: {
        data: xAxisData,
        name: 'X Axis',
        silent: false,
        axisLine: {onZero: true},
        splitLine: {show: false},
        splitArea: {show: false}
    },
    yAxis: {
        inverse: true,
        splitArea: {show: false}
    },
    grid: {
        left: 100
    },
    visualMap: {
        type: 'continuous',
        dimension: 1,
        text: ['High', 'Low'],
        inverse: true,
        itemHeight: 200,
        calculable: true,
        min: -2,
        max: 6,
        top: 60,
        left: 10,
        inRange: {
            colorLightness: [0.4, 0.8]
        },
        outOfRange: {
            color: '#bbb'
        },
        controller: {
            inRange: {
                color: '#2f4554'
            }
        }
    },
    series: [
        {
            name: 'bar',
            type: 'bar',
            stack: 'one',
            itemStyle: itemStyle,
            data: data1
        },
        {
            name: 'bar2',
            type: 'bar',
            stack: 'one',
            itemStyle: itemStyle,
            data: data2
        },
        {
            name: 'bar3',
            type: 'bar',
            stack: 'two',
            itemStyle: itemStyle,
            data: data3
        },
        {
            name: 'bar4',
            type: 'bar',
            stack: 'two',
            itemStyle: itemStyle,
            data: data4
        }
    ]
};

myChart.on('brushSelected', renderBrushed);

function renderBrushed(params) {
    var brushed = [];
    var brushComponent = params.batch[0];

    for (var sIdx = 0; sIdx < brushComponent.selected.length; sIdx++) {
        var rawIndices = brushComponent.selected[sIdx].dataIndex;
        brushed.push('[Series ' + sIdx + '] ' + rawIndices.join(', '));
    }

    myChart.setOption({
        title: {
            backgroundColor: '#333',
            text: 'SELECTED DATA INDICES: \n' + brushed.join('\n'),
            bottom: 0,
            right: 0,
            width: 100,
            textStyle: {
                fontSize: 12,
                color: '#fff'
            }
        }
    });
};
if (option && typeof option === "object") {
    myChart.setOption(option, true);
}
//        </script>
//    </body>
// </html>