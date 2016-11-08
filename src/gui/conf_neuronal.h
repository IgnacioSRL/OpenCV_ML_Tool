#ifndef CONF_NEURONAL_H
#define CONF_NEURONAL_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_neuronal;
}

class Conf_neuronal : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_neuronal(void *puntero, QWidget *parent = 0);
    ~Conf_neuronal();
    
private slots:
    void on_Aceptar_clicked();

private:
    Ui::Conf_neuronal *ui;
    void *punt;
};

#endif // CONF_NEURONAL_H
