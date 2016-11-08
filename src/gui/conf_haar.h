#ifndef CONF_HAAR_H
#define CONF_HAAR_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_HAAR;
}

class Conf_HAAR : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_HAAR(void *puntero, QWidget *parent = 0);
    ~Conf_HAAR();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Conf_HAAR *ui;
    void *punt;
};

#endif // CONF_HAAR_H
