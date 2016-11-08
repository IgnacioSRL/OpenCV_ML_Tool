#ifndef CONF_ERTREES_H
#define CONF_ERTREES_H

#include <QMainWindow>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_ERTrees;
}

class Conf_ERTrees : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_ERTrees(void *puntero,QWidget *parent = 0);
    ~Conf_ERTrees();
    
private slots:
    void on_Aceptar_clicked();

private:
    Ui::Conf_ERTrees *ui;
    void *punt;
};

#endif // CONF_ERTREES_H
