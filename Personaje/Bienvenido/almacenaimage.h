#ifndef ALMACENAIMAGE_H
#define ALMACENAIMAGE_H
#include <vector>
#include <QString>
#include <QDebug>
using namespace std;

class AlmacenaImage{
    public:
        AlmacenaImage(QString sex_edad);
        QString getImageHead(size_t i);
        QString getImageBody(size_t i);
        QString getImageLegs(size_t i);
        QString getImageHandRight(size_t i);
        QString getImageHandLeft(size_t i);
        QString getImageFoots(size_t i);
        QString getImageDresses(size_t i);

        int getPosicionHead(QString imagehead);
        size_t getPosicionBody(QString imagebody);
        int getPosicionLegs(QString imagelegs);
        int getPosicionFoots(QString imagefoots);
        int getPosicionDresses(QString imagefoots);


    private:
        vector<QString> head;
        vector<QString> body;
        vector<QString> dresses;
        vector<QString> legs;
        vector<QString> foots;
};

#endif // ALMACENAIMAGE_H
