#ifndef AVATARSCARGADOS_H
#define AVATARSCARGADOS_H

#include <QDialog>
#include "guardarnombre.h"
#include "escojerfemenina.h"
#include "escojermasculino.h"
#include "accionpersonamostrar.h"
#include "accionpersona.h"
#include "escojergenero.h"
#include "almacenaimage.h"
//#include "cuenta.h"
#include <QMessageBox>
#include <QtSql>

namespace Ui {
class AvatarsCargados;
}

class AvatarsCargados : public QDialog
{
    Q_OBJECT

public:
    explicit AvatarsCargados(QWidget *parent = nullptr,QString set_nombre = nullptr);
    //AvatarsCargados(QString set_nombre);
    QString set_Avatar();
    ~AvatarsCargados();


signals:
    void back();
private slots:

    void on_pushButton_atrasLogin_clicked();

    void on_pushButton_NextEscojerAvatar_clicked();

    void esconder();
    void esconder2();
    void esconder3();
private:
    Ui::AvatarsCargados *ui;
    //extraer los avatar y las vestimentas
    GuardarNombre* envname;

    //para dibujar dentro del ui de femenina y comunicar con la ventana escojer femenina
    Escojerfemenina* ventana;
    //para dibujar dentro del ui de masculino y comunicar con la ventana escojer masculino
    EscojerMasculino* ventana3;
    //comunicar con escojer genero
    EscojerGenero* ventana2;

    //comunicar con cuenta
    //Cuenta* ventanak;


    QString recuNombre;
    QString avatar;
    QString head;
    QString body;
    QString legs;
    QString foots;
    //almacenar los elementos del usuario y el personaje
    QStringList TAvatar;
    QStringList id_Nombre;

    //almacenar todos los persoajes de un usuario
    QStringList PersoComparar;

    //dibujar las vestimentas
    AccionPersonaMostrar* rehead;
    AccionPersonaMostrar* rebody;

    AccionPersonaMostrar* rebody2;
    AccionPersonaMostrar* relegs;

    AccionPersonaMostrar* relegs2;
    AccionPersonaMostrar* refoots;

    //rescatar las imagenes del almacen
    AlmacenaImage* almacen;
};

#endif // AVATARSCARGADOS_H
