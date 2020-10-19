#include "mainbienvenido.h"
#include "ui_mainbienvenido.h"

MainBienvenido::MainBienvenido(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainBienvenido)
{
    ui->setupUi(this);

    //cambiar el titulo
    setWindowTitle("BIENVENIDO");

    ventana = new Cuenta();

    //la conexion de la ventana mainbienvenido y cuenta
    QObject :: connect(ventana,SIGNAL(back()),this,SLOT(esconder()));
}

//imagen de fondo
void MainBienvenido :: paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPixmap img("/home/judal/Escritorio/fondos_fulhd/imagenes_para_proyecto/presentacion.jpg");
    resize(img.size());//incrementa de acuerdo a la imagen
    painter.drawPixmap(0,0,img);
    QWidget::paintEvent(e);
}

//boton play esconder la ventana del boton mainbienvenido y abrir la ventana cuenta
void MainBienvenido::on_pushButton_play_clicked()
{
    this->setVisible(false);
    ventana->setVisible(true);
}

//escondiendo
void MainBienvenido::esconder()
{
    this->setVisible(true);
    ventana->setVisible(false);
}


MainBienvenido::~MainBienvenido()
{
    delete ui;
    delete ventana;
}
