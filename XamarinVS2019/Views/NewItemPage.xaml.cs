using System;
using System.Collections.Generic;
using System.ComponentModel;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

using XamarinVS2019.Models;

namespace XamarinVS2019.Views
{
    // Learn more about making custom code visible in the Xamarin.Forms previewer
    // by visiting https://aka.ms/xamarinforms-previewer
    [DesignTimeVisible(false)]
    public partial class NewItemPage : ContentPage
    {
        public Item Item { get; set; }

        public NewItemPage()
        {
            InitializeComponent();

            Item = new Item
            {
                Text = "Item name",
                Description = "This is an item description."
            };

            MessagingCenter.Subscribe<string, DateTime>(this, "TryExit", async (sender, args) =>
            {
                Console.WriteLine($"sender {sender} args {args}");
                await Navigation.PopModalAsync();
            });

            BindingContext = this;
        }

        void Send_Clicked(object sender, EventArgs e)
        {
            MessagingCenter.Send("DateTime", "TryExit", DateTime.Now);
        }

        async void Save_Clicked(object sender, EventArgs e)
        {
            MessagingCenter.Send(this, "AddItem", Item);
            await Navigation.PopModalAsync();
        }

        async void Cancel_Clicked(object sender, EventArgs e)
        {
            await Navigation.PopModalAsync();
        }
    }
}