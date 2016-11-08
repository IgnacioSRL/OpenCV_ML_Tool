#include "config_pc.h"
#include "ui_config_pc.h"

Config_PC::Config_PC(void *puntero,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Config_PC)
{
    punt=puntero;
    ui->setupUi(this);
}

Config_PC::~Config_PC()
{
    delete ui;
}

void Config_PC::on_Aceptar_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    QString descriptor,detector;
    descriptor=ui->Descriptor->currentText();
    detector=ui->Detector->currentText();
    window->Tipo_Des=descriptor.toStdString();
    window->Tipo_Ext=detector.toStdString();
    window->Parametro=(float)ui->Parametro->value();
    delete this;
}
