#include "escojerfemenina.h"
#include "ui_escojerfemenina.h"


Escojerfemenina::Escojerfemenina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Escojerfemenina)
{
    ui->setupUi(this);
    setWindowTitle("Escojer tu Personaje Femenina");

    //creando scene de tipo QGraphicsScene
    scene = new QGraphicsScene(this);
    ui->graphics_Avatar->setScene(scene);


}
size_t Escojerfemenina :: headcont = 0;
size_t Escojerfemenina :: bodycont = 0;
size_t Escojerfemenina :: legscont = 0;
size_t Escojerfemenina :: footscont = 0;

//para guardar avatar y ropa
static QString personaje = "";
static QString Persona = "";
static QString set_head = "";
static QString set_body = "";
static QString set_legsshort = "";
static QString set_foots = "";

//para guardarimagenes en BD
static int guardarcont = 0;

void Escojerfemenina::on_pushButton_atrasgenero_clicked()
{

    QMessageBox :: warning(this,"Atras","Desea retroceder se perderan los datos");
    emit(back());
}

//mostrar avatar Mujer_joven
void Escojerfemenina::on_pushButton_jovenshow_clicked()
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
    legscont = 0;
    footscont = 0;

    guardarcont = 0;
    //*************



    QPixmap mujer_joven(":/imagenes/mujer_joven/avatar_joven_actual.png");
    Persona = ":/imagenes/mujer_joven/avatar_joven_actual.png";

    scene->addPixmap(mujer_joven.scaledToHeight(850));

    //enviando al constructor el parametro de Mujer_Joven para que el almacen sea de la joven
    personaje = "Mujer_Joven";
    store = new AlmacenaImage(personaje);

    //colocando las vestimentas
    //CABEZA
    QPixmap head(":/imagenes/mujer_joven/clothing_Mjoven/antifaz.png");

    ui->label_head->setPixmap(head.scaled(100,100,Qt::KeepAspectRatio));
    //POLO
    QPixmap Body(":/imagenes/mujer_joven/clothing_Mjoven/polo_act2.png");
    ui->label_Body->setPixmap(Body.scaled(100,100,Qt::KeepAspectRatio));
    //SHORT
    QPixmap Legsshort(":/imagenes/mujer_joven/clothing_Mjoven/short.png");
    ui->label_LegsShort->setPixmap(Legsshort.scaled(100,100,Qt::KeepAspectRatio));
    //ZAPATOS
    QPixmap Foots(":/imagenes/mujer_joven/clothing_Mjoven/zapatos_act1.png");
    ui->label_Foots->setPixmap(Foots.scaled(100,100,Qt::KeepAspectRatio));

}

//mostrar avatar Mujer_Adulta
void Escojerfemenina::on_pushButton_adultashow_clicked()
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
    legscont = 0;
    footscont = 0;

    guardarcont = 0;
    //*************



    QPixmap mujer_adulta(":/imagenes/mujer_adulta/mujer_adulta.png");
    Persona = ":/imagenes/mujer_adulta/mujer_adulta.png";

    scene->addPixmap(mujer_adulta.scaledToHeight(850));

    //enviando al constructor el parametro de Mujer_Joven para que el almacen sea de la joven
    personaje = "Mujer_Adulta";
    store = new AlmacenaImage(personaje);

    //colocando las Puertas
    //CABEZA
    QPixmap puerta(":/imagenes/mujer_adulta/puertaadultamuj.jpg");

    ui->label_head->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //POLO
    ui->label_Body->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //SHORT
    ui->label_LegsShort->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //ZAPATOS
    ui->label_Foots->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
}

