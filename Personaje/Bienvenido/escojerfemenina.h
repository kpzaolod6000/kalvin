#ifndef ESCOJERFEMENINA_H
#define ESCOJERFEMENINA_H

#include <QMessageBox>

#include <QDialog>
#include <QGraphicsScene>
#include <QDebug>
#include "accionpersona.h"
#include "almacenaimage.h"
#include "guardarnombre.h"
#include <QtSql>
#include <QSqlQuery>


namespace Ui {
class Escojerfemenina;
}

class Escojerfemenina : public QDialog
{
    Q_OBJECT

public:
    explicit Escojerfemenina(QWidget *parent = nullptr);
    ~Escojerfemenina();
    QGraphicsScene* scene;
signals:
    void back();
private slots:
    void on_pushButton_atrasgenero_clicked();


    //vestimenta
    //***********************************
    void on_pushButton_NextHead_clicked();

    void on_pushButton_NextPolos_clicked();

    void on_pushButton_NextShort_clicked();

    void on_pushButton_NextFoots_clicked();

    //***********************************


    void on_pushButton_Guardar_clicked();

    //avatar

    void on_pushButton_jovenshow_clicked();

    void on_pushButton_adultashow_clicked();

    void on_pushButton_ninhashow_clicked();

private:
    Ui::Escojerfemenina *ui;

    //vector<QString>Guardar;ojo crear para almacenar las imagenes que se va ir a la base de datos

    AccionPersona* head;
    AccionPersona* body;
    AccionPersona* handright;
    AccionPersona* handleft;
    AccionPersona* legs;
    AccionPersona* foots;


    //extraendo las vestimentas imagenes
    AlmacenaImage* store;
    //Recuperando el nombre de usuario
    GuardarNombre* name;

    static size_t headcont;
    static size_t bodycont;
    static size_t legscont;
    static size_t footscont;
};

#endif // ESCOJERFEMENINA_H
