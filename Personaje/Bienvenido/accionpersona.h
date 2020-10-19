#ifndef ACCIONPERSONA_H
#define ACCIONPERSONA_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

//La clase AccionPersona encargada de recibir posicion y la imagen
//para luego dibujarla de acuerdo a la posicion correspondiente
class AccionPersona : public QGraphicsItem
{
public:
    AccionPersona( int, int, int, int, QString);

    QRectF boundingRect() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

    bool Pressed;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    int ejeX;
    int ejeY;
    int length;
    int height;
    QString setImage;
};

#endif // ACCIONPERSONA_H
