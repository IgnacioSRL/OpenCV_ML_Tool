#include "conf_histograma.h"
#include "ui_conf_histograma.h"

Conf_Histograma::Conf_Histograma(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conf_Histograma)
{
    punt=puntero;
    ui->setupUi(this);
}

Conf_Histograma::~Conf_Histograma()
{
    delete ui;
}

void Conf_Histograma::on_Aceptar_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    window->Hist_tam_celda=ui->Tam_Celda->value();
    delete this;
}
