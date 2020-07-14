using System;
using System.Collections.Generic;
using System.Text;

namespace XamarinVS2019.Models
{
    public enum MenuItemType
    {
        Browse,
        About
    }
    public class HomeMenuItem
    {
        public MenuItemType Id { get; set; }
        public Type Tag { get; set; }

        public string Title { get; set; }
    }
}
