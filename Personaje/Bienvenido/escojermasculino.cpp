#include "escojermasculino.h"
#include "ui_escojermasculino.h"

EscojerMasculino::EscojerMasculino(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EscojerMasculino)
{
    ui->setupUi(this);
    setWindowTitle("Escoje tu Personaje Masculino");

    //creando scene de tipo QGraphicsScene
    scene = new QGraphicsScene(this);
    ui->graphics_Avatar->setScene(scene);

}
size_t EscojerMasculino :: headcont = 0;
size_t EscojerMasculino :: bodycont = 0;
size_t EscojerMasculino :: handRcont = 0;
size_t EscojerMasculino :: handLcont = 0;
size_t EscojerMasculino :: legscont = 0;
size_t EscojerMasculino :: footscont = 0;


//para guardar avatar y ropa
static QString personaje = "";
static QString Persona = "";
static QString set_head = "";
static QString set_body = "";
static QString set_legsshort = "";
static QString set_foots = "";

//para guardarimagenes en BD
static int guardarcont = 0;


//emitiendo el metodo back que se comunica con el metodo esconder

void EscojerMasculino::on_pushButton_atrasgenero_clicked()
{
    QMessageBox :: warning(this,"Atras","Desea retroceder se perderan los datos");
    emit(back());
}


//mostrar avatar Hombre_Joven
void EscojerMasculino::on_pushButton_jovenshow_clicked()
{
    //****************************
        //esto se hace cada vez que se apriete el boton
        //para que los anteriores direcciones de imagenes no permanezcan
        //a la hora de guardar en la base de datos

        //limpia todo las imagenes en el graphicsview

        scene->clear();

        //****************************

        Persona = "";
        set_head = "";
        set_body = "";
        set_legsshort = "";
        set_foots = "";

        //importante los contadores de las vestimentas deben ser inicializadas en creo cada vez que se integre un personaje
        headcont = 0;
        bodycont = 0;
        handRcont = 0;
        handLcont = 0;
        legscont = 0;
        footscont = 0;

        guardarcont = 0;
        //*************

        QPixmap hombre_joven(":/imagenes/hombre_joven/hombre_joven.png");
        Persona = ":/imagenes/hombre_joven/hombre_joven.png";

        scene->addPixmap(hombre_joven.scaledToHeight(650));

        //enviando al constructor el parametro de Mujer_Joven para que el almacen sea de la joven
        personaje = "Hombre_Joven";
        store = new AlmacenaImage(personaje);

        //colocando las Puertas
        //CABEZA
        QPixmap puerta(":/imagenes/hombre_joven/puertajovenhom.jpg");

        ui->label_head->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
        //POLO
        ui->label_Body->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
        //SHORT
        ui->label_LegsShort->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
        //ZAPATOS
        ui->label_Foots->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));

}

//mostrar avata Hombre_Adulto
void EscojerMasculino::on_pushButton_adultoshow_clicked()
{
    //limpia todo las imagenes en el graphicsview
    scene->clear();
    //****************************


    Persona = "";
    set_head = "";
    set_body = "";
    set_legsshort = "";
    set_foots = "";

    //importante los contadores de las vestimentas deben ser inicializadas en creo cada vez que se integre un personaje
    headcont = 0;
    bodycont = 0;
    handRcont = 0;
    handLcont = 0;
    legscont = 0;
    footscont = 0;

    guardarcont = 0;
    //*************

    QPixmap hombre_joven(":/imagenes/hombre_adulto/hombre_adulto.png");
    Persona = ":/imagenes/hombre_adulto/hombre_adulto.png";

    scene->addPixmap(hombre_joven.scaledToHeight(900));

    //enviando al constructor el parametro de Mujer_Joven para que el almacen sea de la joven
    personaje = "Hombre_Adulto";
    store = new AlmacenaImage(personaje);

    //colocando las Puertas
    //CABEZA
    QPixmap puerta(":/imagenes/hombre_adulto/puertaadultahom.jpg");

    ui->label_head->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //POLO
    ui->label_Body->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //SHORT
    ui->label_LegsShort->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //ZAPATOS
    ui->label_Foots->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));


}

