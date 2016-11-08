#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

#include <iostream>
#include <opencv2/opencv.hpp>

namespace MLT {
enum{
    RGB=0,
    GRAY=1,
    HOG_DES=2,
    PUNTOS_CARACTERISTICOS=3,
    THRESHOLD=4,
    CANNY=5,
    SOBEL=6,
    HSV=7,
    H_CHANNEL=8,
    S_CHANNEL=9,
    V_CHANNEL=10,
    COLOR_PREDOMINANTE
};
    class Descriptor{
    public:
        Descriptor(){}
        int virtual Extract(std::vector<cv::Mat> Images, std::vector<cv::Mat> &Descriptors){}
    };
}

#endif // DESCRIPTOR_H
