#ifndef REPRESENTACION_H
#define REPRESENTACION_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <Herramientas/auxiliares.h>
#include <Herramientas/analisis.h>
#ifdef GUI
#include <QApplication>
#endif

using namespace std;
using namespace cv;

namespace MLT {
class Representacion
    {
    public:
        Representacion();

        int Color(Mat Result_Etiq, vector<cv::Scalar> Colores, Mat &Colored, bool Show);
        int Recuadros(Mat imagen, vector<RotatedRect> recuadros, vector<float> labels_recuadros, vector<Scalar> Colores, Mat &salida, bool show);
        int Data_represent(string nombre,vector<Mat> Data, vector<float> labels, vector<int> dimensions, vector<cv::Scalar> Colores);
        int Ellipse_represent(string nombre,vector<Mat> Data, vector<float> labels, vector<int> dimensions, vector<cv::Scalar> Colores);
        int Data_Ellipse_represent(string nombre,vector<Mat> Data, vector<float> labels, vector<int> dimensions, vector<cv::Scalar> Colores);
        int Continuous_data_represent(string nombre,Mat Data, vector<float> labels, vector<cv::Scalar> Colores);
        int Histogram_represent(string nombre, vector<vector<Mat> > Histograma, vector<cv::Scalar> Colores, int dimension);
        int Imagen(vector<Mat> Imagenes, int numero);
    };
}

#endif // REPRESENTACION_H
