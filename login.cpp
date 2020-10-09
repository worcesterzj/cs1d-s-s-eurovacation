#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login),
    _loggedIn(false)
{
    ui->setupUi(this);

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_login_clicked()
{

    if(ui->lineEdit_username->text() == "SmithStrauss" && ui->lineEdit_password->text() == "cs1d")
    {
        QMessageBox::information(this, "Login", "Username and password is correct.");
        _loggedIn = true;

        QString temp = ui->lineEdit_username->text();
        emit loginSuccess(temp);
        close();
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
