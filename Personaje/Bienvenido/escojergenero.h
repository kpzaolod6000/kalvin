#ifndef ESCOJERGENERO_H
#define ESCOJERGENERO_H

#include <QDialog>
#include "escojermasculino.h"
#include "escojerfemenina.h"

namespace Ui {
class EscojerGenero;
}

class EscojerGenero : public QDialog
{
    Q_OBJECT

public:
    explicit EscojerGenero(QWidget *parent = nullptr);
    ~EscojerGenero();
signals:
    void back();
private slots:
    void on_pushButton_atraslogin_clicked();

    void on_pushButton_varon_clicked();

    void on_pushButton_mujer_clicked();

    void esconder();
    void esconder2();

private:
    Ui::EscojerGenero *ui;
    EscojerMasculino *ventana;
    Escojerfemenina* ventana2;
};

#endif // ESCOJERGENERO_H
