#ifndef CONF_DTREES_H
#define CONF_DTREES_H

#include <QMainWindow>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_DTrees;
}

class Conf_DTrees : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_DTrees(void *puntero,QWidget *parent = 0);
    ~Conf_DTrees();
    
private slots:
    void on_Aceptar_clicked();

private:
    Ui::Conf_DTrees *ui;
    void *punt;
};

#endif // CONF_DTREES_H
