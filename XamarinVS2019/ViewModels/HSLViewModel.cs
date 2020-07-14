using System;
using Xamarin.Forms;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Collections.Generic;

namespace XamarinVS2019.ViewModels
{
    public class HSLViewModel : INotifyPropertyChanged
    {
    	Color _color;
    	Double _hue, _saturation, _luminosity, _ratationX, _ratationY, _rotationZ;

        // new string Title = "HSL Color Scroll Page";
        // public HSLViewModel()
        // {
        //     Title = "HSL Color Scroll Page";
        // }
		public event PropertyChangedEventHandler PropertyChanged;

		public void OnPropertyChanged([CallerMemberName] string name = "")
		{
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
		}

        private bool setProperty<T>(ref T store, T value, 
                [CallerMemberName] string name = null, Action onChanged = null)
        {
            if (EqualityComparer<T>.Default.Equals(store, value)) return false;
            store = value;
            onChanged?.Invoke();
            OnPropertyChanged(name);
            return true;
        }

    	public Color Color 
    	{
    		get { return _color; }
    		set 
    		{
    			if (_color==value) return;
    			_color = value;
    			Hue = value.Hue;
    			Saturation = value.Saturation;
    			Luminosity = value.Luminosity;
                OnPropertyChanged();
    		}
    	}
    	public Double Hue 
    	{
    		get { return _hue; }
    		set
    		{
    			if (setProperty(ref _hue, value))
                {
                    updateColor();
                }
    		}
    	}
    	public Double Saturation 
    	{
    		get { return _saturation; }
    		set
    		{
                if (setProperty(ref _saturation, value))
                {
                    updateColor();
                }
    		}
    	}
    	public Double Luminosity 
    	{
    		get { return _luminosity; }
    		set
    		{
                if (setProperty(ref _luminosity, value))
                {
                    updateColor();
                }
    		}
    	}
        public Double RotationZ 
        {
            get { return _rotationZ; }
            set
            {
                setProperty(ref _rotationZ, value);
            }
        }

        public Double RotationX 
        {
            get { return _ratationX; }
            set
            {
                setProperty(ref _ratationX, value);
            }
        }

        public Double RotationY 
        {
            get { return _ratationY; }
            set
            {
                setProperty(ref _ratationY, value);
            }
        }

		void updateColor()
		{
			Color = Color.FromHsla(Hue, Saturation, Luminosity);
		}

    }
}