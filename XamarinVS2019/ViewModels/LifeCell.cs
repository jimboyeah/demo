using System;
using Xamarin.Forms;

class LifeCell : BoxView
{
    bool isAlive;

    public event EventHandler Tapped;
    public event EventHandler<SwipedEventArgs> Swiped;
    public event EventHandler<PinchGestureUpdatedEventArgs> PinchUpdated;

    public LifeCell()
    {
        BackgroundColor = Color.White;

        var swipeGesture = new SwipeGestureRecognizer{ Direction = SwipeDirection.Left | SwipeDirection.Right};
        swipeGesture.Swiped += (sender, args) =>
        {
            Swiped?.Invoke(this, args);
        };
        GestureRecognizers.Add(swipeGesture);

        PinchGestureRecognizer pinchGesture = new PinchGestureRecognizer();
        pinchGesture.PinchUpdated += (sender, args) =>
        {
            PinchUpdated?.Invoke(this, args);
        };
        GestureRecognizers.Add(pinchGesture);

        TapGestureRecognizer tapGesture = new TapGestureRecognizer();
        tapGesture.Tapped += (sender, args) =>
        {
            Tapped?.Invoke(this, EventArgs.Empty);
        };
        GestureRecognizers.Add(tapGesture);
    }

    public int Col { set; get; }

    public int Row { set; get; }

    public bool IsAlive
    {
        set
        {
            if (isAlive != value)
            {
                isAlive = value;
                BackgroundColor = isAlive ? Color.Black : Color.White;
            }
        }
        get
        {
            return isAlive;
        }
    }
}