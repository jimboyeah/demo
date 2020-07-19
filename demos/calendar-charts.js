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
function getVirtulData(year) {
    year = year || '2017';
    var date = +echarts.number.parseDate(year + '-01-01');
    var end = +echarts.number.parseDate((+year + 1) + '-01-01');
    var dayTime = 3600 * 24 * 1000;
    var data = [];
    for (var time = date; time < end; time += dayTime) {
        data.push([
            echarts.format.formatTime('yyyy-MM-dd', time),
            Math.floor(Math.random() * 1000)
        ]);
    }
    console.log(data[data.length - 1]);
    return data;
}



var graphData = [
    [1485878400000, 260 ],
    [1486137600000, 200 ],
    [1486569600000, 279 ],
    [1486915200000, 847 ],
    [1487347200000, 241 ],
    [1487779200000, 411 ],
    [1488124800000, 985 ]
];

var links = graphData.map(function (item, idx) {
    return {
        source: idx,
        target: idx + 1
    };
});
links.pop();

option = {
    tooltip: {
        position: 'top'
    },

    visualMap: [{
        min: 0,
        max: 1000,
        calculable: true,
        seriesIndex: [2, 3, 4],
        orient: 'horizontal',
        left: '55%',
        bottom: 20
    }, {
        min: 0,
        max: 1000,
        inRange: {
            color: ['grey'],
            opacity: [0, 0.3]
        },
        controller: {
            inRange: {
                opacity: [0.3, 0.6]
            },
            outOfRange: {
                color: '#ccc'
            }
        },
        calculable: true,
        seriesIndex: [1],
        orient: 'horizontal',
        left: '10%',
        bottom: 20
    }],

    calendar: [
    {
        orient: 'vertical',
        yearLabel: {
            margin: 40
        },
        monthLabel: {
            nameMap: 'cn',
            margin: 20
        },
        dayLabel: {
            firstDay: 1,
            nameMap: 'cn'
        },
        cellSize: 40,
        range: '2017-02'
    },
    {
        orient: 'vertical',
        yearLabel: {
            margin: 40
        },
        monthLabel: {
            margin: 20
        },
        cellSize: 40,
        left: 460,
        range: '2017-01'
    },
    {
        orient: 'vertical',
        yearLabel: {
            margin: 40
        },
        monthLabel: {
            margin: 20
        },
        cellSize: 40,
        top: 350,
        range: '2017-03'
    },
    {
        orient: 'vertical',
        yearLabel: {
            margin: 40
        },
        dayLabel: {
            firstDay: 1,
            nameMap: ['周日', '周一', '周二', '周三', '周四', '周五', '周六']
        },
        monthLabel: {
            nameMap: 'cn',
            margin: 20
        },
        cellSize: 40,
        top: 350,
        left: 460,
        range: '2017-04'
    }],

    series: [{
        type: 'graph',
        edgeSymbol: ['none', 'arrow'],
        coordinateSystem: 'calendar',
        links: links,
        symbolSize: 10,
        calendarIndex: 0,
        data: graphData
    }, {
        type: 'heatmap',
        coordinateSystem: 'calendar',
        data: getVirtulData(2017)
    }, {
        type: 'effectScatter',
        coordinateSystem: 'calendar',
        calendarIndex: 1,
        symbolSize: function (val) {
            return val[1] / 40;
        },
        data: getVirtulData(2017)
    }, {
        type: 'scatter',
        coordinateSystem: 'calendar',
        calendarIndex: 2,
        symbolSize: function (val) {
            return val[1] / 60;
        },
        data: getVirtulData(2017)
    }, {
        type: 'heatmap',
        coordinateSystem: 'calendar',
        calendarIndex: 3,
        data: getVirtulData(2017)
    }]
};

if (option && typeof option === "object") {
    myChart.setOption(option, true);
}
//        </script>
//    </body>
// </html>