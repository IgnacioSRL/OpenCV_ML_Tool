#ifndef CONFIG_PC_H
#define CONFIG_PC_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "gui/mainwindow.h"

namespace Ui {
class Config_PC;
}

class Config_PC : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Config_PC(void *puntero, QWidget *parent = 0);
    ~Config_PC();

private slots:
    void on_Aceptar_clicked();

private:
    Ui::Config_PC *ui;
    void *punt;
};

#endif // CONFIG_PC_H
