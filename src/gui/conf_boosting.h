#ifndef CONF_BOOSTING_H
#define CONF_BOOSTING_H

#include <QMainWindow>
#include "gui/mainwindow.h"

namespace Ui {
class Conf_Boosting;
}

class Conf_Boosting : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_Boosting(void *puntero,QWidget *parent = 0);
    ~Conf_Boosting();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Conf_Boosting *ui;
    void *punt;
};

#endif // CONF_BOOSTING_H
