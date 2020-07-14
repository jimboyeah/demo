using System;
using System.Reflection;
using System.Text;
using Xamarin.Forms;
using System.Collections.Generic;
using System.Globalization;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace XamarinVS2019.ViewModels
{
    public class NamedColor : BaseViewModel
    {
        public string Name { private set; get; }
        public string FriendlyName { private set; get; }
        public Color Color { private set; get; }
        public String ColorHex { private set; get; }

        public static List<NamedColor> All { private set; get; }
        public static List<String> AllName { private set; get; }

        // new string Title = "Named Color List";
        public NamedColor()
        {
            Title = "Named Color List";
            this.DateTime = DateTime.Now;
            Device.StartTimer(TimeSpan.FromSeconds(5), () =>
            {
                Console.WriteLine("Device Timer... {0:mm:ss.fff}ms", this.DateTime);
                this.DateTime = DateTime.Now;
                return true;
            });
        }
        
        private DateTime _datetime;
        public DateTime DateTime
        {
            get { return _datetime; }
            set
            {
                if (_datetime != value)
                {
                    _datetime = value;
                    OnPropertyChanged();
                }
            }
        }

        static NamedColor()
        {
            All = new List<NamedColor>();
            AllName = new List<string>();
            Color color = new Color();

            //var fields = color.GetType().GetFields();
            var props = color.GetType().GetRuntimeFields();
            StringBuilder builder = new StringBuilder();
            foreach (FieldInfo pi in props)
            {
                if (pi.FieldType != typeof(Color))
                {
                    continue;
                }

                int idx = 0;
                builder.Clear();
                builder.Append($"[{All.Count,2}] ");
                AllName.Add($"[{AllName.Count,2}] " + pi.Name);
                foreach (char ch in pi.Name)
                {
                    if (idx++ != 0 && char.IsUpper(ch)) builder.Append(' ');
                    builder.Append(ch);
                }
                All.Add(new NamedColor {
                    Name = pi.Name,
                    FriendlyName = builder.ToString(),
                    Color = (Color)pi.GetValue(null),
                    ColorHex = ((Color)pi.GetValue(null)).ToHex()
                });
                // if (All.Count > 50)
                // {
                //     break;
                // }
            }
        }

        //public new event PropertyChangedEventHandler PropertyChanged;

        //private void OnPropertyChanged([CallerMemberName] string name=null)
        //{
        //    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        //}
    }


    class DoubleToIntConverter : IValueConverter
    {
        public object Convert(object value, Type targetType,
                              object parameter, CultureInfo culture)
        {
            double multiplier;

            if (!Double.TryParse(parameter as string, out multiplier))
                multiplier = 1;

            return (int)Math.Round(multiplier * (double)value);
        }

        public object ConvertBack(object value, Type targetType,
                                  object parameter, CultureInfo culture)
        {
            double divider;

            if (!Double.TryParse(parameter as string, out divider))
                divider = 1;

            return ((double)(int)value) / divider;
        }
    }
    
}
