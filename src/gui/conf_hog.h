#ifndef CONF_HOG_H
#define CONF_HOG_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_HOG;
}

class Conf_HOG : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_HOG(void *puntero, QWidget *parent = 0);
    ~Conf_HOG();


private slots:
    void on_Aceptar_clicked();

private:
    Ui::Conf_HOG *ui;
    void *punt;
};

#endif // CONF_HOG_H
