#include "accionpersonamostrar.h"

AccionPersonaMostrar::AccionPersonaMostrar(int a,int b,int c,int d,QString setImage)
{
    ejeX = a;
    ejeY = b;
    length = c;
    height = d;
    this->setImage = setImage;
}
QRectF AccionPersonaMostrar::boundingRect() const {
    return QRectF( ejeX,ejeY,length,height);
}

void AccionPersonaMostrar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    QImage image(setImage);
    painter->drawImage(rec,image);

    //QPen transPen(Qt :: TransparentMode);// dibuja el recuadro de posicion invisible
    QPen transPens(Qt :: transparent);
    painter->setPen(transPens);
    painter->drawRect( rec );
}

AccionPersonaMostrar::~AccionPersonaMostrar()
{
    ejeX = 0;
    ejeY = 0;
    length = 0;
    height = 0;
}

