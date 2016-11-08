#ifndef CONF_PARAMETROS_H
#define CONF_PARAMETROS_H

#include <QMainWindow>
#include "Herramientas/optimizacion.h"

using namespace MLT;


namespace Ui {
class Conf_Parametros;
}

class Conf_Parametros : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Conf_Parametros(void *puntero, QWidget *parent = 0);
    ~Conf_Parametros();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Conf_Parametros *ui;
    void *punt;
};

#endif // CONF_PARAMETROS_H
