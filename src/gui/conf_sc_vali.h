#ifndef CONF_SC_VALI_H
#define CONF_SC_VALI_H

#include <QMainWindow>
#include "gui/mainwindow.h"

using namespace MLT;


namespace Ui {
class Conf_SC_Vali;
}

class Conf_SC_Vali : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_SC_Vali(void *puntero, QWidget *parent = 0);
    ~Conf_SC_Vali();
    
private slots:
    void on_Iniciar_2_clicked();

private:
    Ui::Conf_SC_Vali *ui;
    void *punt;
    vector<int> id_clasificadores;
};

#endif // CONF_SC_VALI_H
