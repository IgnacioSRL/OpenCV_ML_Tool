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

#include "clasificador_distancias.h"

MLT::Clasificador_Distancias::Clasificador_Distancias(string Nombre)
{
    nombre=Nombre;
    tipo_clasificador=DISTANCIAS;
}

MLT::Clasificador_Distancias::~Clasificador_Distancias(){
}

int MLT::Clasificador_Distancias::Parametrizar(){
    return 0;
}

int MLT::Clasificador_Distancias::Autotrain(vector<Mat> Data, vector<float> Labels, Dimensionalidad::Reducciones reduc, Generacion::Info_Datos info, bool save){
    int e=0;
    if(Data.size()==0){
        cout<<"ERROR en Autotrain: No hay datos"<<endl;
        return 1;
    }
    if(Labels.size()==0){
        cout<<"ERROR en Autotrain: No hay Etiquetas"<<endl;
        return 1;
    }
    if(Data.size()!=Labels.size()){
        cout<<"ERROR en Autotrain: Numero de datos y etiquetas distinto"<<endl;
        return 1;
    }
    if((reduc.si_dist&&(reduc.si_pca||reduc.si_lda||reduc.si_d_prime))||
            (reduc.si_d_prime&&(reduc.si_pca||reduc.si_lda||reduc.si_dist))||
            (reduc.si_pca&&(reduc.si_dist||reduc.si_lda||reduc.si_d_prime))||
            (reduc.si_lda&&(reduc.si_pca||reduc.si_dist||reduc.si_d_prime))){
        cout<<"ERROR en Autotrain: Solo puede haber un metodo de reduccion de dimensionalidad activado"<<endl;
        return 1;
    }
    if((reduc.si_lda || reduc.si_pca || reduc.si_dist || reduc.si_d_prime) && reduc.tam_reduc<=0){
        cout<<"ERROR en Autotrain: si_lda=true o si_pca=true o si_dist=true o si_d_prime=true pero t_reduc es igual o menor a 0"<<endl;
        return 1;
    }
    ventana_o_x=info.Tam_Orig_X;
    ventana_o_y=info.Tam_Orig_Y;
    ventana_x=info.Tam_X;
    ventana_y=info.Tam_Y;
    tipo_dato=info.Tipo_Datos;
    if((reduc.si_dist==true || reduc.si_d_prime==true || reduc.si_lda==true || reduc.si_pca==true)&&(info.si_dist==true || info.si_d_prime==true || info.si_lda==true || info.si_pca==true)){
        cout<<"ERROR en Autotrain: Ya se le ha hecho una reduccion anteriormente a los datos"<<endl;
        return 1;
    }
    reduccion=reduc;
    Auxiliares ax;
    bool negativa;
    numero_etiquetas=ax.numero_etiquetas(Labels,negativa);
    Mat lexic_data;
    e=ax.Image2Lexic(Data,lexic_data);
    if(e==1){
        cout<<"ERROR en Autorain: Error en Image2Lexic"<<endl;
        return 1;
    }
    Mat lexic_labels(Labels.size(), 1, CV_32FC1, Labels.data());
    lexic_data.convertTo(lexic_data,CV_32FC1);
    lexic_labels.convertTo(lexic_labels,CV_32FC1);
    Mat trainingDataMat;
    if(reduccion.si_lda){
        Dimensionalidad dim(nombre);
        e=dim.LDA_matriz(lexic_data,Labels,reduccion.tam_reduc,reduccion.LDA,save);
        if(e==1){
            cout<<"ERROR en Autotrain: Error en LDA_matriz"<<endl;
            return 1;
        }
        Mat Proyectada;
        e=dim.Proyeccion(lexic_data,Proyectada,LDA_DIM,reduccion.LDA);
        if(e==1){
            cout<<"ERROR en Autotrain: Error en Proyeccion"<<endl;
            return 1;
        }
        Proyectada.copyTo(trainingDataMat);
    }
    else if(reduccion.si_pca){
        Dimensionalidad dim(nombre);
        e=dim.PCA_matriz(lexic_data,reduccion.tam_reduc,reduccion.PCA,save);
        if(e==1){
            cout<<"ERROR en Autotrain: Error en PCA_matriz"<<endl;
            return 1;
        }
        Mat Proyectada;
        e=dim.Proyeccion(lexic_data,Proyectada,PCA_DIM,reduccion.PCA);
        if(e==1){
            cout<<"ERROR en Autotrain: Error en Proyeccion"<<endl;
            return 1;
        }
        Proyectada.copyTo(trainingDataMat);
    }
    else if(reduccion.si_dist){
        Dimensionalidad dim(nombre);
        e=dim.MaxDist_matriz(lexic_data,Labels,reduccion.tam_reduc,reduccion.DS,save);
        if(e==1){
            cout<<"ERROR en Autotrain: Error en MaxDist_matriz"<<endl;
            return 1;
        }
        Mat Proyectada;
        e=dim.Proyeccion(lexic_data,Proyectada,MAXDIST_DIM,reduccion.DS);
        if(e==1){
            cout<<"ERROR en Autotrain: Error en Proyeccion"<<endl;
            return 1;
        }
        Proyectada.copyTo(trainingDataMat);
    }
    else if(reduccion.si_d_prime){
        Dimensionalidad dim(nombre);
        e=dim.D_Prime_matriz(lexic_data,Labels,reduccion.tam_reduc,reduccion.D_PRIME,save);
        if(e==1){
            cout<<"ERROR en Autotrain: Error en D_PRIME_matriz"<<endl;
            return 1;
        }
        Mat Proyectada;
        e=dim.Proyeccion(lexic_data,Proyectada,D_PRIME_DIM,reduccion.D_PRIME);
        if(e==1){
            cout<<"ERROR en Autotrain: Error en Proyeccion"<<endl;
            return 1;
        }
        Proyectada.copyTo(trainingDataMat);
    }
    else
        lexic_data.copyTo(trainingDataMat);
    Entrenamiento(trainingDataMat, lexic_labels);
    if(reduc.si_dist==false && reduc.si_d_prime==false && reduc.si_lda==false && reduc.si_pca==false){
        reduccion.si_dist=info.si_dist;
        reduccion.si_d_prime=info.si_d_prime;
        reduccion.si_lda=info.si_lda;
        reduccion.si_pca=info.si_pca;
        reduccion.DS=info.DS;
        reduccion.D_PRIME=info.D_PRIME;
        reduccion.LDA=info.LDA;
        reduccion.PCA=info.PCA;
        reduccion.tam_reduc=info.Tam_X*info.Tam_Y;
    }
    if(save){
        e=Save_Data();
        if(e==1){
            cout<<"ERROR en Autotrain: Error en Save_Data"<<endl;
            return 1;
        }
    }
    return 0;
}

