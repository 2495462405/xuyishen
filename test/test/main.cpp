//
//  main.cpp
//  test
//
//  Created by 徐亦燊 on 2020/2/28.
//  Copyright © 2020 徐亦燊. All rights reserved.
//

#include <iostream>
#include <highgui.hpp>

using namespace cv;

int main(int argc, const char * argv[]) {
    
    
    cv::Mat srcMat = cv::imread("/Users/xuyishen/Desktop/Imread/test/tu.png");
    uchar threshold = 100;
    int height = srcMat.rows; //行数
     int width = srcMat.cols; //每行元素的总元素数量 for (int j = 0; j<height; j++)
     for (int j=0; j<height; j++){
     for (int i = 0; i<width; i++) {
    uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2])/3;
         if(average>threshold){
             average = 255;
    srcMat.at<Vec3b>(j,i)[0] = average;
    srcMat.at<Vec3b>(j,i)[1] = average;
    srcMat.at<Vec3b>(j,i)[2] = average; //-------------结束像素处理------------------------
         }
         else{
                  average = 0;
         srcMat.at<Vec3b>(j,i)[0] = average;
         srcMat.at<Vec3b>(j,i)[1] = average;
         srcMat.at<Vec3b>(j,i)[2] = average; //-------------结束像素处理------------------------
              }
     }//单行处理结束 }
         
         }
    cv::namedWindow("srcImage");

    
     cv::imshow("srcImage",srcMat);
    waitKey(0);
    return 0;
}

