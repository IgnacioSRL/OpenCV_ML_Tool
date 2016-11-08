#ifndef CLUSTERING_H
#define CLUSTERING_H

#include <opencv2/opencv.hpp>
#include <Herramientas/auxiliares.h>

using namespace std;
using namespace cv;

namespace MLT {
    class Clustering
    {
    public:
        Clustering();
        ~Clustering();

        int K_mean(vector<Mat> Data, int K, vector<float> &Labels, Mat &Centers, int attempts=5, int inicializacion=0);
        int Min_Max(vector<Mat> Data, float max_dist, vector<float> &Labels, Mat &Centers);
        int Distancias_Encadenadas(vector<Mat> Data, float max_dist, vector<float> &Labels, Mat &Centers);
        int Histograma(vector<Mat> Data, float tam_celda, vector<float> &Labels, Mat &Centers);
        int EXP_MAX(vector<Mat> Data, vector<float> &Labelsint, Mat &Centers, int nclusters=ml::EM::DEFAULT_NCLUSTERS, int covMatType=ml::EM::COV_MAT_DIAGONAL);
    };
}

#endif // CLUSTERING_H
