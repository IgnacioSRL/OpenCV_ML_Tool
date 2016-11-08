#ifndef DESCRIPTORES_H
#define DESCRIPTORES_H

#include <opencv2/xfeatures2d.hpp>
#include "descriptor.h"

using namespace std;
using namespace cv;

namespace MLT {
    class Puntos_Caracteristicos: public Descriptor{
    public:
        Puntos_Caracteristicos(String DetectorType="SURF", String ExtractorType="SURF", float ParamDetector=1000);
        int Extract(vector<cv::Mat> Images, vector<cv::Mat> &Descriptores);
        void Mostrar(vector<Mat> Images);
    private:
        std::vector< vector<cv::KeyPoint> > keypoints_I;
        cv::String detectorType;
        cv::String extractorType;
        float paramDetector;
    };
}

#endif // DESCRIPTORES_H
