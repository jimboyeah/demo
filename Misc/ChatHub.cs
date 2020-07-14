using System;
using Microsoft.AspNetCore.SignalR;
using System.Threading.Tasks;


namespace AppWeb
{

    public class ChatHub : Hub
    {
        public async Task SendMessage(string user, string message)
        {
        	Console.WriteLine($"SendMessage {user} {message}");
            await Clients.Caller.SendAsync("ReceiveMessage", user, message);
            // await Clients.All.SendAsync("ReceiveMessage", user, message);
        }
        
        public async Task NewMessage(string user, string message)
        {
            Console.WriteLine($"NewMessage {user} {message}");
            await Clients.All.SendAsync("ReceiveMessage", user, message);
        }

    }

}
