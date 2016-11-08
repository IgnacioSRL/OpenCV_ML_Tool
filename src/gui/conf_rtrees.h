#ifndef CONF_RTREES_H
#define CONF_RTREES_H

#include <QMainWindow>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_RTrees;
}

class Conf_RTrees : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_RTrees(void *puntero, QWidget *parent=0);
    ~Conf_RTrees();
    
private slots:
    void on_Aceptar_clicked();

private:
    Ui::Conf_RTrees *ui;
    void *punt;
};

#endif // CONF_RTREES_H
