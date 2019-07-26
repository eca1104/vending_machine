#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
}

Widget::~Widget()
{


    delete ui;
}
void Widget::changeMoney(int n){


    money += n;
    ui->lcdNumber->display(QString::number(money));

    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbGongcha->setEnabled(false);
    if(money>=100){
    ui->pbCoffee->setEnabled(true);
    }
    if(money>=150){
    ui->pbTea->setEnabled(true);
    }
    if(money>=200){
    ui->pbGongcha->setEnabled(true);
    }

}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);

}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbGongcha_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbexchange_clicked()
{
    QMessageBox msg;

    obaek=money/500;
    obaek_nmg=money%500;
    baek=obaek_nmg/100;
    baek_nmg=obaek_nmg%100;
    osip=baek_nmg/50;
    osip_nmg=baek_nmg%50;
    sip=osip_nmg/10;

    msg.information(nullptr, "Exchange","Total = "+QString::number(money)+"\n"+
                    "500 = "+QString::number(obaek)+"\n"+
                    "100 = "+QString::number(baek)+"\n"+
                    "50 = "+QString::number(osip)+"\n"+
                    "10 = "+QString::number(sip));

    money=0;
    ui->lcdNumber->display(QString::number(money));
}
