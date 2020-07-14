import "./css/main.css";
import * as signalR from "@microsoft/signalr";

const divMessages: HTMLDivElement = document.querySelector("#divMessages");
const tbMessage: HTMLInputElement = document.querySelector("#tbMessage");
const btnSend: HTMLButtonElement = document.querySelector("#btnSend");
const username = "K" + new Date().getTime();

(function(){

	if (!window.signalR) return;
	const connection = new signalR.HubConnectionBuilder()
		.withUrl("/hub")
		.build();

	connection.on("ReceiveMessage", (username: string, message: string) => {
		let messages = document.createElement("div");

		messages.innerHTML =
			`<div class="message-author">${username}</div><div>${message}</div>`;

		divMessages.appendChild(messages);
		divMessages.scrollTop = divMessages.scrollHeight;
	});

	connection.start().catch(err => document.write(err));

	tbMessage.addEventListener("keyup", (e: KeyboardEvent) => {
		if (e.key === "Enter") {
			send();
		}
	});

	btnSend.addEventListener("click", send);

	function send() {
		console.log("NewMessage",username, tbMessage.value);
		connection.send("NewMessage", username, tbMessage.value)
			.then(() => tbMessage.value = "");
	}

})();