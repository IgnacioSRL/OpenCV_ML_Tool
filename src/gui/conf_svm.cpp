#include "conf_svm.h"
#include "ui_conf_svm.h"

Conf_SVM::Conf_SVM(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conf_SVM)
{
    punt=puntero;
    ui->setupUi(this);
}

Conf_SVM::~Conf_SVM()
{
    delete ui;
}

void Conf_SVM::on_pushButton_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    if(ui->Train->currentIndex()==0)
        window->SVM_train=TRAIN;
    else if(ui->Train->currentIndex()==1)
        window->SVM_train=TRAIN_AUTO;
    if(ui->Tipo_SVM->currentIndex()==0)
        window->SVM_Type=ml::SVM::C_SVC;
    else if(ui->Tipo_SVM->currentIndex()==1)
        window->SVM_Type=ml::SVM::NU_SVC;
    else if(ui->Tipo_SVM->currentIndex()==2)
        window->SVM_Type=ml::SVM::ONE_CLASS;
    else if(ui->Tipo_SVM->currentIndex()==3)
        window->SVM_Type=ml::SVM::EPS_SVR;
    else if(ui->Tipo_SVM->currentIndex()==4)
        window->SVM_Type=ml::SVM::NU_SVR;
    if(ui->Kernel->currentIndex()==0)
        window->SVM_kernel_type=ml::SVM::LINEAR;
    else if(ui->Kernel->currentIndex()==1)
        window->SVM_kernel_type=ml::SVM::POLY;
    else if(ui->Kernel->currentIndex()==2)
        window->SVM_kernel_type=ml::SVM::RBF;
    else if(ui->Kernel->currentIndex()==3)
        window->SVM_kernel_type=ml::SVM::SIGMOID;
    window->SVM_degree=(double)ui->Degree->value();
    window->SVM_gamma=(double)ui->Gamma->value();
    window->SVM_coef0=(double)ui->Coef0->value();
    window->SVM_C=(double)ui->C->value();
    window->SVM_nu=(double)ui->nu->value();
    window->SVM_p=(double)ui->p->value();
    delete this;
}