int MLT::Clasificador_Distancias::Autoclasificacion(vector<Mat> Data, vector<float> &Labels, bool reducir, bool read){
    int e=0;
    if(read){
        e=Read_Data();
        if(e==1){
            cout<<"ERROR en Autoclasificacion: Error en Read_Data"<<endl;
            return 1;
        }
    }
    Auxiliares ax;
    Mat lexic_data;
    e=ax.Image2Lexic(Data,lexic_data);
    if(e==1){
        cout<<"ERROR en Autoclasificacion: Error en Image2Lexic"<<endl;
        return 1;
    }
    Mat trainingDataMat;
    if(reducir){
        if(reduccion.si_lda){
            Dimensionalidad dim(nombre);
            Mat Proyectada;
            e=dim.Proyeccion(lexic_data,Proyectada,LDA_DIM,reduccion.LDA);
            if(e==1){
                cout<<"ERROR en Autoclasificacion: Error en Proyeccion"<<endl;
                return 1;
            }
            Proyectada.copyTo(trainingDataMat);
        }
        else if(reduccion.si_pca){
            Dimensionalidad dim(nombre);
            Mat Proyectada;
            e=dim.Proyeccion(lexic_data,Proyectada,PCA_DIM,reduccion.PCA);
            if(e==1){
                cout<<"ERROR en Autoclasificacion: Error en Proyeccion"<<endl;
                return 1;
            }
            Proyectada.copyTo(trainingDataMat);
        }
        else if(reduccion.si_dist){
            Dimensionalidad dim(nombre);
            Mat Proyectada;
            e=dim.Proyeccion(lexic_data,Proyectada,MAXDIST_DIM,reduccion.DS);
            if(e==1){
                cout<<"ERROR en Autoclasificacion: Error en Proyeccion"<<endl;
                return 1;
            }
            Proyectada.copyTo(trainingDataMat);
        }
        else if(reduccion.si_d_prime){
            Dimensionalidad dim(nombre);
            Mat Proyectada;
            e=dim.Proyeccion(lexic_data,Proyectada,D_PRIME_DIM,reduccion.D_PRIME);
            if(e==1){
                cout<<"ERROR en Autoclasificacion: Error en Proyeccion"<<endl;
                return 1;
            }
            Proyectada.copyTo(trainingDataMat);
        }
        else
            lexic_data.copyTo(trainingDataMat);
    }
    else
        lexic_data.copyTo(trainingDataMat);
    for(int i=0; i<trainingDataMat.rows; i++){
        float response=Clasificacion(trainingDataMat.row(i));
        Labels.push_back(response);
#ifdef GUI
            progreso++;
            window->progress_Clasificar->setValue(base_progreso+(max_progreso*progreso/total_progreso));
#endif
    }
    return 0;
}

