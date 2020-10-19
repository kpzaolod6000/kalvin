#ifndef MAINBIENVENIDO_H
#define MAINBIENVENIDO_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include "cuenta.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainBienvenido; }
QT_END_NAMESPACE

class MainBienvenido : public QMainWindow
{
    Q_OBJECT

public:
    MainBienvenido(QWidget *parent = nullptr);
    ~MainBienvenido();
    //imagen de fondo
    void paintEvent(QPaintEvent* e);

private slots:
    void on_pushButton_play_clicked();
    void esconder();

private:
    Ui::MainBienvenido *ui;
    Cuenta* ventana;
};
#endif // MAINBIENVENIDO_H
