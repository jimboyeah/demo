var app = require('http').createServer(handler)
var io = require('socket.io')(app, { perMessageDeflate: true });
var fs = require('fs');

app.listen(7001);

function handler(req, res) {
    var url = req.client.parser.incoming.url;
    console.log(req.client.parser.incoming.url)
    var f = {
        "/": "/view/socket-client.tpl",
        "/public/theme.css": "/view/theme.css",
        "/public/socket.io.js": "/../node_modules/socket.io-client/dist/socket.io.js",
        "/public/socket.io.js.map": "/../node_modules/socket.io-client/dist/socket.io.js.map",
    } [url]
    fs.readFile(__dirname + (f || url), function(err, data) {
        if (err) {
            res.writeHead(404);
            return res.end('File Not Found: ' + (f || url));
        }
        res.writeHead(200);
        res.end(data);
    });
}

io.on('connection', function(socket) {
    console.log("socket io connection", socket.nsp.name);
    socket.emit('chat', { hello: 'world' }, (data)=>{
        console.log("emit chat ack", data);    
    });
    socket.on('chat', (data, ack) => {
        var buf = Buffer.from(data, "utf8");
        console.log("socket io on chat", data, ack, buf);
        if (ack && ack.constructor.name == "Function") ack('woo chat');
    });
    socket.on('binary', (data, ack) => {
        console.log("binary data", data, ack);
        if (ack && ack.constructor.name == "Function") ack('woo binary');
    });
});