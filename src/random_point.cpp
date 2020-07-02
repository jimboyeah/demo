
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
 
using namespace std;
using namespace cv;
 
int main()
{
    Mat image(480, 640, CV_8UC1, Scalar(255, 255, 255));
    RNG x, y;
    vector<Point> points;
    points.reserve(40);
    for (int i = 0; i < 40; i++)
    {
        int x1 = x.uniform(0, 640);
 
        int y1 = x.uniform(0, 480);
        points.push_back(Point(x1, y1));
 
    }
 
    for (vector<Point>::iterator it = points.begin(); it != points.end(); it++)
    {
        circle(image, *it, 3, CV_RGB(0, 0, 0), 4);
    }
 
    // char key;
    // cout << "Enter w/W to write file\n";
    // cin >> key;
    // if (key == 'w' || key == 'W')
    // {
    //     FileStorage fs("randomPoints40Vector.yml", FileStorage::WRITE);
    //     fs << "points number" << 40;
    //     for (vector<Point>::reverse_iterator it = points.rbegin(); it != points.rend(); it++)
    //     {
    //         fs << *it;
 
    //     }
    //     fs.release();
    // }
 
    imshow("image", image);
    waitKey();
    // system("pause");
    return 0;
}
