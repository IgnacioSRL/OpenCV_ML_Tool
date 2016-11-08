#include "selec_param.h"
#include "ui_selec_param.h"

Selec_Param::Selec_Param(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Selec_Param)
{
    punt=puntero;
    ui->setupUi(this);
}

Selec_Param::~Selec_Param()
{
    delete ui;
}

void Selec_Param::on_Aceptar_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    if(ui->Boosting_max_depth->isChecked())
        window->parametro="Boosting_max_depth";
    if(ui->Boosting_weak_count->isChecked())
        window->parametro="Boosting_weak_count";
    if(ui->DTrees_cv_folds->isChecked())
        window->parametro="DTrees_cv_folds";
    if(ui->DTrees_max_categories->isChecked())
        window->parametro="DTrees_max_categories";
    if(ui->DTrees_max_depth->isChecked())
        window->parametro="DTrees_max_depth";
    if(ui->DTrees_min_sample_count->isChecked())
        window->parametro="DTrees_min_sample_count";
    if(ui->DTrees_regression_accuracy->isChecked())
        window->parametro="DTrees_regression_accuracy";
    if(ui->EM_nclusters->isChecked())
        window->parametro="EM_nclusters";
    if(ui->Hist_tam_celda->isChecked())
        window->parametro="Hist_tam_celda";
    if(ui->KNN_k->isChecked())
        window->parametro="KNN_k";
    if(ui->Neuronal_bp_dw_scale->isChecked())
        window->parametro="Neuronal_bp_dw_scale";
    if(ui->Neuronal_bp_moment_scale->isChecked())
        window->parametro="Neuronal_bp_moment_scale";
    if(ui->Neuronal_fparam1->isChecked())
        window->parametro="Neuronal_fparam1";
    if(ui->Neuronal_fparam2->isChecked())
        window->parametro="Neuronal_fparam2";
    if(ui->Neuronal_rp_dw0->isChecked())
        window->parametro="Neuronal_rp_dw0";
    if(ui->Neuronal_rp_dw_max->isChecked())
        window->parametro="Neuronal_rp_dw_max";
    if(ui->Neuronal_rp_dw_min->isChecked())
        window->parametro="Neuronal_rp_dw_min";
    if(ui->Neuronal_rp_dw_minus->isChecked())
        window->parametro="Neuronal_rp_dw_minus";
    if(ui->Neuronal_rp_dw_plus->isChecked())
        window->parametro="Neuronal_rp_dw_plus";
    if(ui->RTrees_cv_folds->isChecked())
        window->parametro="RTrees_cv_folds";
    if(ui->RTrees_max_categories->isChecked())
        window->parametro="RTrees_max_categories";
    if(ui->RTrees_max_depth->isChecked())
        window->parametro="RTrees_max_depth";
    if(ui->RTrees_min_sample_count->isChecked())
        window->parametro="RTrees_min_sample_count";
    if(ui->RTrees_native_vars->isChecked())
        window->parametro="RTrees_native_vars";
    if(ui->RTrees_regression_accuracy->isChecked())
        window->parametro="RTrees_regression_accuracy";
    if(ui->SVM_C->isChecked())
        window->parametro="SVM_C";
    if(ui->SVM_coef0->isChecked())
        window->parametro="SVM_coef0";
    if(ui->SVM_degree->isChecked())
        window->parametro="SVM_degree";
    if(ui->SVM_gamma->isChecked())
        window->parametro="SVM_gamma";
    if(ui->SVM_nu->isChecked())
        window->parametro="SVM_nu";
    if(ui->SVM_p->isChecked())
        window->parametro="SVM_p";
//    if(ui->ERTrees_cv_folds->isChecked())
//        window->parametro="ERTrees_cv_folds";
//    if(ui->ERTrees_max_categories->isChecked())
//        window->parametro="ERTrees_max_categories";
//    if(ui->ERTrees_max_depth->isChecked())
//        window->parametro="ERTrees_max_depth";
//    if(ui->ERTrees_min_sample_count->isChecked())
//        window->parametro="ERTrees_min_sample_count";
//    if(ui->ERTrees_native_vars->isChecked())
//        window->parametro="ERTrees_native_vars";
//    if(ui->ERTrees_regression_accuracy->isChecked())
//        window->parametro="ERTrees_regression_accuracy";
//    if(ui->GBT_max_depth->isChecked())
//        window->parametro="GBT_max_depth";
//    if(ui->GBT_shrinkage->isChecked())
//        window->parametro="GBT_shrinkage";
//    if(ui->GBT_weak_count->isChecked())
//    window->parametro="GBT_weak_count";
    window->X=ui->X->currentIndex();
    window->Y=ui->Y->currentIndex();
    delete this;
}
