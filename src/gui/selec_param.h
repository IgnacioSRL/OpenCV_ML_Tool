#ifndef SELEC_PARAM_H
#define SELEC_PARAM_H

#include <QMainWindow>
#include "gui/mainwindow.h"

using namespace MLT;


namespace Ui {
class Selec_Param;
}

class Selec_Param : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Selec_Param(void *puntero, QWidget *parent = 0);
    ~Selec_Param();
    
private slots:
    void on_Aceptar_clicked();

private:
    Ui::Selec_Param *ui;
    void *punt;
};

#endif // SELEC_PARAM_H
