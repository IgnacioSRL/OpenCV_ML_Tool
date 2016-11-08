#include "conf_hog.h"
#include "ui_conf_hog.h"

Conf_HOG::Conf_HOG(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conf_HOG)
{
    punt=puntero;
    ui->setupUi(this);
}

Conf_HOG::~Conf_HOG()
{
    delete ui;
}

void Conf_HOG::on_Aceptar_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    window->Win_Size.width=ui->Win_Size_X->value();
    window->Win_Size.height=ui->Win_Size_Y->value();
    window->Block_Stride.width=ui->Block_Stride_X->value();
    window->Block_Stride.height=ui->Block_Stride_Y->value();
    window->Win_Sigma=ui->Sigma->value();
    window->Threshold_L2hys=ui->Threshold->value();
    window->Gamma_Correction=ui->Gamma->isChecked();
    window->Nlevels=ui->NLevels->value();
    delete this;
}
