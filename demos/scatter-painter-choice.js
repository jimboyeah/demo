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
myChart.showLoading();

$.get(ROOT_PATH + 'data/masterPainterColorChoice.json', function (json) {
    myChart.hideLoading();

    var data = json[0].x.map(function (x, idx) {
        return [+x, +json[0].y[idx]];
    });

    myChart.setOption(option = {
        title: {
            text: 'Master Painter Color Choices Throughout History',
            subtext: 'Data From Plot.ly',
            left: 'right'
        },
        tooltip: {
            trigger: 'axis',
            axisPointer: {
                type: 'cross'
            }
        },
        xAxis: {
            type: 'value',
            splitLine: {
                show: false
            },
            scale: true,
            splitNumber: 5,
            max: 'dataMax',
            axisLabel: {
                formatter: function (val) {
                    return val + 's';
                }
            }
        },
        yAxis: {
            type: 'value',
            min: 0,
            max: 360,
            interval: 60,
            name: 'Hue',
            splitLine: {
                show: false
            }
        },
        series: [{
            name: 'scatter',
            type: 'scatter',
            symbolSize: function (val, param) {
                return json[0].marker.size[param.dataIndex] / json[0].marker.sizeref;
            },
            itemStyle: {
                normal: {
                    color: function (param) {
                        return json[0].marker.color[param.dataIndex];
                    }
                }
            },
            data: data
        }]
    });
});;
if (option && typeof option === "object") {
    myChart.setOption(option, true);
}
//        </script>
//    </body>
// </html>