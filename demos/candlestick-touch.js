var dom = document.getElementById("container");
var myChart = echarts.init(dom);
var app = {};
option = null;

var rawData = [["2015/1/5","3258.63","3350.52","115.84","3.58%","3253.88","3369.28","531352384","54976008","-"],["2015/1/6","3330.8","3351.45","0.93","0.03%","3303.18","3394.22","501661696","53239848","-"],["2015/1/7","3326.65","3373.95","22.51","0.67%","3312.21","3374.9","391918880","43641672","-"],["2015/1/8","3371.96","3293.46","-80.5","-2.39%","3285.09","3381.57","371131200","39923032","-"],["2015/1/9","3276.97","3285.41","-8.04","-0.24%","3267.51","3404.83","410240864","45864804","-"],["2015/1/12","3258.21","3229.32","-56.1","-1.71%","3191.58","3275.19","322064672","36627308","-"],["2015/1/13","3223.54","3235.3","5.98","0.19%","3214.41","3259.39","230725760","27358878","-"],["2015/1/14","3242.34","3222.44","-12.86","-0.40%","3193.98","3268.48","240190752","26720452","-"],["2015/1/15","3224.07","3336.46","114.02","3.54%","3207.54","3337.08","282546240","33061054","-"],["2015/1/16","3343.6","3376.5","40.04","1.20%","3340.49","3400.32","339876768","39225388","-"],["2015/1/19","3189.73","3116.35","-260.14","-7.70%","3095.07","3262.21","401098784","40988600","-"],["2015/1/20","3114.56","3173.05","56.7","1.82%","3100.48","3190.25","357080800","41629524","-"],["2015/1/21","3189.08","3323.61","150.56","4.74%","3178.34","3337","410956032","47375868","-"],["2015/1/22","3327.32","3343.34","19.73","0.59%","3293.98","3352.38","353382976","40787408","-"],["2015/1/23","3357.1","3351.76","8.42","0.25%","3328.29","3406.79","366249248","42097952","-"],["2015/1/26","3347.26","3383.18","31.42","0.94%","3321.31","3384.8","317540992","35842744","-"],["2015/1/27","3389.85","3352.96","-30.22","-0.89%","3290.22","3390.22","374517568","41829884","-"],["2015/1/28","3325.72","3305.74","-47.22","-1.41%","3294.66","3354.8","301927104","34156428","-"],["2015/1/29","3259","3262.3","-43.43","-1.31%","3234.24","3286.79","274658624","29642450","-"],["2015/1/30","3273.75","3210.36","-51.94","-1.59%","3210.31","3288.5","258312544","28426564","-"],["2015/2/2","3148.14","3128.3","-82.06","-2.56%","3122.57","3175.13","250861632","26684996","-"],["2015/2/3","3156.09","3204.91","76.61","2.45%","3129.73","3207.94","248192160","28335594","-"],["2015/2/4","3212.82","3174.13","-30.78","-0.96%","3171.14","3238.98","249098080","29015516","-"],["2015/2/5","3251.21","3136.53","-37.6","-1.18%","3135.82","3251.21","306139296","34826696","-"],["2015/2/6","3120.09","3075.91","-60.62","-1.93%","3052.94","3129.54","246749680","26650278","-"],["2015/2/9","3063.51","3095.12","19.22","0.62%","3049.11","3119.03","206108384","24071968","-"],["2015/2/10","3090.49","3141.59","46.47","1.50%","3084.25","3142.1","193817136","22508492","-"],["2015/2/11","3145.76","3157.7","16.11","0.51%","3139.05","3166.42","172840096","21086256","-"],["2015/2/12","3157.96","3173.42","15.71","0.50%","3134.24","3181.77","194592320","22969158","-"],["2015/2/13","3186.81","3203.83","30.41","0.96%","3182.79","3237.16","261290432","29301768","-"],["2015/2/16","3206.14","3222.36","18.54","0.58%","3195.88","3228.85","223797440","26595070","-"],["2015/2/17","3230.88","3246.91","24.54","0.76%","3230.77","3255.73","228332624","26334004","-"],["2015/2/25","3256.48","3228.84","-18.06","-0.56%","3215.55","3257.22","233348096","26514336","-"],["2015/2/26","3222.15","3298.36","69.52","2.15%","3202.19","3300.62","301263872","33434746","-"],["2015/2/27","3296.83","3310.3","11.94","0.36%","3291.01","3324.55","299163712","33501958","-"],["2015/3/2","3332.72","3336.28","25.98","0.78%","3298.67","3336.76","346445664","41025956","-"],["2015/3/3","3317.7","3263.05","-73.23","-2.20%","3260.43","3317.7","382044608","44159348","-"],["2015/3/4","3264.18","3279.53","16.48","0.51%","3250.48","3286.59","293639520","34678976","-"],["2015/3/5","3264.08","3248.48","-31.06","-0.95%","3221.67","3266.64","320663584","37358000","-"],["2015/3/6","3248.04","3241.19","-7.29","-0.22%","3234.53","3266.93","282915808","32834414","-"],["2015/3/9","3224.31","3302.41","61.22","1.89%","3198.37","3307.7","321495456","35992752","-"],["2015/3/10","3289.08","3286.07","-16.34","-0.49%","3277.09","3309.92","285817568","32995596","-"],["2015/3/11","3289.59","3290.9","4.83","0.15%","3278.47","3325.05","282985536","32757308","-"],["2015/3/12","3314.81","3349.32","58.42","1.78%","3300.49","3360.05","357295104","40719240","-"],["2015/3/13","3359.49","3372.91","23.59","0.70%","3352.15","3391.25","328410144","37404140","-"],["2015/3/16","3391.16","3449.3","76.39","2.26%","3377.09","3449.3","399132416","47935532","-"],["2015/3/17","3469.6","3502.85","53.54","1.55%","3459.69","3504.12","520939520","60150068","-"],["2015/3/18","3510.5","3577.3","74.45","2.13%","3503.85","3577.66","545217152","61736700","-"],["2015/3/19","3576.02","3582.27","4.97","0.14%","3546.84","3600.68","537346624","61224968","-"],["2015/3/20","3587.08","3617.32","35.05","0.98%","3569.38","3632.34","516661664","65177196","-"],["2015/3/23","3640.1","3687.73","70.41","1.95%","3635.49","3688.25","536062816","66157464","-"],["2015/3/24","3692.57","3691.41","3.68","0.10%","3600.7","3715.87","639554688","75488472","-"],["2015/3/25","3680.95","3660.73","-30.68","-0.83%","3634.56","3693.15","521886336","64549892","-"],["2015/3/26","3641.94","3682.09","21.37","0.58%","3615.01","3707.32","488647200","61951560","-"],["2015/3/27","3686.13","3691.1","9","0.24%","3656.83","3710.48","408945184","50929848","-"],["2015/3/30","3710.61","3786.57","95.47","2.59%","3710.61","3795.94","564702400","69212536","-"],["2015/3/31","3822.99","3747.9","-38.67","-1.02%","3737.04","3835.57","561676032","72129488","-"],["2015/4/1","3748.34","3810.29","62.4","1.66%","3742.21","3817.08","447458304","59241832","-"],["2015/4/2","3827.69","3825.78","15.49","0.41%","3775.89","3835.45","479299680","63202892","-"],["2015/4/3","3803.38","3863.93","38.14","1.00%","3792.21","3864.41","473033312","63565136","-"]];
var colorList = ['#c23531','#2f4554', '#61a0a8', '#d48265', '#91c7ae','#749f83',  '#ca8622', '#bda29a','#6e7074', '#546570', '#c4ccd3'];
var labelFont = 'bold 12px Sans-serif';

