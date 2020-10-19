#ifndef ACCIONPERSONAMOSTRAR_H
#define ACCIONPERSONAMOSTRAR_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class AccionPersonaMostrar : public QGraphicsItem
{
public:
    AccionPersonaMostrar( int, int, int, int, QString);
    ~AccionPersonaMostrar();
    QRectF boundingRect()const;

    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
private:
    int ejeX;
    int ejeY;
    int length;
    int height;
    QString setImage;
};

#endif // ACCIONPERSONAMOSTRAR_H
