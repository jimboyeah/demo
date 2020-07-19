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
// Thanks to: 若怀冰
// http://gallery.echartsjs.com/explore.html?u=bd-16906679
// http://gallery.echartsjs.com/editor.html?c=xHJw-hVqjW

$.getJSON(ROOT_PATH + 'data/house-price-area2.json', function (data) {

    var option = {
        title: {
            text: 'Dispersion of house price based on the area',
            left: 'center',
            top: 0
        },
        visualMap: {
            min: 15202,
            max: 159980,
            dimension: 1,
            orient: 'vertical',
            right: 10,
            top: 'center',
            text: ['HIGH', 'LOW'],
            calculable: true,
            inRange: {
                color: ['#f2c31a', '#24b7f2']
            }
        },
        tooltip: {
            trigger: 'item',
            axisPointer: {
                type: 'cross'
            }
        },
        xAxis: [{
            type: 'value'
        }],
        yAxis: [{
            type: 'value'
        }],
        series: [{
            name: 'price-area',
            type: 'scatter',
            symbolSize: 5,
            // itemStyle: {
            //     normal: {
            //         borderWidth: 0.2,
            //         borderColor: '#fff'
            //     }
            // },
            data: data
        }]
    };

    myChart.setOption(option);
});;
if (option && typeof option === "object") {
    myChart.setOption(option, true);
}
//        </script>
//    </body>
// </html>