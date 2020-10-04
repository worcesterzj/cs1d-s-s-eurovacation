#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

//void Login::mousePressEvent(QMouseEvent *event)
//{
//    m_nMouseClick_X_Coordinate = event->x();
//    m_nMouseClick_Y_Coordinate = event->y();
//}

//void Login::mouseMoveEvent(QMouseEvent *event)
//{
//    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
//}

void Login::on_pushButton_login_clicked()
{
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(username == "SmithStrauss" && password == "cs1d")
    {
        QMessageBox::information(this, "Login", "Username and password is correct.");
        hide();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and password is incorrect");
    }
}

void Login::on_pushButton_clicked()
{
    close();
}
