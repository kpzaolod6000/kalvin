#include "cuenta.h"
#include "ui_cuenta.h"


static QSqlDatabase conectar = QSqlDatabase::addDatabase("QSQLITE");//creamos conexion de tipo Qslitdatabase para la conexion
Cuenta::Cuenta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cuenta)
{

    ui->setupUi(this);
    //cambiar el titulo
    setWindowTitle("CUENTA");

    conectar.setDatabaseName("/home/judal/QtCreatorAvatar/base_de_datos_cuentas/Cuentas");//establecemos la base de datos

    if (conectar.open()){
        ui->label_conexion->setText("La base de datos abierta");
    }
    else {
        ui->label_conexion->setText("La base de datos cerrada");
    }

    ventana = new EscojerGenero();


    //la conexion de la ventana cuenta y escojer genero
    QObject :: connect(ventana,SIGNAL(back()),this,SLOT(esconder()));
}

//ingresa los datos a la base de datos y esconde la ventana para abrir la siguiente
void Cuenta::on_pushButton_login_clicked()
{
    QString nombre = ui->lineEdit_usuario->text();
    QString password = ui->lineEdit_password->text();
    QString repassword = ui->lineEdit_repeatpassword->text();



    if(!nombre.isEmpty() && !password.isEmpty() && !repassword.isEmpty()){
        if(password == repassword){
            QSqlQuery query;

            query.prepare("INSERT INTO Cuentas (Nombre,contrasenha) VALUES "
                                  "('"+nombre+"','"+password+"')");

            if(query.exec()){
                QMessageBox :: information(this,"Aviso de registro","Registro grabado");

                //guardandao en el constructor
                QString set_name= ui->lineEdit_usuario->text();
                name = new GuardarNombre(set_name);

                ui->lineEdit_usuario->clear();
                ui->lineEdit_password->clear();
                ui->lineEdit_repeatpassword->clear();
                ui->lineEdit_usuario->setFocus();//enfoca la mira para que ingrese empezando por nombre
                this->setVisible(false);
                ventana->setVisible(true);

            }else{
                 QMessageBox :: critical(this,"ERROR","ERROR nose puede ingresar datos, ya existe dicho usuario con el mismo nombre");
                 ui->lineEdit_usuario->clear();
                 ui->lineEdit_password->clear();
                 ui->lineEdit_repeatpassword->clear();
                 ui->lineEdit_usuario->setFocus();
            }
        }else{
            QMessageBox :: warning(this,"Advertencia","Contraseña diferente");

            ui->lineEdit_password->clear();
            ui->lineEdit_repeatpassword->clear();
            ui->lineEdit_password->setFocus();
        }
    }else {
        QMessageBox :: warning(this,"Advertencia","Campos Vacios");
    }

    //this->setVisible(false);
    //ventana->setVisible(true);

}

void Cuenta::esconder()
{
    this->setVisible(true);
    ventana->setVisible(false);
}

void Cuenta::escondercar()
{
    this->setVisible(true);
    ventanacar->setVisible(false);
}

//emitiendo el metodo back que se comunica con el metodo esconder

void Cuenta::on_pushButton_atrasbienve_clicked()
{
    emit(back());
}

//cargar avatar
void Cuenta::on_pushButton_cargar_clicked()
{
    QString nombre = ui->lineEdit_usuario->text();
    QString contrasenha = ui->lineEdit_password->text();
    QString recontrasenha = ui -> lineEdit_repeatpassword->text();
    QSqlQuery query;
    QStringList ls;
    QStringList lsC;



    query.prepare("SELECT * FROM Cuentas");

    if(query.exec()){
        qDebug() << "Consulta afirmativa";
    }else{
        qDebug() << "Consulta negativa";
    }

    while(query.next()){
        ls << query.value(0).toByteArray().constData();
        lsC << query.value(1).toByteArray().constData();
    }
    qDebug() << ls;

    QString set_nombre;
    QString set_contrasenha;
    for (int i = 0; i < ls.size(); ++i){
        //qDebug() << ls.at(i).toLocal8Bit().constData();
        if(nombre == ls[i]){

            set_nombre = ls[i];
            set_contrasenha = lsC[i];
        }else{
            qDebug() << "Usuario no encontrado";
        }
    }
    //Hacer que envie el nombre por medio de un constructor
    //************************************

    if (!nombre.isEmpty() && !contrasenha.isEmpty() && !recontrasenha.isEmpty()){
        if(nombre == set_nombre && contrasenha == set_contrasenha && contrasenha == recontrasenha){
        //Tratando enviar para extraer
            QMessageBox :: information(this,"Cargar","Usuario Encontrado");
            // recuperar el nombre


            ventanacar = new AvatarsCargados(this,set_nombre);
            //la conexion de ventana cuenta y avatarcargados
            QObject :: connect(ventanacar,SIGNAL(back()),this,SLOT(escondercar()));

            this->setVisible(false);
            ventanacar->setVisible(true);

        }else if(contrasenha != recontrasenha){
            QMessageBox :: warning(this,"Advertencia","Contraseña diferente");

            ui->lineEdit_password->clear();
            ui->lineEdit_repeatpassword->clear();
            ui->lineEdit_password->setFocus();
        }else if(nombre !=set_nombre){
            QMessageBox :: warning(this,"Advertencia","El Usuario no Existe");

            ui->lineEdit_usuario->clear();
            ui->lineEdit_password->clear();
            ui->lineEdit_repeatpassword->clear();
            ui->lineEdit_usuario->setFocus();
        }else if(contrasenha != set_contrasenha){
            QMessageBox :: warning(this,"Advertencia","La contraseña es incorrecta");

            ui->lineEdit_password->clear();
            ui->lineEdit_repeatpassword->clear();
            ui->lineEdit_password->setFocus();
        }

    }else{

        QMessageBox :: warning(this,"Advertencia","Campos Vacios");
    }
}

Cuenta::~Cuenta()
{
    delete ui;
    delete ventana;
    delete name;
    delete envname;
}


