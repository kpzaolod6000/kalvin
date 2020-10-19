#include "accionpersona.h"

AccionPersona::AccionPersona(int a, int b, int c, int d, QString setImage )
{
    ejeX = a;
    ejeY = b;
    length = c;
    height = d;
    this->setImage = setImage;
    Pressed = false;
}
QRectF AccionPersona::boundingRect() const {
    return QRectF( ejeX,ejeY,length,height);
}

void AccionPersona::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    QImage image(setImage);
    if(Pressed == true){

        painter->drawImage(rec,image);

    }

    else{
        qDebug() << "NOT";
    }

    //QPen transPen(Qt :: TransparentMode);// dibuja el recuadro de posicion invisible
    QPen transPen(Qt :: transparent);
    painter->setPen(transPen);
    painter->drawRect( rec );

}

void AccionPersona::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem :: mousePressEvent(event);

}
