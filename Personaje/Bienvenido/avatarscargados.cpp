#include "avatarscargados.h"
#include "ui_avatarscargados.h"

AvatarsCargados::AvatarsCargados(QWidget *parent,QString set_nombre) :
    QDialog(parent),
    ui(new Ui::AvatarsCargados)
{
    ui->setupUi(this);
    ventana = new Escojerfemenina();

    ventana3 = new EscojerMasculino();

    //la conexion de la ventana escojergenero y escojerfemenina
    QObject :: connect(ventana3,SIGNAL(back()),this,SLOT(esconder2()));


    //tratando de comunicar con la ventana de escojergenero
    ventana2 = new EscojerGenero();

    //la conexion de la ventana escojergenero y escojerfemenina
    QObject :: connect(ventana,SIGNAL(back()),this,SLOT(esconder()));


    recuNombre = set_nombre;
    qDebug() << recuNombre;


    QSqlQuery query;
    query.prepare("SELECT * FROM AvatarRopa");
    if(query.exec()){
        qDebug() << "Consulta afirmativa de datos";
    }else{
        qDebug() << "Consulta negativa de datos";
    }


    while(query.next()){
        TAvatar << query.value(1).toByteArray().constData();
        id_Nombre << query.value(2).toByteArray().constData();
    }


    ui->tableWidgetPersonajes->setRowCount(0);//limpia la tabla

    int fila = 0;
    for(auto i=0;i<TAvatar.size();i++){
        if(recuNombre == id_Nombre[i]){

            ui->tableWidgetPersonajes->insertRow(fila);
            ui->tableWidgetPersonajes->setItem(fila,0,new QTableWidgetItem(id_Nombre[i]));
            ui->tableWidgetPersonajes->setItem(fila,1,new QTableWidgetItem(TAvatar[i]));
            PersoComparar << TAvatar[i];
            fila++;
        }
    }
}


void AvatarsCargados::on_pushButton_atrasLogin_clicked()
{
    emit(back());
}

QString AvatarsCargados::set_Avatar()
{
    //obteniendo el nombre para comprobar la lista
    //se debe modificar

    QString personaje = ui->lineEdit_personaje->text();
    //bool esta = false;
    for(auto i=0;i<PersoComparar.size();i++){
        if(PersoComparar[i] == personaje){
            envname = new GuardarNombre(recuNombre,personaje);
            almacen = new AlmacenaImage(personaje);
            return PersoComparar[i];
        }
    }
    return personaje;
}

