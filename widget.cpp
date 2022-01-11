#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbMilk->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
}

void Widget::calcMoney()
{
    c500 = money/500;
    money = money % 500;
    c100 = money/100;
    money = money % 100;
    c50 = money/50;
    money = money % 50;
    c10 = money/10;
    money = money % 10;
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
//    money += 500;
//    ui->lcdNumber->display(money);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbReset_clicked()
{
    calcMoney();
    QString c500s = QString::number(c500);
    QString c100s = QString::number(c100);
    QString c50s = QString::number(c50);
    QString c10s = QString::number(c10);
    QMessageBox msgBox;
    msgBox.setText("잔돈 500원: "+c500s+"개, 100원: "+c100s+"개, 50원: "+c50s+"개, 10원: "+c10s+"개");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}
