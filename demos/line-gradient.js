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

data = [
  ["2000-06-05",116],
  ["2000-06-06",129],
  ["2000-06-07",135],
  ["2000-06-08",86],
  ["2000-06-09",73],
  ["2000-06-10",85],
  ["2000-06-11",73],
  ["2000-06-12",68],
  ["2000-06-13",92],
  ["2000-06-14",130],
  ["2000-06-15",245],
  ["2000-06-16",139],
  ["2000-06-17",115],
  ["2000-06-18",111],
  ["2000-06-19",309],
  ["2000-06-20",206],
  ["2000-06-21",137],
  ["2000-06-22",128],
  ["2000-06-23",85],
  ["2000-06-24",94],
  ["2000-06-25",71],
  ["2000-06-26",106],
  ["2000-06-27",84],
  ["2000-06-28",93],
  ["2000-06-29",85],
  ["2000-06-30",73],
  ["2000-07-01",83],
  ["2000-07-02",125],
  ["2000-07-03",107],
  ["2000-07-04",82],
  ["2000-07-05",44],
  ["2000-07-06",72],
  ["2000-07-07",106],
  ["2000-07-08",107],
  ["2000-07-09",66],
  ["2000-07-10",91],
  ["2000-07-11",92],
  ["2000-07-12",113],
  ["2000-07-13",107],
  ["2000-07-14",131],
  ["2000-07-15",111],
  ["2000-07-16",64],
  ["2000-07-17",69],
  ["2000-07-18",88],
  ["2000-07-19",77],
  ["2000-07-20",83],
  ["2000-07-21",111],
  ["2000-07-22",57],
  ["2000-07-23",55],
  ["2000-07-24",60]
];

var dateList = data.map(function (item) {
    return item[0];
});
var valueList = data.map(function (item) {
    return item[1];
});

option = {

    // Make gradient line here
    visualMap: [{
        show: true,
        type: 'continuous',
        seriesIndex: 0,
        min: 0,
        max: 600
    }, {
        show: false,
        type: 'continuous',
        seriesIndex: 1,
        dimension: 0,
        min: 0,
        max: dateList.length - 1
    }],


    title: [{
        left: 'center',
        text: 'Gradient along the y axis'
    }, {
        top: '55%',
        left: 'center',
        text: 'Gradient along the x axis'
    }],
    tooltip: {
        trigger: 'axis'
    },
    xAxis: [{
        data: dateList
    }, {
        data: dateList,
        gridIndex: 1
    }],
    yAxis: [{
        splitLine: {show: false}
    }, {
        splitLine: {show: false},
        gridIndex: 1
    }],
    grid: [{
        bottom: '60%'
    }, {
        top: '60%'
    }],
    series: [{
        type: 'line',
        showSymbol: false,
        data: valueList
    }, {
        type: 'line',
        showSymbol: false,
        data: valueList,
        xAxisIndex: 1,
        yAxisIndex: 1
    }]
};;
if (option && typeof option === "object") {
    myChart.setOption(option, true);
}
//        </script>
//    </body>
// </html>