//mostrar avatar Mujer_Ninha
void Escojerfemenina::on_pushButton_ninhashow_clicked()
{
    //limpia todo las imagenes en el graphicsview
    scene->clear();
    //****************************


    Persona = "";
    set_head = "";
    set_body = "";
    set_legsshort = "";
    set_foots = "";

    //importante los contadores de las vestimentas deben ser inicializadas en cero cada vez que se integre un personaje
    headcont = 0;
    bodycont = 0;
    legscont = 0;
    footscont = 0;

    guardarcont = 0;
    //*************



    QPixmap mujer_ninha(":/imagenes/mujer_ninha/mujer_ninha.png");
    Persona = ":/imagenes/mujer_ninha/mujer_ninha.png";
    scene->addPixmap(mujer_ninha.scaledToHeight(450));

    //enviando al constructor el parametro de Mujer_Joven para que el almacen sea de la joven
    personaje = "Mujer_Ninha";
    store = new AlmacenaImage(personaje);

    //colocando las Puertas
    //CABEZA
    QPixmap puerta(":/imagenes/mujer_ninha/puertaninhamuj.jpg");

    ui->label_head->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //POLO
    ui->label_Body->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //SHORT
    ui->label_LegsShort->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));
    //ZAPATOS
    ui->label_Foots->setPixmap(puerta.scaled(200,200,Qt::KeepAspectRatio));


}


void Escojerfemenina::on_pushButton_NextHead_clicked()
{

    if(personaje == "Mujer_Joven"){
        if(headcont ==1){
            scene->removeItem(head);
            headcont = 0;
        }

        set_head = store->getImageHead(headcont);

        //remueve el ultimo elemento en la cabeza
        if(headcont > 0)
            scene->removeItem(head);//ojo cada vez que hago click se elimina el ultimo elemento guardado en person
        //scene->update();
        head = new AccionPersona(67,55,100,50,set_head);
        scene->addItem(head);


        //cambio de vestimenta en el label
        QString cambio = store ->getImageHead(headcont);
        QPixmap head(cambio);
        ui -> label_head -> setPixmap(head.scaled(100,100,Qt::KeepAspectRatio));
        headcont++;


    }else if( personaje == "Mujer_Adulta"){
        if(headcont == 1)
            headcont = 0;
        set_head = store->getImageHead(headcont);

        head = new AccionPersona(47,-33,278,150,set_head);
        scene->addItem(head);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageHead(headcont);
        QPixmap head(cambio);
        ui -> label_head -> setPixmap(head.scaled(100,100,Qt::KeepAspectRatio));
        headcont++;
    }else if(personaje == "Mujer_Ninha"){
        if(headcont == 1)
            headcont = 0;
        set_head = store->getImageHead(headcont);

        head = new AccionPersona(-1,-42,207,100,set_head);
        scene->addItem(head);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageHead(headcont);
        QPixmap head(cambio);
        ui -> label_head -> setPixmap(head.scaled(100,100,Qt::KeepAspectRatio));
        headcont++;
    }

}
void Escojerfemenina::on_pushButton_NextPolos_clicked()
{
    if(personaje == "Mujer_Joven"){
        if(bodycont ==1)
            bodycont = 0;

        set_body = store->getImageBody(bodycont);

        body = new AccionPersona(8,145,213,287,set_body);
        scene->addItem(body);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageBody(bodycont);
        QPixmap bodyy(cambio);
        ui -> label_Body -> setPixmap(bodyy.scaled(100,100,Qt::KeepAspectRatio));
        bodycont++;

    }else if( personaje == "Mujer_Adulta"){
        if(bodycont ==2){
            scene->removeItem(body);
            bodycont = 0;
        }
        if(bodycont % 2 == 0){

            set_body = store->getImageBody(bodycont);

            if(bodycont > 0)
                scene->removeItem(body);
            body = new AccionPersona(87,191,178,218,set_body);

            scene->addItem(body);
        }else{

            set_body = store->getImageBody(bodycont);
            scene->removeItem(body);
            body = new AccionPersona(106,189,138,150,set_body);

            scene->addItem(body);

        }
        //cambio de vestimenta en el label
        QString cambio = store ->getImageBody(bodycont);
        QPixmap bodyy(cambio);
        ui -> label_Body -> setPixmap(bodyy.scaled(100,100,Qt::KeepAspectRatio));
        bodycont++;

    }else if(personaje == "Mujer_Ninha"){
        if(bodycont ==1)
            bodycont = 0;

        set_body = store->getImageBody(bodycont);

        body = new AccionPersona(51,150,108,80,set_body);
        scene->addItem(body);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageBody(bodycont);
        QPixmap bodyy(cambio);
        ui -> label_Body -> setPixmap(bodyy.scaled(100,100,Qt::KeepAspectRatio));
        bodycont++;

    }
}


