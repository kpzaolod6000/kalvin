#ifndef GUARDARNOMBRE_H
#define GUARDARNOMBRE_H

#include <QString>
#include <QtSql>
#include <QMessageBox>

//almacenando el nombre enviad por la cuenta.h del usuario
static QString nombre;
class GuardarNombre
{
public:
    GuardarNombre(QString);
    GuardarNombre(QString,QString);
    GuardarNombre(){}

    QString getNombre();
    QStringList tipo;
    QStringList ls;
    QStringList lsA;
    QStringList lsH;
    QStringList lsB;
    QStringList lsL;
    QStringList lsF;
    //recogiendo de la base de datos
    QString getAvatar();
    QString getHead();
    QString getBody();
    QString getLegs();
    QString getFoots();
private:
    QString avatar;
    QString head;
    QString body;
    QString legs;
    QString foots;

};

#endif // GUARDARNOMBRE_H
