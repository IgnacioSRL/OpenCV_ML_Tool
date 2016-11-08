#ifndef CONF_SVM_H
#define CONF_SVM_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_SVM;
}

class Conf_SVM : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_SVM(void *puntero, QWidget *parent = 0);
    ~Conf_SVM();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Conf_SVM *ui;
    void *punt;
};

#endif // CONF_SVM_H
