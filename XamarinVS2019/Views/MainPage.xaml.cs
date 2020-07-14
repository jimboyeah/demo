using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Threading.Tasks;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

using XamarinVS2019.Models;

namespace XamarinVS2019.Views
{
    // Learn more about making custom code visible in the Xamarin.Forms previewer
    // by visiting https://aka.ms/xamarinforms-previewer
    [DesignTimeVisible(false)]
    public partial class MainPage : MasterDetailPage
    {
        Dictionary<MenuItemType, NavigationPage> MenuPages = new Dictionary<MenuItemType, NavigationPage>();
        Dictionary<Type, NavigationPage> MenuPagesTag = new Dictionary<Type, NavigationPage>();
        public MainPage()
        {
            InitializeComponent();

            MasterBehavior = MasterBehavior.SplitOnPortrait;
            IsGestureEnabled = true;
            Master.BackgroundColor = Color.AliceBlue;

            // MenuPages.Add((int)MenuItemType.Browse, (NavigationPage)Detail);
            MenuPagesTag.Add(typeof(ItemsPage), (NavigationPage)Detail);
        }

        public async Task NavigateFromMenu(Type tag)
        {
            if (!MenuPagesTag.ContainsKey(tag))
            {
                var page = System.Activator.CreateInstance(tag) as Page;
                MenuPagesTag.Add(tag, new NavigationPage(page));
            }

            var newPage = MenuPagesTag[tag];

            if (newPage != null && Detail != newPage)
            {
                Detail = newPage;

                if (Device.RuntimePlatform == Device.Android)
                    await Task.Delay(100);

                if (Device.RuntimePlatform==Device.iOS ||
                    Device.RuntimePlatform==Device.Android ||
                    // Device.RuntimePlatform==Device.WinPhone ||
                    MasterBehavior==MasterBehavior.Popover){
                    IsPresented = false;
                }
            }
        }

        public async Task NavigateFromMenu(MenuItemType id)
        {
            if (!MenuPages.ContainsKey(id))
            {
                switch (id)
                {
                    case MenuItemType.Browse:
                        MenuPages.Add(id, new NavigationPage(new ItemsPage()));
                        break;
                    case MenuItemType.About:
                        MenuPages.Add(id, new NavigationPage(new AboutPage()));
                        break;
                }
            }

            var newPage = MenuPages[id];

            if (newPage != null && Detail != newPage)
            {
                Detail = newPage;

                if (Device.RuntimePlatform == Device.Android)
                    await Task.Delay(100);

                if (MasterBehavior==MasterBehavior.Popover){
                    IsPresented = false;
                }
            }
        }
    }
}