void MLT::Clasificador_Distancias::Entrenamiento(Mat trainingDataMat, Mat labelsMat){
    trainingDataMat.convertTo(trainingDataMat,CV_32FC1);
    labelsMat.convertTo(labelsMat,CV_32FC1);
    bool neg=false;
    int num_etiq=0;
    for(int i=0; i<labelsMat.rows; i++){
        if(labelsMat.at<float>(i,0)<0)
            neg=true;
        if(num_etiq<labelsMat.at<float>(i,0))
            num_etiq=labelsMat.at<float>(i,0);
    }
    if(neg)
        num_etiq=num_etiq+1;
    vector<int> num(num_etiq);
    for(uint i=0; i<num.size(); i++)
        num[i]=0;
    for(int i=0; i<labelsMat.rows; i++){
        if(neg && labelsMat.at<float>(i,0)==-1)
            num[0]++;
        else if(neg && labelsMat.at<float>(i,0)!=-1)
            num[labelsMat.at<float>(i,0)]++;
        else
            num[labelsMat.at<float>(i,0)-1]++;
    }
    vector<Mat> Medias;
    for(int i=0; i<num_etiq; i++){
        Mat Zeros=Mat::zeros(1,trainingDataMat.cols,CV_32FC1);
        Medias.push_back(Zeros);
    }
    for(int i=0; i<trainingDataMat.rows; i++){
        if(neg && labelsMat.at<float>(i,0)==-1)
            Medias[0]=Medias[0]+trainingDataMat.row(i);
        else if(neg && labelsMat.at<float>(i,0)!=-1)
            Medias[labelsMat.at<float>(i,0)]=Medias[labelsMat.at<float>(i,0)]+trainingDataMat.row(i);
        else
            Medias[labelsMat.at<float>(i,0)-1]=Medias[labelsMat.at<float>(i,0)-1]+trainingDataMat.row(i);
    }
    for(uint i=0; i<Medias.size(); i++)
        Medias[i]=Medias[i]/num[i];
    DIST.Medias=Medias;

    if(neg){
        DIST.Etiquetas.push_back(-1);
        for(uint i=1; i<Medias.size(); i++)
            DIST.Etiquetas.push_back(i);
    }
    else
        for(uint i=1; i<Medias.size()+1; i++)
            DIST.Etiquetas.push_back(i);
}

float MLT::Clasificador_Distancias::Clasificacion(Mat Data){
    Data.convertTo(Data,CV_32FC1);
    float response=0;
    vector<float> distancias;
    for(uint i=0; i<DIST.Medias.size(); i++)
        distancias.push_back(0);
    for(uint i=0; i<distancias.size(); i++){
        Mat cuadrada;
        cv::pow(Data.row(0)-DIST.Medias[i].row(0),2,cuadrada);
        Scalar d=sum(cuadrada);
        float dist=sqrt(d[0]);
        distancias[i]=dist;
    }
    float minima=99999999;
    int pos=-1;
    for(uint i=0; i<distancias.size(); i++){
        if(distancias[i]<minima){
            minima=distancias[i];
            pos=i;
        }
    }
    if(pos<0)
        response=0;
    else
        response=DIST.Etiquetas[pos];
    return response;
}