function calculateMA(dayCount, data) {
    var result = [];
    for (var i = 0, len = data.length; i < len; i++) {
        if (i < dayCount) {
            result.push('-');
            continue;
        }
        var sum = 0;
        for (var j = 0; j < dayCount; j++) {
            sum += data[i - j][1];
        }
        result.push((sum / dayCount).toFixed(2));
    }
    return result;
}


var dates = ["2016-03-29", "2016-03-30", "2016-03-31", "2016-04-01", "2016-04-04", "2016-04-05", "2016-04-06", "2016-04-07", "2016-04-08", "2016-04-11", "2016-04-12", "2016-04-13", "2016-04-14", "2016-04-15", "2016-04-18", "2016-04-19", "2016-04-20", "2016-04-21", "2016-04-22", "2016-04-25", "2016-04-26", "2016-04-27", "2016-04-28", "2016-04-29", "2016-05-02", "2016-05-03", "2016-05-04", "2016-05-05", "2016-05-06", "2016-05-09", "2016-05-10", "2016-05-11", "2016-05-12", "2016-05-13", "2016-05-16", "2016-05-17", "2016-05-18", "2016-05-19", "2016-05-20", "2016-05-23", "2016-05-24", "2016-05-25", "2016-05-26", "2016-05-27", "2016-05-31", "2016-06-01", "2016-06-02", "2016-06-03", "2016-06-06", "2016-06-07", "2016-06-08", "2016-06-09", "2016-06-10", "2016-06-13", "2016-06-14", "2016-06-15", "2016-06-16", "2016-06-17", "2016-06-20", "2016-06-21", "2016-06-22"];
var data = [[17512.58,17633.11,17434.27,17642.81,86160000],[17652.36,17716.66,17652.36,17790.11,79330000],[17716.05,17685.09,17669.72,17755.7,102600000],[17661.74,17792.75,17568.02,17811.48,104890000],[17799.39,17737,17710.67,17806.38,85230000],[17718.03,17603.32,17579.56,17718.03,115230000],[17605.45,17716.05,17542.54,17723.55,99410000],[17687.28,17541.96,17484.23,17687.28,90120000],[17555.39,17576.96,17528.16,17694.51,79990000],[17586.48,17556.41,17555.9,17731.63,107100000],[17571.34,17721.25,17553.57,17744.43,81020000],[17741.66,17908.28,17741.66,17918.35,91710000],[17912.25,17926.43,17885.44,17962.14,84510000],[17925.95,17897.46,17867.41,17937.65,118160000],[17890.2,18004.16,17848.22,18009.53,89390000],[18012.1,18053.6,17984.43,18103.46,89820000],[18059.49,18096.27,18031.21,18167.63,100210000],[18092.84,17982.52,17963.89,18107.29,102720000],[17985.05,18003.75,17909.89,18026.85,134120000],[17990.94,17977.24,17855.55,17990.94,83770000],[17987.38,17990.32,17934.17,18043.77,92570000],[17996.14,18041.55,17920.26,18084.66,109090000],[18023.88,17830.76,17796.55,18035.73,100920000],[17813.09,17773.64,17651.98,17814.83,136670000],[17783.78,17891.16,17773.71,17912.35,80100000],[17870.75,17750.91,17670.88,17870.75,97060000],[17735.02,17651.26,17609.01,17738.06,95020000],[17664.48,17660.71,17615.82,17736.11,81530000],[17650.3,17740.63,17580.38,17744.54,80020000],[17743.85,17705.91,17668.38,17783.16,85590000],[17726.66,17928.35,17726.66,17934.61,75790000],[17919.03,17711.12,17711.05,17919.03,87390000],[17711.12,17720.5,17625.38,17798.19,88560000],[17711.12,17535.32,17512.48,17734.74,86640000],[17531.76,17710.71,17531.76,17755.8,88440000],[17701.46,17529.98,17469.92,17701.46,103260000],[17501.28,17526.62,17418.21,17636.22,79120000],[17514.16,17435.4,17331.07,17514.16,95530000],[17437.32,17500.94,17437.32,17571.75,111990000],[17507.04,17492.93,17480.05,17550.7,87790000],[17525.19,17706.05,17525.19,17742.59,86480000],[17735.09,17851.51,17735.09,17891.71,79180000],[17859.52,17828.29,17803.82,17888.66,68940000],[17826.85,17873.22,17824.73,17873.22,73190000],[17891.5,17787.2,17724.03,17899.24,147390000],[17754.55,17789.67,17664.79,17809.18,78530000],[17789.05,17838.56,17703.55,17838.56,75560000],[17799.8,17807.06,17689.68,17833.17,82270000],[17825.69,17920.33,17822.81,17949.68,71870000],[17936.22,17938.28,17936.22,18003.23,78750000],[17931.91,18005.05,17931.91,18016,71260000],[17969.98,17985.19,17915.88,18005.22,69690000],[17938.82,17865.34,17812.34,17938.82,90540000],[17830.5,17732.48,17731.35,17893.28,101690000],[17710.77,17674.82,17595.79,17733.92,93740000],[17703.65,17640.17,17629.01,17762.96,94130000],[17602.23,17733.1,17471.29,17754.91,91950000],[17733.44,17675.16,17602.78,17733.44,248680000],[17736.87,17804.87,17736.87,17946.36,99380000],[17827.33,17829.73,17799.8,17877.84,85130000],[17832.67,17780.83,17770.36,17920.16,89440000]];
var volumes = [86160000,79330000,102600000,104890000,85230000,115230000,99410000,90120000,79990000,107100000,81020000,91710000,84510000,118160000,89390000,89820000,100210000,102720000,134120000,83770000,92570000,109090000,100920000,136670000,80100000,97060000,95020000,81530000,80020000,85590000,75790000,87390000,88560000,86640000,88440000,103260000,79120000,95530000,111990000,87790000,86480000,79180000,68940000,73190000,147390000,78530000,75560000,82270000,71870000,78750000,71260000,69690000,90540000,101690000,93740000,94130000,91950000,248680000,99380000,85130000,89440000];

