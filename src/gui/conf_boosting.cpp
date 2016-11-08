#include "conf_boosting.h"
#include "ui_conf_boosting.h"

Conf_Boosting::Conf_Boosting(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conf_Boosting)
{
    punt=puntero;
    ui->setupUi(this);
}

Conf_Boosting::~Conf_Boosting()
{
    delete ui;
}

void Conf_Boosting::on_pushButton_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    window->Boosting_priors=0;
    if(ui->boost_type->currentIndex()==0)
        window->Boosting_boost_type=ml::Boost::DISCRETE;
    else if(ui->boost_type->currentIndex()==1)
        window->Boosting_boost_type=ml::Boost::REAL;
    else if(ui->boost_type->currentIndex()==2)
        window->Boosting_boost_type=ml::Boost::LOGIT;
    else if(ui->boost_type->currentIndex()==3)
        window->Boosting_boost_type=ml::Boost::GENTLE;
    window->Boosting_max_depth=ui->max_depth->value();
    window->Boosting_use_surrogates=ui->use_surrogates->isChecked();
    window->Boosting_weak_count=ui->weak_count->value();
    window->Boosting_weight_trim_rate=ui->weight_trim_rate->value();
    delete this;
}
