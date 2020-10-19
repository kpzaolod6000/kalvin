#ifndef CUENTA_H
#define CUENTA_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QDebug>
#include "escojergenero.h"
#include "almacenaimage.h"
#include "guardarnombre.h"

#include "escojerfemenina.h"
#include "avatarscargados.h"
namespace Ui {
class Cuenta;
//class Escojerfemenina;
}

class Cuenta : public QDialog
{
    Q_OBJECT

public:
    explicit Cuenta(QWidget *parent = nullptr);
    //enviando nombre
    ~Cuenta();

signals:
    void back();

private slots:
    void on_pushButton_atrasbienve_clicked();

    void on_pushButton_login_clicked();//registro de la base de datos

    //ventana de comunicacion con otras
    void esconder();
    void escondercar();


    void on_pushButton_cargar_clicked();//cargar imagenes guardadas

private:
    Ui::Cuenta *ui;

    EscojerGenero* ventana;
    Escojerfemenina* ventana2;

    //ingresa a la ventana para verificar cuantos avatar tiene el usuario
    AvatarsCargados* ventanacar;

    //recuperando nombre
    GuardarNombre* name;

    //mandar nombre para cargar
    GuardarNombre* envname;

};

#endif // CUENTA_H
