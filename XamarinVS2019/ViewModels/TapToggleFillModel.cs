using System;
using System.Drawing;
using Xamarin.Forms;
using System.Collections.Generic;

using XamarinVS2019.ViewModels;

namespace SkiaSharpFormsDemos.Basics
{
    public class TapToggleFillModel : BaseViewModel
    {

        private int _colorswitch;
        private float _strokewidth;
        private List<Xamarin.Forms.Color> _colors;

        public TapToggleFillModel()
        {
            Title = "Tap Toggle Fill";
            _colors = new List<Xamarin.Forms.Color> {
                Xamarin.Forms.Color.Red,
                Xamarin.Forms.Color.Green,
                Xamarin.Forms.Color.Blue,
                Xamarin.Forms.Color.Yellow,
                Xamarin.Forms.Color.AliceBlue,
                Xamarin.Forms.Color.Aqua
            };
        }

        public int ColorSwitch 
        {
            get { return _colorswitch; }
            set
            {
                SetProperty(ref _colorswitch, value);
                OnPropertyChanged(nameof(Color));
            }
        }

        public Xamarin.Forms.Color Color 
        {
            get { 
                return _colors[_colorswitch];
            }
        }

        public float StrokeWidth 
        {
            get { return _strokewidth; }
            set
            {
                SetProperty(ref _strokewidth, value);
                Console.WriteLine("StrokeWidth {0}", StrokeWidth);
            }
        }

    }

    
}