var dataMA5 = calculateMA(5, data);
var dataMA10 = calculateMA(10, data);
var dataMA20 = calculateMA(20, data);


option = {
    animation: false,
    color: colorList,
    title: {
        left: 'center',
        text: '移动端 K线图'
    },
    legend: {
        top: 30,
        data: ['日K', 'MA5', 'MA10', 'MA20', 'MA30']
    },
    tooltip: {
        triggerOn: 'none',
        transitionDuration: 0,
        confine: true,
        bordeRadius: 4,
        borderWidth: 1,
        borderColor: '#333',
        backgroundColor: 'rgba(255,255,255,0.9)',
        textStyle: {
            fontSize: 12,
            color: '#333'
        },
        position: function (pos, params, el, elRect, size) {
            var obj = {
                top: 60
            };
            obj[['left', 'right'][+(pos[0] < size.viewSize[0] / 2)]] = 5;
            return obj;
        }
    },
    axisPointer: {
        link: [{
            xAxisIndex: [0, 1]
        }]
    },
    dataZoom: [{
        type: 'slider',
        xAxisIndex: [0, 1],
        realtime: false,
        start: 20,
        end: 70,
        top: 65,
        height: 20,
        handleIcon: 'M10.7,11.9H9.3c-4.9,0.3-8.8,4.4-8.8,9.4c0,5,3.9,9.1,8.8,9.4h1.3c4.9-0.3,8.8-4.4,8.8-9.4C19.5,16.3,15.6,12.2,10.7,11.9z M13.3,24.4H6.7V23h6.6V24.4z M13.3,19.6H6.7v-1.4h6.6V19.6z',
        handleSize: '120%'
    }, {
        type: 'inside',
        xAxisIndex: [0, 1],
        start: 40,
        end: 70,
        top: 30,
        height: 20
    }],
    xAxis: [{
        type: 'category',
        data: dates,
        boundaryGap : false,
        axisLine: { lineStyle: { color: '#777' } },
        axisLabel: {
            formatter: function (value) {
                return echarts.format.formatTime('MM-dd', value);
            }
        },
        min: 'dataMin',
        max: 'dataMax',
        axisPointer: {
            show: true
        }
    }, {
        type: 'category',
        gridIndex: 1,
        data: dates,
        scale: true,
        boundaryGap : false,
        splitLine: {show: false},
        axisLabel: {show: false},
        axisTick: {show: false},
        axisLine: { lineStyle: { color: '#777' } },
        splitNumber: 20,
        min: 'dataMin',
        max: 'dataMax',
        axisPointer: {
            type: 'shadow',
            label: {show: false},
            triggerTooltip: true,
            handle: {
                show: true,
                margin: 30,
                color: '#B80C00'
            }
        }
    }],
    yAxis: [{
        scale: true,
        splitNumber: 2,
        axisLine: { lineStyle: { color: '#777' } },
        splitLine: { show: true },
        axisTick: { show: false },
        axisLabel: {
            inside: true,
            formatter: '{value}\n'
        }
    }, {
        scale: true,
        gridIndex: 1,
        splitNumber: 2,
        axisLabel: {show: false},
        axisLine: {show: false},
        axisTick: {show: false},
        splitLine: {show: false}
    }],
    grid: [{
        left: 20,
        right: 20,
        top: 110,
        height: 120
    }, {
        left: 20,
        right: 20,
        height: 40,
        top: 260
    }],
    graphic: [{
        type: 'group',
        left: 'center',
        top: 70,
        width: 300,
        bounding: 'raw',
        children: [{
            id: 'MA5',
            type: 'text',
            style: {fill: colorList[1], font: labelFont},
            left: 0
        }, {
            id: 'MA10',
            type: 'text',
            style: {fill: colorList[2], font: labelFont},
            left: 'center'
        }, {
            id: 'MA20',
            type: 'text',
            style: {fill: colorList[3], font: labelFont},
            right: 0
        }]
    }],
    series: [{
        name: 'Volume',
        type: 'bar',
        xAxisIndex: 1,
        yAxisIndex: 1,
        itemStyle: {
            normal: {
                color: '#7fbe9e'
            },
            emphasis: {
                color: '#140'
            }
        },
        data: volumes
    }, {
        type: 'candlestick',
        name: '日K',
        data: data,
        itemStyle: {
            normal: {
                color: '#ef232a',
                color0: '#14b143',
                borderColor: '#ef232a',
                borderColor0: '#14b143'
            },
            emphasis: {
                color: 'black',
                color0: '#444',
                borderColor: 'black',
                borderColor0: '#444'
            }
        }
    }, {
        name: 'MA5',
        type: 'line',
        data: dataMA5,
        smooth: true,
        showSymbol: false,
        lineStyle: {
            normal: {
                width: 1
            }
        }
    }, {
        name: 'MA10',
        type: 'line',
        data: dataMA10,
        smooth: true,
        showSymbol: false,
        lineStyle: {
            normal: {
                width: 1
            }
        }
    }, {
        name: 'MA20',
        type: 'line',
        data: dataMA20,
        smooth: true,
        showSymbol: false,
        lineStyle: {
            normal: {
                width: 1
            }
        }
    }]
};
;
if (option && typeof option === "object") {
    myChart.setOption(option, true);
}
