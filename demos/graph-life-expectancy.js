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
option = {
    grid: {
        left: 0,
        bottom: 0,
        containLabel: true,
        top: 80
    },
    xAxis: {
        type: 'value'
    },
    yAxis: {
        type: 'value',
        scale: true
    },
    toolbox: {
        feature: {
            dataZoom: {}
        }
    },
    dataZoom: {
        type: 'inside'
    },
    series: []
};

$.get(ROOT_PATH + 'data/life-expectancy.json', function (data) {
    var series = data.series;

    option.visualMap = {
        show: false,
        min: 0,
        max: 100,
        dimension: 1
    };

    option.legend = {
        data: data.counties,
        selectedMode: 'single',
        right: 100
    };

    data.counties.forEach(function (country) {
        var data = series.map(function (yearData) {
            var item = yearData.filter(function (item) {
                return item[3] === country;
            })[0];
            return {
                label: {
                    normal: {
                        show: item[4] % 20 === 0 && item[4] > 1940
                    },
                    emphasis: {
                        position: 'top',
                        show: true
                    }
                },
                name: item[4],
                value: item
            };
        });
        var links = data.map(function (item, idx) {
            return {
                source: idx,
                target: idx + 1
            };
        });
        links.pop();

        option.series.push({
            name: country,
            type: 'graph',
            coordinateSystem: 'cartesian2d',
            data: data,
            links: links,
            edgeSymbol: ['none', 'arrow'],
            edgeSymbolSize: 5,
            legendHoverLink: false,
            lineStyle: {
                normal: {
                    color: '#333'
                }
            },
            itemStyle: {
                normal: {
                    borderWidth: 1,
                    borderColor: '#333'
                }
            },
            label: {
                normal: {
                    textStyle: {
                        color: '#333'
                    },
                    position: 'right'
                }
            },
            symbolSize: 10,
            animationDelay: function (idx) {
                return idx * 100;
            }
        });
    });


    myChart.setOption(option);
});;
if (option && typeof option === "object") {
    myChart.setOption(option, true);
}
//        </script>
//    </body>
// </html>