using System;
using Xamarin.Forms;

namespace XamarinVS2019.Views
{
	public partial class SessionDataPage : ContentPage // was ContentPage
	// public partial class SessionDataPage : Xamarin.Forms.Pages.ListDataPage // was ContentPage
	{
		public SessionDataPage ()
		{
			InitializeComponent ();
		}

		void PanUpdated(object sender, PanUpdatedEventArgs args)
		{
			double radius = Math.Min(Width, Height) / 2;
			var avatar = sender as VisualElement;
			Console.WriteLine("Pan Updated {0}, {1}, {2}", avatar.Height, args.TotalX, args.TotalY);
			avatar.TranslateTo(args.TotalX, args.TotalY);
			// avatar.Rotation = 0;
			// avatar.AnchorY = radius / avatar.Height;
			//await avatar.RotateTo(360, 2000);
		}
	}

}