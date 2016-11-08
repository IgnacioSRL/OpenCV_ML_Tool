#include "conf_knn.h"
#include "ui_conf_knn.h"

Conf_KNN::Conf_KNN(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conf_KNN)
{
    punt=puntero;
    ui->setupUi(this);
}

Conf_KNN::~Conf_KNN()
{
    delete ui;
}

void Conf_KNN::on_Aceptar_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    window->KNN_k=ui->K->value();
    delete this;
}
