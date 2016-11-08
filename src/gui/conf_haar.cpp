#include "conf_haar.h"
#include "ui_conf_haar.h"

Conf_HAAR::Conf_HAAR(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conf_HAAR)
{
    punt=puntero;
    ui->setupUi(this);
}

Conf_HAAR::~Conf_HAAR()
{
    delete ui;
}

void Conf_HAAR::on_pushButton_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    window->Cascada_NumPos=ui->Positivos->value();
    window->Cascada_NumNeg=ui->Negativos->value();
    window->Cascada_Mode=ui->Modo->currentText().toStdString();
    window->Cascada_NumStage=ui->Etapas->value();
    window->Cascada_MinHitRate=ui->MinHitRate->value();
    window->Cascada_MaxFalseAlarmRate=ui->MaxFalseAlarmRate->value();
    window->Cascada_WeightTrimRate=ui->WeightTrimRate->value();
    window->Cascada_MaxWeakCount=ui->MaxWeakCount->value();
    window->Cascada_MaxDepth=ui->MaxDepth->value();
    window->Cascada_Bt=ui->Bt->currentText().toStdString();
    window->Cascada_PrecalcValBufSize=ui->PrecalcValBufSize->value();
    window->Cascada_PrecalcidxBufSize=ui->PrecalcidxBufSize->value();
    window->si_entrenar=!ui->Entrenar->isChecked();
    delete this;
}
