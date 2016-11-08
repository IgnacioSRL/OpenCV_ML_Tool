#include "conf_em.h"
#include "ui_conf_em.h"

Conf_EM::Conf_EM(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conf_EM)
{
    punt=puntero;
    ui->setupUi(this);
}

Conf_EM::~Conf_EM()
{
    delete ui;
}

void Conf_EM::on_Aceptar_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    if(ui->Tipo_Cov->currentIndex()==0)
        window->EM_covMatType=ml::EM::COV_MAT_SPHERICAL;
    if(ui->Tipo_Cov->currentIndex()==1)
        window->EM_covMatType=ml::EM::COV_MAT_DIAGONAL;
    if(ui->Tipo_Cov->currentIndex()==2)
        window->EM_covMatType=ml::EM::COV_MAT_GENERIC;
    window->EM_nclusters=ui->Num_Clus->value();
    delete this;
}
