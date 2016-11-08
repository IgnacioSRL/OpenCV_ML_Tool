#include "conf_neuronal.h"
#include "ui_conf_neuronal.h"

Conf_neuronal::Conf_neuronal(void *puntero, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conf_neuronal)
{
    punt=puntero;
    ui->setupUi(this);
    ui->rp_dw_min->setValue(FLT_EPSILON);
}

Conf_neuronal::~Conf_neuronal()
{
    delete ui;
}

void Conf_neuronal::on_Aceptar_clicked()
{
    MainWindow *window=(MainWindow*) punt;
    std::string texto=ui->Num_neur->text().toStdString();
    std::vector<int> pos;
    pos.push_back(-1);
    for(uint i=0; i<texto.size(); i++){
        if(texto[i]==',')
            pos.push_back(i);
    }
    pos.push_back(texto.size());
    std::vector<int> num;
    for(uint i=1; i<pos.size(); i++){
        std::string numero;
        for(int j=pos[i-1]+1; j<pos[i]; j++){
            numero=numero+texto[j];
        }
        int n=atoi(numero.c_str());
        num.push_back(n);
    }
    window->Neuronal_layerSize=cv::Mat::zeros(num.size()+2,1,CV_32SC1);
    window->Neuronal_layerSize.row(window->Neuronal_layerSize.rows-1)=1;
    for(int i=1; i<window->Neuronal_layerSize.rows-1; i++)
        window->Neuronal_layerSize.row(i)=cv::Scalar(num[i-1]);
    if(ui->Metodo->currentIndex()==0)
        window->Neuronal_Method=ml::ANN_MLP::BACKPROP;
    else if(ui->Metodo->currentIndex()==1)
        window->Neuronal_Method=ml::ANN_MLP::RPROP;
    if(ui->Funcion->currentIndex()==0)
        window->Neuronal_Function=ml::ANN_MLP::IDENTITY;
    else if(ui->Funcion->currentIndex()==1)
        window->Neuronal_Function=ml::ANN_MLP::SIGMOID_SYM;
    else if(ui->Funcion->currentIndex()==2)
        window->Neuronal_Function=ml::ANN_MLP::GAUSSIAN;
    window->Neuronal_bp_dw_scale=ui->bp_dw_scale->value();
    window->Neuronal_fparam1=ui->fparam1->value();
    window->Neuronal_fparam2=ui->fparam2->value();
    window->Neuronal_rp_dw0=ui->rp_dw0->value();
    window->Neuronal_rp_dw_max=ui->rp_dw_max->value();
    window->Neuronal_rp_dw_min=ui->rp_dw_min->value();
    window->Neuronal_rp_dw_minus=ui->rp_dw_minus->value();
    window->Neuronal_rp_dw_plus=ui->rp_dw_plus->value();
    delete this;
}
