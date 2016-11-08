#include "conf_ertrees.h"
#include "ui_conf_ertrees.h"

Conf_ERTrees::Conf_ERTrees(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conf_ERTrees)
{
    punt=puntero;
    ui->setupUi(this);
}

Conf_ERTrees::~Conf_ERTrees()
{
    delete ui;
}

void Conf_ERTrees::on_Aceptar_clicked()
{
    MainWindow *window=(MainWindow*) punt;
//    window->ERTrees_priors=0;
//    window->ERTrees_calc_var_importance=ui->calc_var_importance->isChecked();
//    window->ERTrees_cv_folds=ui->cv_folds->value();
//    window->ERTrees_max_categories=ui->max_categories->value();
//    window->ERTrees_max_depth=ui->max_depth->value();
//    window->ERTrees_min_sample_count=ui->min_sample_count->value();
//    window->ERTrees_native_vars=ui->native_vars->value();
//    window->ERTrees_regression_accuracy=ui->regression_accuracy->value();
//    window->ERTrees_truncate_pruned_tree=ui->truncate_pruned_tree->isChecked();
//    window->ERTrees_use_1se_rule=ui->use_1se_rule->isChecked();
//    window->ERTrees_use_surrogates=ui->use_surrogates->isChecked();
    delete this;
}
