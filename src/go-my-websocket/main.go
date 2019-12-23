package main

import (
	"./ws"
	"html/template"
	stdLog "log"
	"net/http"
	"os"
)

var log = stdLog.New(os.Stderr, "[ws]", stdLog.Ltime)

func main() {
	staticweb := http.StripPrefix("/socket/", http.FileServer(http.Dir("./src/view/")))

	http.Handle("/socket.io/", ws.Wsdemo{})
	http.Handle("/socket/", staticweb)
	http.HandleFunc("/", home)

	log.SetPrefix("[wsDemo]")
	log.Println("Serving at localhost:8000...")
	log.Fatal(http.ListenAndServe(":8000", nil))
}

func home(w http.ResponseWriter, r *http.Request) {
	homeTemplate.Execute(w, "ws://"+r.Host+"/socket.io/")
}

var homeTemplate = template.Must(template.New("").Parse(`
	<!DOCTYPE html>
	<html>
	<head>
	<meta charset="utf-8">
	<script>  
	window.addEventListener("load", function(evt) {

	    var output = document.getElementById("output");
	    var input = document.getElementById("input");
	    var ws;

	    var print = function(message) {
	        var d = document.createElement("div");
	        d.innerHTML = message;
	        output.appendChild(d);
	    };

	    document.getElementById("open").onclick = function(evt) {
	        if (ws) {
	            return false;
	        }
	        ws = new WebSocket("{{.}}");
	        ws.onopen = function(evt) {
	            print("OPEN");
	        }
	        ws.onclose = function(evt) {
	            print("CLOSE");
	            ws = null;
	        }
	        ws.onmessage = function(evt) {
	            print("⇩⇧ " + evt.data);
	        }
	        ws.onerror = function(evt) {
	            print("ERROR: " + evt.data);
	        }
	        return false;
	    };

	    document.getElementById("send").onclick = function(evt) {
	        if (!ws) {
	            return false;
	        }
	        print("☝ " + input.value);
	        ws.send(input.value);
	        return false;
	    };

	    document.getElementById("close").onclick = function(evt) {
	        if (!ws) {
	            return false;
	        }
	        ws.close();
	        return false;
	    };

	});
	</script>
	</head>
	<body>
	<table>
	<tr><td valign="top" width="50%">
	<p>1. <b>Open</b> a websocket connection to the server.
	<p>2. <b>Send</b> a message to the server.
	<p>3. <b>Change</b> the message below. 
	<p>4. <b>Close</b> the connection. 
	<p><a href="/socket/">to test socket.io</a>
	<form>
	<button id="open">Open</button>
	<button id="close">Close</button>
	<button id="send">Send</button>
	<p><textarea name="input" id="input" cols="30" rows="10">Hello world!</textarea>
	<finput id="finput" type="text" value="42["chat", "Hello world!"]">
	</form>
	</td><td valign="top" width="50%">
	<div id="output"></div>
	</td></tr></table>
	</body>
	</html>
	`))