//mostrar avatar Hombre_Ninho
void EscojerMasculino::on_pushButton_ninhoshow_clicked()
{
    //limpia todo las imagenes en el graphicsview
    scene->clear();
    //****************************


    Persona = "";
    set_head = "";
    set_body = "";
    set_legsshort = "";
    set_foots = "";

    //importante los contadores de las vestimentas deben ser inicializadas en creo cada vez que se integre un personaje
    headcont = 0;
    bodycont = 0;
    handRcont = 0;
    handLcont = 0;
    legscont = 0;
    footscont = 0;

    guardarcont = 0;
    //*************

    QPixmap hombre_joven(":/imagenes/hombre_ninho/hombre_ninho.png");
    Persona = ":/imagenes/hombre_ninho/hombre_ninho.png";

    scene->addPixmap(hombre_joven.scaledToHeight(500));

    //enviando al constructor el parametro de Mujer_Joven para que el almacen sea de la joven
    personaje = "Hombre_Ninho";
    store = new AlmacenaImage(personaje);

    //colocando las Puertas
    //CABEZA
    QPixmap puerta(":/imagenes/hombre_ninho/puertaninhohom.jpg");

    ui->label_head->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //POLO
    ui->label_Body->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //SHORT
    ui->label_LegsShort->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //ZAPATOS
    ui->label_Foots->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));



}




void EscojerMasculino::on_pushButton_NextHead_clicked()
{
    if(personaje == "Hombre_Joven"){
        if(headcont ==1)
            headcont = 0;

        set_head = store->getImageHead(headcont);

        head = new AccionPersona(101,-1,155,60,set_head);
        scene->addItem(head);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageHead(headcont);
        QPixmap head(cambio);
        ui -> label_head -> setPixmap(head.scaled(100,100,Qt::KeepAspectRatio));
        headcont++;


    }else if( personaje == "Hombre_Adulto"){
        if(headcont == 1)
            headcont = 0;
        set_head = store->getImageHead(headcont);

        head = new AccionPersona(79,-13,130,85,set_head);
        scene->addItem(head);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageHead(headcont);
        QPixmap head(cambio);
        ui -> label_head -> setPixmap(head.scaled(100,100,Qt::KeepAspectRatio));
        headcont++;
    }else if(personaje == "Hombre_Ninho"){
        if(headcont == 1)
            headcont = 0;
        set_head = store->getImageHead(headcont);

        head = new AccionPersona(16,-1,105,65,set_head);
        scene->addItem(head);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageHead(headcont);
        QPixmap head(cambio);
        ui -> label_head -> setPixmap(head.scaled(100,100,Qt::KeepAspectRatio));
        headcont++;
    }


}

void EscojerMasculino::on_pushButton_NextPolos_clicked()
{
    if(personaje == "Hombre_Joven"){
        if(bodycont ==1)
            bodycont = 0;

        set_body = store->getImageBody(bodycont);

        body = new AccionPersona(49,125,216,170,set_body);
        scene->addItem(body);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageBody(bodycont);
        QPixmap bodyy(cambio);
        ui -> label_Body -> setPixmap(bodyy.scaled(100,100,Qt::KeepAspectRatio));
        bodycont++;

    }else if( personaje == "Hombre_Adulto"){
        if(bodycont ==1)
            bodycont = 0;

        set_body = store->getImageBody(bodycont);

        body = new AccionPersona(2,132,275,325,set_body);
        scene->addItem(body);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageBody(bodycont);
        QPixmap bodyy(cambio);
        ui -> label_Body -> setPixmap(bodyy.scaled(100,100,Qt::KeepAspectRatio));
        bodycont++;

    }else if(personaje == "Hombre_Ninho"){
        if(bodycont ==1)
            bodycont = 0;

        set_body = store->getImageBody(bodycont);

        body = new AccionPersona(7,146,125,114,set_body);
        scene->addItem(body);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageBody(bodycont);
        QPixmap bodyy(cambio);
        ui -> label_Body -> setPixmap(bodyy.scaled(100,100,Qt::KeepAspectRatio));
        bodycont++;

    }

}

