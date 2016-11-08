#ifndef CONF_EM_H
#define CONF_EM_H

#include <QMainWindow>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_EM;
}

class Conf_EM : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_EM(void *puntero, QWidget *parent = 0);
    ~Conf_EM();
    
private slots:
    void on_Aceptar_clicked();

private:
    Ui::Conf_EM *ui;
    void *punt;
};

#endif // CONF_EM_H
