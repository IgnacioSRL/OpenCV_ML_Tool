#ifndef CONF_KNN_H
#define CONF_KNN_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_KNN;
}

class Conf_KNN : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_KNN(void *puntero, QWidget *parent = 0);
    ~Conf_KNN();
    
private slots:
    void on_Aceptar_clicked();

private:
    Ui::Conf_KNN *ui;
    void *punt;
};

#endif // CONF_KNN_H