void EscojerMasculino::on_pushButton_NextShort_clicked()
{
    if(personaje== "Hombre_Joven"){
        if(legscont == 1)
            legscont = 0;

        set_legsshort = store->getImageLegs(legscont);

        legs = new AccionPersona(74,287,200,305,set_legsshort);
        scene->addItem(legs);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageLegs(legscont);
        QPixmap legsshort(cambio);
        ui -> label_LegsShort -> setPixmap(legsshort.scaled(100,100,Qt::KeepAspectRatio));
        legscont++;

    }else if( personaje == "Hombre_Adulto"){
        if(legscont == 1)
            legscont = 0;
        set_legsshort = store->getImageLegs(legscont);
        legs = new AccionPersona(50,405,180,405,set_legsshort);
        scene->addItem(legs);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageLegs(legscont);
        QPixmap legsshort(cambio);
        ui -> label_LegsShort -> setPixmap(legsshort.scaled(100,100,Qt::KeepAspectRatio));
        legscont++;

    }else if(personaje == "Hombre_Ninho"){
        if(legscont == 1)
            legscont = 0;
        if(legscont%2 == 0){//para los pantalones
            set_legsshort = store->getImageLegs(legscont);
            legs = new AccionPersona(28,257,83,200,set_legsshort);
            scene->addItem(legs);
        }else{//para los short
            //set_legsshort = store->getImageLegs(legscont);
            //legs = new AccionPersona(39,378,152,180,set_legsshort);
            //scene->addItem(legs);
        }
        //cambio de vestimenta en el label
        QString cambio = store ->getImageLegs(legscont);
        QPixmap legsshort(cambio);
        ui -> label_LegsShort -> setPixmap(legsshort.scaled(100,100,Qt::KeepAspectRatio));
        legscont++;


    }

}

void EscojerMasculino::on_pushButton_NextFoots_clicked()
{
    if(personaje== "Hombre_Joven"){
        if(footscont == 1)
            footscont = 0;

        set_foots= store->getImageFoots(footscont);

        foots = new AccionPersona(54,588,241,73,set_foots);
        scene->addItem(foots);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageFoots(footscont);
        QPixmap footss(cambio);
        ui -> label_Foots -> setPixmap(footss.scaled(100,100,Qt::KeepAspectRatio));
        footscont++;

    }else if( personaje == "Hombre_Adulto"){
        if(footscont == 1)
            footscont = 0;
        set_foots= store->getImageFoots(footscont);

        foots = new AccionPersona(68,803,145,115,set_foots);
        scene->addItem(foots);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageFoots(footscont);
        QPixmap footss(cambio);
        ui -> label_Foots -> setPixmap(footss.scaled(100,100,Qt::KeepAspectRatio));
        footscont++;


    }else if(personaje == "Hombre_Ninho"){
        if(footscont == 1)
            footscont = 0;
        set_foots= store->getImageFoots(footscont);

        foots = new AccionPersona(36,457,64,43,set_foots);
        scene->addItem(foots);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageFoots(footscont);
        QPixmap footss(cambio);
        ui -> label_Foots -> setPixmap(footss.scaled(100,100,Qt::KeepAspectRatio));
        footscont++;

    }

}

