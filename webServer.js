	const http = require("http");

	// Create an demo web server
	const webServer = http.createServer((req,res)=>{
		res.writeHead("200",{
			"Content-Type":"text/html",
			"Server":"c-daystep Demo 0.1"
		});
		console.log("Incoming message ",req.method, req.url);
		if( req.url=="/close" ) webServer.close();

		res.write(`
		<!DOCTYPE html>
		<html>
			<head>
				<meta charset="utf-8">
				<title>html-css-js-demo</title>
				<link rel="stylesheet" href="theme.css">
				<style>
					body { background:repeating-linear-gradient(30deg, #f6bd3c 2%, #f6cd3c 5%); }
					h1 { line-height: 1.2em; text-align: center; }
					.explain { color: bisque; }
					#header { border:1px solid yellow; background:#804080; width:520px; height:220px; margin:auto; }
					#header .abbreviation { color: #ff8040; }
				</style>
				<script>
					function setFont(event){
						// var her = document.getElementById("header");
						var her = event.currentTarget;
						her.style.fontSize = Math.round(Math.random()*50+50)+'px';
					}
				</script>
			</head>
			<body style="font-size:36px;">
				<h1 id="header" onclick="setFont(event)">
					<span class="abbreviation">DOM</span>
					 - 
					<span class="explain">Document Object Model</span>
				</h1>
			</body>
		</html>
		`);
		res.end();
	});
	webServer.on("error", (err)=>{
		let file = arguments[3];
		console.log("Error", err.code, err.message, file);
	});
	webServer.on('clientError', (err, socket) => {
	  socket.end('HTTP/1.1 400 Bad Request\r\n\r\n');
	});
	webServer.on("connection", (socket)=>{
		let client = [socket.remoteAddress, socket.remotePort].join(":");
		console.log("connection...", socket.address(), client);
	});
	webServer.on("close", (socket)=>{
		let client = [socket.remoteAddress, socket.remotePort].join(":");
		console.log("close...", socket.address(), client);
	});
	webServer.listen(8080, '127.0.0.1',()=>console.log("Web Sever listnning... http://127.0.0.1:8080"));
