#include "core/core.hpp"
#include "highgui/highgui.hpp"
#include "imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;

Mat image, image1, image2;

// warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
// char* windowName = "string";
char* mainWindow   = (char*)"Image Fusion";
char* panelWindow  = (char*)"Controllers";
char* trackBarName = (char*)"α- Alpha";

int _alpha = 0;
int _gamma = 0;
int alphaMax = 50;

void TrackBarFunc(int ,void(*));

int main(int argc,char *argv[])
{
    image1=imread("c:/pictures/x5.jpg");
    image2=imread("c:/pictures/0025.jpg");

    if(!image1.data | !image2.data)  
    {  
        std::cout<<"打开图片失败，请检查路径！"<<std::endl;
        return 0;
    }  
    // resize(src, dst, Size(), 0.5, 0.5, interpolation);
    resize(image2, image2, Size(image1.cols,image1.rows));
    namedWindow(mainWindow, 0);
    namedWindow(panelWindow,0);
    
    // int cv::createTrackbar(const String& trackbarName, const String& winName,
    //                int* value, int count, TrackbarCallback callback,
    //                void* userdata)
    createTrackbar(trackBarName, panelWindow, &_alpha, alphaMax, TrackBarFunc);
    createTrackbar("γ - Gamma", panelWindow, &_gamma, 255, TrackBarFunc);
    TrackBarFunc(0,0); 
    waitKey();
    imwrite("c:/download/water.jpg",image);
    return 0;
}

void TrackBarFunc(int ,void(*))  
{  
    float rate = (float)_alpha/alphaMax;
    // 融合函数，要求输入的两个图形尺寸相同 
    // dst =   cv.addWeighted( src1, alpha, src2, beta, gamma[, dst[, dtype]]  )
    addWeighted(image1, rate, image2, 1-rate, _gamma, image);
    imshow(mainWindow,image);   
}  
