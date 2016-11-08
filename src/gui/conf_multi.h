#ifndef CONF_MULTI_H
#define CONF_MULTI_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "gui/mainwindow.h"
#include "Clasificadores/multiclasificador.h"

using namespace MLT;


namespace Ui {
class Conf_Multi;
}

class Conf_Multi : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_Multi(void *puntero, QWidget *parent = 0);
    ~Conf_Multi();

private slots:
    void on_Anadir_clicked();

    void on_Anadir_2_clicked();

    void on_Cascada_2_clicked();

    void on_Votacion_2_clicked();

    void on_reset_2_clicked();

    void on_Aceptar_2_clicked();

private:
    Ui::Conf_Multi *ui;
    MultiClasificador::Multi_type multi;
    vector<int> id_clasificadores;
    stringstream texto;
    void *punt;
};

#endif // CONF_MULTI_H
