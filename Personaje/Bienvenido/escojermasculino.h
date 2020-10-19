#ifndef ESCOJERMASCULINO_H
#define ESCOJERMASCULINO_H

#include <QMessageBox>
#include <QDialog>

#include <QDialog>
#include <QGraphicsScene>
#include <QDebug>
#include "accionpersona.h"
#include "almacenaimage.h"
#include <QtSql>
#include <QSqlQuery>
#include "guardarnombre.h"

namespace Ui {
class EscojerMasculino;
}

class EscojerMasculino : public QDialog
{
    Q_OBJECT

public:
    explicit EscojerMasculino(QWidget *parent = nullptr);
    ~EscojerMasculino();
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
    void on_pushButton_ninhoshow_clicked();

    void on_pushButton_jovenshow_clicked();

    void on_pushButton_adultoshow_clicked();



private:
    Ui::EscojerMasculino *ui;
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
    static size_t handRcont;
    static size_t handLcont;
    static size_t legscont;
    static size_t footscont;

};

#endif // ESCOJERMASCULINO_H
