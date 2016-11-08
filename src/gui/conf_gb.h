#ifndef CONF_GB_H
#define CONF_GB_H

#include <QMainWindow>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_GB;
}

class Conf_GB : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_GB(void *puntero, QWidget *parent = 0);
    ~Conf_GB();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Conf_GB *ui;
    void *punt;
};

#endif // CONF_GB_H