void EscojerMasculino::on_pushButton_Guardar_clicked()
{
    name = new GuardarNombre();//otro constructor
    QString set_name = name->getNombre();
    qDebug()<< set_name;

    if(personaje == "Hombre_Joven"){
        static QString id;
        int ids = 0;
        guardarcont++;
        if(guardarcont == 1){
            QSqlQuery query;
            query.prepare("INSERT INTO AvatarRopa (EtapaPerson,Id_Nombre,Cuerpo,Head,Body,LegsShort,Foots) VALUES "
                        "('"+personaje+"','"+set_name+"','"+Persona+"','"+set_head+"','"+set_body+"','"+set_legsshort+"','"+set_foots+"')");
            if(query.exec()){
                QMessageBox :: information(this,"Guardar","Datos Guardados");
            }else{
                QMessageBox :: information(this,"Guardar","NO guardo");
            }
            QSqlQuery query1;
            query1.prepare("SELECT * FROM AvatarRopa");
                if(query1.exec()){
                }else{
                }
                 while(query1.next()){
                id = query1.value(0).toByteArray().constData();

                qDebug() << id;
                qDebug() << ids;
            }

            guardarcont++;
        }else if(guardarcont>1){
            ids = id.toInt();
            QSqlQuery query1;
            query1.prepare("UPDATE AvatarRopa SET Cuerpo='"+Persona+"',Head='"+set_head+"' ,Body='"+set_body+"' ,LegsShort='"+set_legsshort+"' ,Foots='"+set_foots+"' WHERE id_Avatar="+QString::number(ids));
            if(query1.exec()){
                QMessageBox :: information(this,"SobreGuardar","Datos Sobrescribidos");
            }else{
                QMessageBox :: information(this,"SobreGuardar","NO sobreescribidos");
            }
            guardarcont++;
        }

    }else if(personaje == "Hombre_Adulto"){
        static QString id;
        int ids = 0;
        guardarcont++;
        if(guardarcont == 1){
            QSqlQuery query;
            query.prepare("INSERT INTO AvatarRopa (EtapaPerson,Id_Nombre,Cuerpo,Head,Body,LegsShort,Foots) VALUES "
                        "('"+personaje+"','"+set_name+"','"+Persona+"','"+set_head+"','"+set_body+"','"+set_legsshort+"','"+set_foots+"')");
            if(query.exec()){
                QMessageBox :: information(this,"Guardar","Datos Guardados");
            }else{
                QMessageBox :: information(this,"Guardar","NO guardo");
            }
            QSqlQuery query1;
            query1.prepare("SELECT * FROM AvatarRopa");
                if(query1.exec()){
                }else{
                }
                 while(query1.next()){
                id = query1.value(0).toByteArray().constData();

                qDebug() << id;
                qDebug() << ids;
            }

            guardarcont++;
        }else if(guardarcont>1){
            ids = id.toInt();
            QSqlQuery query1;
            query1.prepare("UPDATE AvatarRopa SET Cuerpo='"+Persona+"',Head='"+set_head+"' ,Body='"+set_body+"' ,LegsShort='"+set_legsshort+"' ,Foots='"+set_foots+"' WHERE id_Avatar="+QString::number(ids));
            if(query1.exec()){
                QMessageBox :: information(this,"SobreGuardar","Datos Sobrescribidos");
            }else{
                QMessageBox :: information(this,"SobreGuardar","NO sobreescribidos");
            }
            guardarcont++;
        }

    }else if(personaje == "Hombre_Ninho"){
        static QString id;
        int ids = 0;
        guardarcont++;
        if(guardarcont == 1){
            QSqlQuery query;
            query.prepare("INSERT INTO AvatarRopa (EtapaPerson,Id_Nombre,Cuerpo,Head,Body,LegsShort,Foots) VALUES "
                        "('"+personaje+"','"+set_name+"','"+Persona+"','"+set_head+"','"+set_body+"','"+set_legsshort+"','"+set_foots+"')");
            if(query.exec()){
                QMessageBox :: information(this,"Guardar","Datos Guardados");
            }else{
                QMessageBox :: information(this,"Guardar","NO guardo");
            }
            QSqlQuery query1;
            query1.prepare("SELECT * FROM AvatarRopa");
                if(query1.exec()){
                }else{
                }
                 while(query1.next()){
                id = query1.value(0).toByteArray().constData();

                qDebug() << id;
                qDebug() << ids;
            }

            guardarcont++;
        }else if(guardarcont>1){
            ids = id.toInt();
            QSqlQuery query1;
            query1.prepare("UPDATE AvatarRopa SET Cuerpo='"+Persona+"',Head='"+set_head+"' ,Body='"+set_body+"' ,LegsShort='"+set_legsshort+"' ,Foots='"+set_foots+"' WHERE id_Avatar="+QString::number(ids));
            if(query1.exec()){
                QMessageBox :: information(this,"SobreGuardar","Datos Sobrescribidos");
            }else{
                QMessageBox :: information(this,"SobreGuardar","NO sobreescribidos");
            }
            guardarcont++;
        }
    }

}

EscojerMasculino::~EscojerMasculino()
{
    delete scene;
    delete head;
    delete body;
    delete handright;
    delete handleft;
    delete foots;
    delete ui;
}
