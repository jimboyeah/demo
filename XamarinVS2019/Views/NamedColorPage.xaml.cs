using System;
using System.ComponentModel;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using XamarinVS2019.ViewModels;

namespace XamarinVS2019.Views
{
    // Learn more about making custom code visible in the Xamarin.Forms previewer
    // by visiting https://aka.ms/xamarinforms-previewer
    [DesignTimeVisible(false)]
    public partial class NamedColorPage : ContentPage
    {
        public NamedColorPage()
        {
            InitializeComponent();
        }

        void OnTapped (object sender, EventArgs args)
        {
            var item = sender as NamedColor;
        }

        void OnMore(object sender, EventArgs args)
        {
            var menu = (MenuItem)sender;
            Navigation.PushAsync(new MainPage());
        }
         void OnDelete(object sender, EventArgs args)
        {
            var menu = (MenuItem)sender;
            var item = menu.CommandParameter as NamedColor;
        }
    }
}