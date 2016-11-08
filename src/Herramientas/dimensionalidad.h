#ifndef DIMENSIONALIDAD_H
#define DIMENSIONALIDAD_H

#include <opencv2/opencv.hpp>
#include <Herramientas/auxiliares.h>
#include <Herramientas/generacion.h>

using namespace std;
using namespace cv;

namespace MLT {
    enum
    {
        LDA_DIM=0,
        PCA_DIM=1,
        MAXDIST_DIM=2,
        D_PRIME_DIM=3
    };

    class Dimensionalidad
    {
    public:
        struct Reducciones {
           bool si_lda;
           bool si_pca;
           bool si_dist;
           bool si_d_prime;
           int tam_reduc;
           Mat LDA;
           Mat PCA;
           Mat DS;
           Mat D_PRIME;
           Reducciones(){
               si_lda=false;
               si_pca=false;
               si_dist=false;
               si_d_prime=false;
               tam_reduc=0;
               LDA=Mat();
               PCA=Mat();
               DS=Mat();
               D_PRIME=Mat();
           }
        };

        Dimensionalidad(string Nombre);

        int Reducir(vector<Mat> Imagenes, vector<Mat> &Reducidas, vector<float> Labels, Reducciones reduccion, Generacion::Info_Datos &info, bool save);
        int LDA_matriz(Mat img, std::vector<float> Etiquetas, int tam_final, Mat &lda, bool guardar);
        int PCA_matriz(Mat img, int tam_final, Mat &pca, bool guardar);
        int MaxDist_matriz(Mat img, std::vector<float> Etiquetas, int tam_final, Mat &mat_reduc, bool guardar);
        int D_Prime_matriz(Mat img, std::vector<float> Etiquetas, int tam_final, Mat &mat_reduc, bool guardar);
        int Proyeccion(Mat img, Mat &Proyectada, int tipo, Mat reduc=Mat());
        int Retro_Proyeccion(Mat img, Mat &Proyectada, int tipo);
        int Calidad_dimensiones_distancia(vector<Mat> img, vector<float> Etiquetas, int tipo_reduccion, int dim_max, Mat &Separabilidad, Mat &Separabilidad_acumulada, int &dim_optim);
        int Calidad_dimensiones_d_prime(vector<Mat> img, vector<float> Etiquetas, int tipo_reduccion, int dim_max, Mat &Separabilidad, Mat &Separabilidad_acumulada, int &dim_optim);

        string nombre;
    };
}

#endif // DIMENSIONALIDAD_H
