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

var CHUNK_COUNT = 32;

var dataCount = 0;

function fetchData(idx) {
    if (idx >= CHUNK_COUNT) {
        return;
    }
    var dataURL = ROOT_PATH + 'data/links_ny_' + idx + '.bin';
    var xhr = new XMLHttpRequest();
    xhr.open('GET', dataURL, true);
    xhr.responseType = 'arraybuffer';

    xhr.onload = function (e) {
        var rawData = new Float32Array(this.response);
        var data = new Float64Array(rawData.length - 2);
        var offsetX = rawData[0];
        var offsetY = rawData[1];
        var off = 0;
        var addedDataCount = 0;
        for (var i = 2; i < rawData.length;) {
            var count = rawData[i++];
            data[off++] = count;
            for (var k = 0; k < count; k++) {
                var x = rawData[i++] + offsetX;
                var y = rawData[i++] + offsetY;
                data[off++] = x;
                data[off++] = y;

                addedDataCount++;
            }
        }

        myChart.appendData({
            seriesIndex: 0,
            data: data
        });

        dataCount += addedDataCount;

        fetchData(idx + 1);
    }

    xhr.send();
}

option = {
    progressive: 20000,
    backgroundColor: '#111',
    geo: {
        center: [-74.04327099998152, 40.86737600240287],
        zoom: 360,
        map: 'world',
        roam: true,
        silent: true,
        itemStyle: {
            normal: {
                color: 'transparent',
                borderColor: 'rgba(255,255,255,0.1)',
                borderWidth: 1
            }
        }
    },
    series: [{
        type: 'lines',

        coordinateSystem: 'geo',

        blendMode: 'lighter',

        dimensions: ['value'],

        data: new Float64Array(),
        polyline: true,
        large: true,

        lineStyle: {
            color: 'orange',
            width: 0.5,
            opacity: 0.3
        }
    }]
}

fetchData(0);;
if (option && typeof option === "object") {
    myChart.setOption(option, true);
}
//        </script>
//    </body>
// </html>