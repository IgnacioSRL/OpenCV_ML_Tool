/*
*
* Copyright 2014-2016 Ignacio San Roman Lana
*
* This file is part of OpenCV_ML_Tool
*
* OpenCV_ML_Tool is free software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* OpenCV_ML_Tool is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with OpenCV_ML_Tool. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by this license please contact with
* isanromanlana@gmail.com
*/

#ifndef CLASIFICADOR_DISTANCIAS_H
#define CLASIFICADOR_DISTANCIAS_H

#include "clasificador.h"

using namespace std;
using namespace cv;

namespace MLT {
    class Clasificador_Distancias: public Clasificador{
    public:
        Clasificador_Distancias(string Nombre="");
        ~Clasificador_Distancias();
        int Parametrizar();
        int Autotrain(vector<Mat> Data, vector<float> Labels, Dimensionalidad::Reducciones reduc, Generacion::Info_Datos info, bool save=true);
        int Autoclasificacion(vector<Mat> Data, vector<float> &Labels, bool reducir, bool read);
        int Save_Data();
        int Read_Data();

    private:

        struct Distancias {
           vector<Mat> Medias;
           vector<float> Etiquetas;
        } DIST;

        void Entrenamiento(Mat trainingDataMat, Mat labelsMat);
        float Clasificacion(Mat Data);

        Dimensionalidad::Reducciones reduccion;
    };
}

#endif // CLASIFICADOR_DISTANCIAS_H
