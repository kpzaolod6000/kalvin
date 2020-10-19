#include "guardarnombre.h"

GuardarNombre::GuardarNombre(QString nombre)
{
    ::nombre = nombre;

}

GuardarNombre::GuardarNombre(QString nombre, QString tipoAvatar)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM AvatarRopa");
    if(query.exec()){
        qDebug() << "Consulta afirmativa de datos";
    }else{
        qDebug() << "Consulta negativa de datos";
    }

    int cont = 0;
    while (query.next()) {
        tipo << query.value(1).toByteArray().constData();
        ls << query.value(2).toByteArray().constData();
        lsA << query.value(3).toByteArray().constData();
        lsH << query.value(4).toByteArray().constData();
        lsB << query.value(5).toByteArray().constData();
        lsL << query.value(6).toByteArray().constData();
        lsF << query.value(7).toByteArray().constData();
        qDebug() << cont;
        qDebug() << ls[cont];
        cont++;
    }

    for(auto i=0;i<ls.size();i++){
        if(nombre == ls[i] && tipoAvatar == tipo[i]){
            avatar = lsA[i];
            head = lsH[i];
            body = lsB[i];
            legs = lsL[i];
            foots = lsF[i];
        }else if(nombre == ls[i] && tipoAvatar != tipo[i]){
            qDebug() << "no tiene una avatar guardado de tipo" << tipo[i];
        }else{
            qDebug() << "no tiene ningun avatar";
        }
    }
    qDebug() << ls;
}




QString GuardarNombre :: getNombre(){
    return nombre;
}

QString GuardarNombre :: getAvatar(){
    return avatar;
}

QString GuardarNombre :: getHead(){
    return head;
}

QString GuardarNombre :: getBody(){
    return body;
}

QString GuardarNombre :: getLegs(){
    return legs;
}

QString GuardarNombre :: getFoots(){
    return foots;
}







