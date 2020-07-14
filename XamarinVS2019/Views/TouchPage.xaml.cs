using System;
using Xamarin.Forms;

namespace XamarinVS2019.Views 
{
    public partial class TouchPage : ContentPage
    {
        public TouchPage()
        {
            InitializeComponent();
        }
        void OnTouchEffectAction(object sender, EventArgs args)
        {
            Console.WriteLine( args);
        }

    }
}

