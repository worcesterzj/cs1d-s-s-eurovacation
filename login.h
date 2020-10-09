#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include <QMouseEvent>
#include <QScreen>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();


    bool loggedIn() const {return _loggedIn;}

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_clicked();

signals:

    void loginSuccess(QString name);

private:
    Ui::Login *ui;
    QPoint offset;

    bool _loggedIn;
};

#endif // LOGIN_H
