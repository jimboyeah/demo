#include <opencv2/opencv.hpp>
#include <opencv2/freetype.hpp>

using namespace std;
using namespace cv;

int main(int argc,char **argv){
    String text = "Hello世界！*毛*泽*东";
    int fontHeight = 60;
    int thickness = -1;
    int linestyle = 8;
    int baseline=0;

    Ptr<freetype::FreeType2> ft2;
    ft2 = freetype::createFreeType2();
    ft2->loadFontData( "c:/windows/fonts/msyh.ttf", 0 );

    namedWindow("box");
    Mat img(600, 800, CV_8UC3, Scalar::all(0));

    Size textSize = ft2->getTextSize(text,
                                 fontHeight,
                                 thickness,
                                 &baseline);
    if(thickness > 0){
        baseline += thickness;
    }

    Point textOrg((img.cols - textSize.width) / 2,
                  (img.rows + textSize.height) / 2);
    rectangle(img, textOrg + Point(0, baseline),
          textOrg + Point(textSize.width, -textSize.height),
          Scalar(0,255,0),1,8);
    line(img, textOrg + Point(0, thickness),
     textOrg + Point(textSize.width, thickness),
     Scalar(0, 0, 255),1,8);
    ft2->putText(img, text, textOrg, fontHeight,
             Scalar::all(255), thickness, linestyle, true );
    imshow("box",img);
    
    while(1){ if(waitKey(100)==27)break; } 

    return 0;
}