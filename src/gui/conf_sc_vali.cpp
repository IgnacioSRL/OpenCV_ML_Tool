#include "conf_sc_vali.h"
#include "ui_conf_sc_vali.h"

Conf_SC_Vali::Conf_SC_Vali(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conf_SC_Vali)
{
    punt=puntero;
    id_clasificadores.clear();
    ui->setupUi(this);
}

Conf_SC_Vali::~Conf_SC_Vali()
{
    delete ui;
}

void Conf_SC_Vali::on_Iniciar_2_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    if(ui->Distancias->isChecked())
        id_clasificadores.push_back(DISTANCIAS);
    if(ui->GAUSS->isChecked())
        id_clasificadores.push_back(GAUSSIANO);
    if(ui->Histograma->isChecked())
        id_clasificadores.push_back(HISTOGRAMA);
    if(ui->KNN->isChecked())
        id_clasificadores.push_back(KNN);
    if(ui->Neuronal->isChecked())
        id_clasificadores.push_back(NEURONAL);
    if(ui->SVM->isChecked())
        id_clasificadores.push_back(C_SVM);
    if(ui->RTrees->isChecked())
        id_clasificadores.push_back(RTREES);
    if(ui->DTrees->isChecked())
        id_clasificadores.push_back(DTREES);
    if(ui->Boosting->isChecked())
        id_clasificadores.push_back(BOOSTING);
//    if(ui->GBT->isChecked())
//        id_clasificadores.push_back(GBT);
    if(ui->EM->isChecked())
        id_clasificadores.push_back(EXP_MAX);
//    if(ui->ERT->isChecked())
//        id_clasificadores.push_back(ERTREES);
    window->id_clasificadores=id_clasificadores;
    delete this;
}