void Escojerfemenina::on_pushButton_NextShort_clicked()
{
    if(personaje== "Mujer_Joven"){
        if(legscont == 1)
            legscont = 0;

        set_legsshort = store->getImageLegs(legscont);
        //remueve el ultimo elemento en la cabeza
        //if(headcont > 0)
            //scene->removeItem(head);//ojo cada vez que hago click se elimina el ultimo elemento guardado en person



        legs = new AccionPersona(39,378,152,180,set_legsshort);
        scene->addItem(legs);        


        //cambio de vestimenta en el label
        QString cambio = store ->getImageLegs(legscont);
        QPixmap legsshort(cambio);
        ui -> label_LegsShort -> setPixmap(legsshort.scaled(100,100,Qt::KeepAspectRatio));
        legscont++;

    }else if( personaje == "Mujer_Adulta"){
        if(legscont == 2){
            scene->removeItem(legs);
            legscont = 0;
        }
        if(legscont%2==0){
            set_legsshort = store->getImageLegs(legscont);
            legs = new AccionPersona(80,363,192,260,set_legsshort);


            if(legscont > 0)
                scene->removeItem(legs);

            scene->addItem(legs);
        }else{
            scene->removeItem(legs);
            set_legsshort = store->getImageLegs(legscont);
            legs = new AccionPersona(84,375,184,351,set_legsshort);
            scene->addItem(legs);
        }


        //cambio de vestimenta en el label
        QString cambio = store ->getImageLegs(legscont);
        QPixmap legsshort(cambio);
        ui -> label_LegsShort -> setPixmap(legsshort.scaled(100,100,Qt::KeepAspectRatio));
        legscont++;

    }else if(personaje == "Mujer_Ninha"){
        if(legscont == 1)
            legscont = 0;
        if(legscont%2 == 0){//para los pantalones
            set_legsshort = store->getImageLegs(legscont);
            legs = new AccionPersona(25,225,160,190,set_legsshort);
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

void Escojerfemenina::on_pushButton_NextFoots_clicked()
{
    if(personaje== "Mujer_Joven"){
        if(footscont == 1)
            footscont = 0;

        set_foots= store->getImageFoots(footscont);
        //remueve el ultimo elemento en la cabeza
        //if(headcont > 0)
            //scene->removeItem(head);//ojo cada vez que hago click se elimina el ultimo elemento guardado en person

        foots = new AccionPersona(41,703,149,155,set_foots);
        scene->addItem(foots);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageFoots(footscont);
        QPixmap footss(cambio);
        ui -> label_Foots -> setPixmap(footss.scaled(100,100,Qt::KeepAspectRatio));
        footscont++;

    }else if( personaje == "Mujer_Adulta"){
        if(footscont == 2){
            scene->removeItem(foots);
            footscont = 0;
        }

        if(footscont > 0)
             scene->removeItem(foots);

        set_foots= store->getImageFoots(footscont);
        foots = new AccionPersona(130,730,103,135,set_foots);

        scene->addItem(foots);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageFoots(footscont);
        QPixmap footss(cambio);
        ui -> label_Foots -> setPixmap(footss.scaled(100,100,Qt::KeepAspectRatio));
        footscont++;

    }else if(personaje == "Mujer_Ninha"){
        if(footscont == 1)
            footscont = 0;
        set_foots= store->getImageFoots(footscont);

        //cambiar zapato
        foots = new AccionPersona(26,405,157,45,set_foots);
        scene->addItem(foots);

        //cambio de vestimenta en el label
        QString cambio = store ->getImageFoots(footscont);
        QPixmap footss(cambio);
        ui -> label_Foots -> setPixmap(footss.scaled(100,100,Qt::KeepAspectRatio));
        footscont++;

    }
}




//guardando Avatar vestida xd con su respectivo usuario
void Escojerfemenina::on_pushButton_Guardar_clicked()
{
    name = new GuardarNombre();//otro constructor
    QString set_name = name->getNombre();
    qDebug()<< set_name;

    if(personaje == "Mujer_Joven"){
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
    }else if(personaje == "Mujer_Adulta"){
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

    }else if(personaje == "Mujer_Ninha"){
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



Escojerfemenina::~Escojerfemenina()
{
    delete scene;
    delete head;
    delete body;
    delete handright;
    delete handleft;
    delete foots;
    delete ui;
}


