#include "almacenaimage.h"


AlmacenaImage::AlmacenaImage(QString sex_edad)
{
    if(sex_edad == "Mujer_Joven")
    {
        head = {":/imagenes/mujer_joven/clothing_Mjoven/antifaz.png"};
        body = {":/imagenes/mujer_joven/clothing_Mjoven/polo_act2.png"};
        legs = {":/imagenes/mujer_joven/clothing_Mjoven/short.png"};
        foots = {":/imagenes/mujer_joven/clothing_Mjoven/zapatos_act1.png"};
    }
    else if(sex_edad == "Mujer_Adulta"){
        head = {":/imagenes/mujer_adulta/clothing_Madulta/head_ada.png"};
        body = {":/imagenes/mujer_adulta/clothing_Madulta/polo1_Ada.png",":/imagenes/mujer_adulta/clothing_Madulta/polo2_ada.png"};
        legs = {":/imagenes/mujer_adulta/clothing_Madulta/falda_Ada.png",":/imagenes/mujer_adulta/clothing_Madulta/pantalon_Ada.png"};
        foots = {":/imagenes/mujer_adulta/clothing_Madulta/zapato_ada.png",":/imagenes/mujer_adulta/clothing_Madulta/zapato1_Ada.png"};
        dresses = {":/imagenes/mujer_adulta/clothing_Madulta/vestido_Ada.png",":/imagenes/mujer_adulta/clothing_Madulta/vestido1_Ada.png"};

    }
    else if(sex_edad == "Mujer_Ninha"){
        head = {":/imagenes/mujer_ninha/clothing_Mninha/head_nia.png"};
        body = {":/imagenes/mujer_ninha/clothing_Mninha/polo_nia.png"};
        legs = {":/imagenes/mujer_ninha/clothing_Mninha/pantalon_nia.png"};
        foots = {":/imagenes/mujer_ninha/clothing_Mninha/zapato1_nia.png"};
    }
    else if(sex_edad == "Hombre_Joven"){

        head = {":/imagenes/hombre_joven/clothing_Hjoven/head_jo.png"};
        body = {":/imagenes/hombre_joven/clothing_Hjoven/polo_jo.png"};
        legs = {":/imagenes/hombre_joven/clothing_Hjoven/pantalon_jo.png"};
        foots = {":/imagenes/hombre_joven/clothing_Hjoven/zapato_jo.png"};
    }

    else if(sex_edad == "Hombre_Adulto"){
        head = {":/imagenes/hombre_adulto/clothing_adulto/head_ad.png"};
        body = {":/imagenes/hombre_adulto/clothing_adulto/polo_ad.png"};
        legs = {":/imagenes/hombre_adulto/clothing_adulto/pantalon_ad.png"};
        foots = {":/imagenes/hombre_adulto/clothing_adulto/zapato_ad.png"};

    }
    else if(sex_edad == "Hombre_Ninho"){
        head = {":/imagenes/hombre_ninho/clothing_Hninho/head_no.png"};
        body = {":/imagenes/hombre_ninho/clothing_Hninho/polo_no.png"};
        legs = {":/imagenes/hombre_ninho/clothing_Hninho/pantalon_no.png"};
        foots = {":/imagenes/hombre_ninho/clothing_Hninho/zapato_no.png"};
    }
}


QString AlmacenaImage::getImageHead(size_t i)
{
    return head[i];
}

QString AlmacenaImage::getImageBody(size_t i)
{
    return body[i];
}

QString AlmacenaImage::getImageLegs(size_t i)
{
    return legs[i];
}

QString AlmacenaImage::getImageFoots(size_t i)
{
    return foots[i];
}

QString AlmacenaImage::getImageDresses(size_t i)
{
    return dresses[i];
}

//Guardando posicion de la imagen para devolver
int AlmacenaImage::getPosicionHead(QString imagehead)
{
    int cont=-1;
    for(size_t i=0;i<head.size();i++){
        if(head[i] == imagehead){
            cont++;
        }else{
            cont++;
        }
    }
    return cont;
}

size_t AlmacenaImage::getPosicionBody(QString imagebody)
{
    for(size_t i=0;i<body.size();i++){
        if(body[i] == imagebody){
            return i;
        }
    }
}

int AlmacenaImage::getPosicionLegs(QString imagelegs)
{
    for(size_t i=0;i<legs.size();i++){
        if(legs[i] == imagelegs){
            return i;
        }
    }
}

int AlmacenaImage::getPosicionFoots(QString imagefoots)
{
    int cont=-1;
        for(size_t i=0;i<foots.size();i++){
            if(foots[i] == imagefoots){
                cont++;
            }else{
                cont++;
            }
        }
        return cont;

}

int AlmacenaImage::getPosicionDresses(QString imagedresses)
{
    int cont=-1;
        for(size_t i=0;i<dresses.size();i++){
            if(dresses[i] == imagedresses){
                cont++;
            }else{
                cont++;
            }
        }
        return cont;

}
