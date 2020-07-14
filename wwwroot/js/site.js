// Please see documentation at https://docs.microsoft.com/aspnet/core/client-side/bundling-and-minification
// for details on configuring this project to bundle and minify static web assets.

// Write your JavaScript code.
"use strict";

(function(){
	if(!window.signalR) return;

	var connection = new signalR.HubConnectionBuilder().withUrl("/hub").build();

	//Disable send button until connection is established
	document.getElementById("sendButton").disabled = true;

	connection.on("ReceiveMessage", function (user, message) {
		console.log(user, message);
		var msg = message.replace(/&/g, "&amp;").replace(/</g, "&lt;").replace(/>/g, "&gt;");
		var encodedMsg = user + " says " + msg;
		var li = document.createElement("li");
		li.textContent = encodedMsg;
		document.getElementById("messagesList").appendChild(li);
	});

	connection.start().then(function () {
		document.getElementById("sendButton").disabled = false;
	}).catch(function (err) {
		return console.error(err.toString());
	});

	document.getElementById("sendButton").addEventListener("click", function (event) {
		var user = document.getElementById("userInput").value;
		var message = document.getElementById("messageInput").value;
		connection.invoke("NewMessage", user, message).catch(function (err) {
			return console.error(err.toString());
		});
		event.preventDefault();
	});

})();