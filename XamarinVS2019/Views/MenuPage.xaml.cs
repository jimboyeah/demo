using XamarinVS2019.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using Xamarin.Forms;
using SkiaSharpFormsDemos.Basics;

namespace XamarinVS2019.Views
{
    // Learn more about making custom code visible in the Xamarin.Forms previewer
    // by visiting https://aka.ms/xamarinforms-previewer
    [DesignTimeVisible(false)]
    public partial class MenuPage : ContentPage
    {
        MainPage RootPage { get => Application.Current.MainPage as MainPage; }
        List<HomeMenuItem> menuItems;
        public MenuPage()
        {
            InitializeComponent();

            menuItems = new List<HomeMenuItem>
            {
                new HomeMenuItem {Id = MenuItemType.Browse, Title="Browse" },
                new HomeMenuItem {Id = MenuItemType.About, Title="About" },
                new HomeMenuItem {Tag = typeof(GameOfLife.GameOfLife), Title="GameOfLife" },
                new HomeMenuItem {Tag = typeof(SessionDataPage), Title="DataPages Demo" },
                new HomeMenuItem {Tag = typeof(TouchPage), Title="TouchPage Demo" },
                new HomeMenuItem {Tag = typeof(TapToggleFillPage), Title="SkiaSharp GDI Demo" },
                new HomeMenuItem {Tag = typeof(KeypadPage), Title="KeypadPage" },
                new HomeMenuItem {Tag = typeof(HSLViewPage), Title="HSL View" },
                new HomeMenuItem {Tag = typeof(NamedColorPage), Title="Named Color" }
            };
            Console.WriteLine("Menu Item add {0}", menuItems.Count);

            ListViewMenu.ItemsSource = menuItems;

            ListViewMenu.SelectedItem = menuItems[0];
            ListViewMenu.ItemSelected += async (sender, e) =>
            {
                if (e.SelectedItem == null)
                    return;

                var item = (HomeMenuItem)e.SelectedItem;
                if (item.Tag == null)
                {
                    await RootPage.NavigateFromMenu(item.Id);
                }else{
                    await RootPage.NavigateFromMenu(item.Tag);
                }
            };
        }
    }
}