#include "escojergenero.h"
#include "ui_escojergenero.h"

EscojerGenero::EscojerGenero(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EscojerGenero)
{
    ui->setupUi(this);
    //cambiar el titulo
    setWindowTitle("ESCOJER GENERO");

    ventana = new EscojerMasculino();

    //la conexion de la ventana escojergenero y escojermasculino
    QObject :: connect(ventana,SIGNAL(back()),this,SLOT(esconder()));

    ventana2 = new Escojerfemenina();

    //la conexion de la ventana escojergenero y escojerfemenina
    QObject :: connect(ventana2,SIGNAL(back()),this,SLOT(esconder2()));
}


//emitiendo el metodo back que se comunica con el metodo esconder

void EscojerGenero::on_pushButton_atraslogin_clicked()
{
    emit(back());
}



//boton para ir a la ventana de escojer personaje masculino
void EscojerGenero::on_pushButton_varon_clicked()
{

    this->setVisible(false);
    ventana->setVisible(true);
}

//esconder para masculino
void EscojerGenero::esconder()
{
    this->setVisible(true);
    ventana->setVisible(false);
}

//boton para ir a la ventana de escojer personaje femenina
void EscojerGenero::on_pushButton_mujer_clicked()
{
    //Aca los datos
    //QPixmap mujer("/home/judal/Escritorio/fondos_fulhd/avataractual.png");
    //ventana2->scene->addPixmap(mujer);
    this->setVisible(false);
    ventana2->setVisible(true);
}


//esconder para femenina
void EscojerGenero::esconder2()
{
    this->setVisible(true);
    ventana2->setVisible(false);
}


EscojerGenero::~EscojerGenero()
{
    delete ui;
    delete ventana;
    delete ventana2;
}