int MLT::Clasificador_Distancias::Save_Data(){
    DIR    *dir_p = opendir ("../Data/Configuracion");
    if(dir_p == NULL) {
        string command = "mkdir ../Data/Configuracion";
        int er=system(command.c_str());
        if(er!=0){
            cout<<"ERROR en Read_Data: Error al crear carpeta"<<endl;
            return 1;
        }
    }
    String dir="../Data/Configuracion/"+nombre;
    DIR    *dir_p2 = opendir (dir.c_str());
    if(dir_p2 == NULL) {
        string command = "mkdir "+dir;
        int er=system(command.c_str());
        if(er!=0){
            cout<<"ERROR en Read_Data: Error al crear carpeta"<<endl;
            return 1;
        }
    }
    string g="../Data/Configuracion/"+nombre+"/DIST2.xml";
    cv::FileStorage archivo_w(g,CV_STORAGE_WRITE);
    if(archivo_w.isOpened()){
        archivo_w<<"ventana_x"<<ventana_x;
        archivo_w<<"ventana_y"<<ventana_y;
        archivo_w<<"ventana_o_x"<<ventana_o_x;
        archivo_w<<"ventana_o_y"<<ventana_o_y;
        archivo_w<<"numero_etiquetas"<<numero_etiquetas;
        archivo_w<<"tipo_dato"<<tipo_dato;
        archivo_w<<"tam_reduc"<<reduccion.tam_reduc;
        archivo_w<<"lda"<<reduccion.si_lda;
        archivo_w<<"LDA"<<reduccion.LDA;
        archivo_w<<"pca"<<reduccion.si_pca;
        archivo_w<<"Pca"<<reduccion.PCA;
        archivo_w<<"dist"<<reduccion.si_dist;
        archivo_w<<"DS"<<reduccion.DS;
    }
    else
        return 1;
    archivo_w.release();
    g="../Data/Configuracion/"+nombre+"/DIST.xml";
    cv::FileStorage archivo_w2(g,CV_STORAGE_WRITE);
    if(archivo_w2.isOpened()){
        archivo_w2<<"Medias"<<DIST.Medias;
        archivo_w2<<"Etiquetas"<<DIST.Etiquetas;
    }
    else
        return 1;
    archivo_w2.release();
    g="../Data/Configuracion/"+nombre+"/Clasificador.xml";
    cv::FileStorage clas(g,CV_STORAGE_WRITE);
    if(clas.isOpened()){
        int id=DISTANCIAS;
        clas<<"Tipo"<<id;
    }
    else
        return 1;
    clas.release();
    return 0;
}

int MLT::Clasificador_Distancias::Read_Data(){
    string g="../Data/Configuracion/"+nombre+"/DIST2.xml";
    cv::FileStorage archivo_r(g,CV_STORAGE_READ);
    if(archivo_r.isOpened()){
        archivo_r["ventana_x"]>>ventana_x;
        archivo_r["ventana_y"]>>ventana_y;
        archivo_r["ventana_o_x"]>>ventana_o_x;
        archivo_r["ventana_o_y"]>>ventana_o_y;
        archivo_r["numero_etiquetas"]>>numero_etiquetas;
        archivo_r["tipo_dato"]>>tipo_dato;
        archivo_r["tam_reduc"]>>reduccion.tam_reduc;
        archivo_r["lda"]>>reduccion.si_lda;
        archivo_r["LDA"]>>reduccion.LDA;
        archivo_r["pca"]>>reduccion.si_pca;
        archivo_r["Pca"]>>reduccion.PCA;
        archivo_r["dist"]>>reduccion.si_dist;
        archivo_r["DS"]>>reduccion.DS;
    }
    else
        return 1;
    archivo_r.release();
    g="../Data/Configuracion/"+nombre+"/DIST.xml";
    cv::FileStorage archivo_r2(g,CV_STORAGE_READ);
    if(archivo_r2.isOpened()){
        archivo_r2["Medias"]>>DIST.Medias;
        archivo_r2["Etiquetas"]>>DIST.Etiquetas;
    }
    else
        return 1;
    archivo_r2.release();
    return 0;
}
