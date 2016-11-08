#ifndef CON_MULTI_H
#define CON_MULTI_H

#include <QMainWindow>
#include <Clasificadores/multiclasificador.h>
#include <QFileDialog>
#include <QMessageBox>
#include "gui/mainwindow.h"

using namespace MLT;

namespace Ui {
class Con_Multi;
}

class Con_Multi : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Con_Multi(void *puntero, QWidget *parent = 0);
    ~Con_Multi();
    
private slots:
    void on_Anadir_clicked();

    void on_Anadir_2_clicked();

    void on_Cascada_clicked();

    void on_Votacion_clicked();

    void on_toolButton_clicked();

    void on_reset_clicked();

    void on_Aceptar_clicked();

private:
    Ui::Con_Multi *ui;
    MultiClasificador::Multi_type multi;
    vector<int> id_clasificadores;
    vector<string> nombres;
    stringstream texto;
    void *punt;
};

#endif // CON_MULTI_H
