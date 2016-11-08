#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <opencv2/opencv.hpp>
#include <dirent.h>
#include <iostream>

using namespace std;
using namespace cv;

namespace MLT {
class Auxiliares
    {
    public:
        Auxiliares();
        int numero_imagenes(String input_directory);
        int numero_etiquetas(vector<float> Labels, bool &negativa);
        int Image2Lexic(std::vector<cv::Mat> Imagen, Mat &Datos);
        int Lexic2Image(cv::Mat Datos, Size tam_imagen, int num_channels, std::vector<cv::Mat> &Imagen);
    };
}

#endif // AUXILIARES_H
