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
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
    QString getPassword() {return password;};

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    QPoint offset;
    QString password;
    QString username;
//    int m_nMouseClick_X_Coordinate;
//    int m_nMouseClick_Y_Coordinate;
};

#endif // LOGIN_H