void AvatarsCargados::on_pushButton_NextEscojerAvatar_clicked()
{
    //generar una QRect una funcion donde retorne las mismas dimensiones de la imagen

    if(set_Avatar() == "Mujer_Adulta"){
        avatar = envname->getAvatar();
        head = envname->getHead();
        body = envname->getBody();
        legs = envname->getLegs();
        foots = envname->getFoots();

        //Generar Avatar
        QPixmap avatarimage(avatar);
        ventana->scene->addPixmap(avatarimage.scaledToHeight(850));


        //recuperando posicion del head
        int conthead = almacen->getPosicionHead(head);

        if(conthead %2 == 0){
            rehead = new AccionPersonaMostrar(47,-33,278,150,head);
            ventana->scene->addItem(rehead);
        }

        //recuperando posicion de body
        size_t contbody = almacen->getPosicionBody(body);
        qDebug() << "posicion" << contbody;

        if(contbody % 2 == 0){
            rebody = new AccionPersonaMostrar(87,191,178,218,body);//par
            ventana->scene->addItem(rebody);
         }else{
            rebody = new AccionPersonaMostrar(106,189,138,150,body);
            ventana->scene->addItem(rebody);
         }


        //recuperando posicion de legs
        int contlegs = almacen->getPosicionLegs(legs);

        if(contlegs % 2 == 0){
            relegs = new AccionPersonaMostrar(80,363,192,260,legs);//par
            ventana->scene->addItem(relegs);
         }else{
            relegs = new AccionPersonaMostrar(84,375,184,351,legs);
            ventana->scene->addItem(relegs);
         }

        //recuperando posicion de foots
        refoots = new AccionPersonaMostrar(130,730,103,135,foots);
        ventana->scene->addItem(refoots);

        this->setVisible(false);
        ventana->setVisible(true);

    }else if(set_Avatar() == "Mujer_Joven"){
        avatar = envname->getAvatar();
        head = envname->getHead();
        body = envname->getBody();
        legs = envname->getLegs();
        foots = envname->getFoots();

        //Generar Avatar
        QPixmap avatarimage(avatar);
        ventana->scene->addPixmap(avatarimage.scaledToHeight(850));

        //recuperando posicion del head
        int conthead = almacen->getPosicionHead(head);

        if(conthead %2 == 0){
            rehead = new AccionPersonaMostrar(50,5,130,100,head);
            ventana->scene->addItem(rehead);
        }else{
            rehead = new AccionPersonaMostrar(67,55,100,50,head);
            ventana->scene->addItem(rehead);
        }

        //recuperando posicion de body
        rebody = new AccionPersonaMostrar(8,145,213,287,body);
        ventana->scene->addItem(rebody);


        //recuperando posicion de legs
        relegs = new AccionPersonaMostrar(39,378,152,180,legs);
        ventana->scene->addItem(relegs);

        //recuperando posicion de foots
        refoots = new AccionPersonaMostrar(41,703,149,155,foots);
        ventana->scene->addItem(refoots);

        this->setVisible(false);
        ventana->setVisible(true);

    }else if(set_Avatar() == "Mujer_Ninha"){
        avatar = envname->getAvatar();
        head = envname->getHead();
        body = envname->getBody();
        legs = envname->getLegs();
        foots = envname->getFoots();

        //Generar Avatar
        QPixmap avatarimage(avatar);
        ventana->scene->addPixmap(avatarimage.scaledToHeight(450));

        //recuperando posicion del head
        rehead = new AccionPersonaMostrar(-1,-42,207,100,head);
        ventana->scene->addItem(rehead);


        //recuperando posicion de body
        rebody = new AccionPersonaMostrar(51,150,108,80,body);
        ventana->scene->addItem(rebody);


        //recuperando posicion de legs
        relegs = new AccionPersonaMostrar(25,225,160,190,legs);
        ventana->scene->addItem(relegs);

        //recuperando posicion de foots
        refoots = new AccionPersonaMostrar(26,405,157,45,foots);
        ventana->scene->addItem(refoots);

        this->setVisible(false);
        ventana->setVisible(true);
    }else if(set_Avatar() == "Hombre_Adulto"){
        avatar = envname->getAvatar();
        head = envname->getHead();
        body = envname->getBody();
        legs = envname->getLegs();
        foots = envname->getFoots();

        //Generar Avatar
        QPixmap avatarimage(avatar);
        ventana3->scene->addPixmap(avatarimage.scaledToHeight(900));

        //recuperando posicion del head
        rehead = new AccionPersonaMostrar(79,-13,130,85,head);
        ventana3->scene->addItem(rehead);


        //recuperando posicion de body
        rebody = new AccionPersonaMostrar(2,132,275,325,body);
        ventana3->scene->addItem(rebody);


        //recuperando posicion de legs
        relegs = new AccionPersonaMostrar(50,405,180,405,legs);
        ventana3->scene->addItem(relegs);

        //recuperando posicion de foots
        refoots = new AccionPersonaMostrar(68,803,145,115,foots);
        ventana3->scene->addItem(refoots);

        this->setVisible(false);
        ventana3->setVisible(true);
    }else if (set_Avatar() == "Hombre_Joven"){
        avatar = envname->getAvatar();
        head = envname->getHead();
        body = envname->getBody();
        legs = envname->getLegs();
        foots = envname->getFoots();

        //Generar Avatar
        QPixmap avatarimage(avatar);
        ventana3->scene->addPixmap(avatarimage.scaledToHeight(650));

        //recuperando posicion del head
        rehead = new AccionPersonaMostrar(101,-1,155,60,head);
        ventana3->scene->addItem(rehead);


        //recuperando posicion de body
        rebody = new AccionPersonaMostrar(49,125,216,170,body);
        ventana3->scene->addItem(rebody);


        //recuperando posicion de legs
        relegs = new AccionPersonaMostrar(74,287,200,305,legs);
        ventana3->scene->addItem(relegs);

        //recuperando posicion de foots
        refoots = new AccionPersonaMostrar(54,588,241,73,foots);
        ventana3->scene->addItem(refoots);

        this->setVisible(false);
        ventana3->setVisible(true);
    }else if(set_Avatar() == "Hombre_Ninho"){
        avatar = envname->getAvatar();
        head = envname->getHead();
        body = envname->getBody();
        legs = envname->getLegs();
        foots = envname->getFoots();

        //Generar Avatar
        QPixmap avatarimage(avatar);
        ventana3->scene->addPixmap(avatarimage.scaledToHeight(500));

        //recuperando posicion del head
        rehead = new AccionPersonaMostrar(16,-1,105,65,head);
        ventana3->scene->addItem(rehead);


        //recuperando posicion de body
        rebody = new AccionPersonaMostrar(7,146,125,114,body);
        ventana3->scene->addItem(rebody);


        //recuperando posicion de legs
        relegs = new AccionPersonaMostrar(28,257,83,200,legs);
        ventana3->scene->addItem(relegs);

        //recuperando posicion de foots
        refoots = new AccionPersonaMostrar(36,457,64,43,foots);
        ventana3->scene->addItem(refoots);

        this->setVisible(false);
        ventana3->setVisible(true);
    }
    else{
        QMessageBox :: warning(this,"ERROR","Ingrese bien los datos");
    }
}

void AvatarsCargados::esconder()
{
    ventana2->setVisible(true);
    ventana->setVisible(false);
}
void AvatarsCargados::esconder2()
{
    ventana2->setVisible(true);
    ventana3->setVisible(false);
}
void AvatarsCargados::esconder3()
{
    //ventana4->setVisible(true);
    //ventana2->setvisible(false);
}

AvatarsCargados::~AvatarsCargados()
{
    delete ui;
}



