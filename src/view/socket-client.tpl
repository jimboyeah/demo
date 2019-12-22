<!-- app/view/socket-client.tpl -->
<html>

<head>
	<title>Socket Test</title>
	<link rel="stylesheet" href="/public/theme.css" />
	<script src="/public/socket.io.js"></script>
</head>

<body>
	<!-- <h1>Socket Test</h1> -->
	<input class="chat-type" placeholder="Socket Test" type="text" onchange="onType(event)" />

	<script>
	// browser
	const log = console.log;

	function onType(e){
		console.log("onType", e.target);
		if(!socket) return;
		socket.emit("chat", e.target.value);
		addMessage("send", {userId, text: e.target.value});
		e.target.value = "";
	}

	var userId = `client_${Math.random().toFixed(5).substr(2)}`;
	var it = document.createElement('ul');
	it.className = "messages";

	document.body.appendChild(it)
	function addMessage(type, msg){
		var li = document.createElement('li');
		li.innerHTML = "<i>"+msg.text+"</i>"+"<b>"+msg.userId+"</b>";
		li.className = type+" "+(msg.type || "");
		if(userId==msg.userId){
			li.className += " self";
		}
		if((msg.text=="connected!" || msg.text=="disconnected!") && msg.rooms){
			var rooms = Object.keys(msg.rooms).length;
			var s = [];
			for(var i in msg.rooms){
				s.push("<i>Room:"+i+" Numbers:"+msg.rooms[i].length+"</i>")
			}
			li.innerHTML += "<div>"+s.join("<br>")+"</div>";
		}
		it.appendChild(li);
	}


	window.onload = function() {

		// init
		var room = 'tent-lodge';
		var namespace = '/';
		// namespace = '/example';
		// namespace = "http://localhost/";

		var socket = io(namespace, {
			// Actual use can pass parameters here
			query: {
				room,
				userId,
			},

			transports: ['websocket']
		});
	    // var socket = io(namespace);
		socket.binaryType = 'arraybuffer';

		socket.on('connect', () => {
			const id = socket.id;

			log('#connect,', id, socket); // receive online user information
			addMessage("connect", {userId, text: "connected "+id});
			var msg = 'Hello Socket.io!';
			socket.emit('chat', msg, function(data){
				console.log("chat ack", data)
			});
			addMessage("send", {userId, text: msg});

			// listen for its own id to implement p2p communication
			socket.on(id, msg => {
				log('#receive,', msg);
			});

		    // var socket = io(namespace);
			// socket.binaryType = 'arraybuffer';
			// socket.send(new ArrayBuffer);
			var buffer = new Uint8Array([0x65,0x66,0x67]);
			socket.binary(true).emit("binary", buffer, function(data){
				console.log("binary ack", data)
			});
		});

		socket.on('chat', (msg, ack) => {
			addMessage("received", msg);
			console.log('chat from server:', msg, ack);
			var buffer = new Uint8Array([0x85,0x86,0x87]);
			var hex = String.fromCharCode.apply(null, buffer)
			socket.binary(true)
			if(ack) ack(hex)
		});

		socket.on('online', msg => {
			log('#online,', msg);
		});

		// system events
		socket.on('disconnect', msg => {
			log('#disconnect', msg);
		});

		socket.on('disconnecting', () => {
			log('#disconnecting');
		});

		socket.on('error', () => {
			log('#error');
		});

		window.socket = socket;
	};

	</script>

</body>

</html>