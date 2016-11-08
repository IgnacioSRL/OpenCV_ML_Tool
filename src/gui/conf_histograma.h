#ifndef CONF_HISTOGRAMA_H
#define CONF_HISTOGRAMA_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_Histograma;
}

class Conf_Histograma : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_Histograma(void *puntero, QWidget *parent = 0);
    ~Conf_Histograma();
    
private slots:
    void on_Aceptar_clicked();

private:
    Ui::Conf_Histograma *ui;
    void *punt;
};

#endif // CONF_HISTOGRAMA_H
