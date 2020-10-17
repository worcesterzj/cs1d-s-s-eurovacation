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
    /**
     * @brief Login constructor to initialze parent to nullptr
     * @param parent QWidget *parent
     */
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    /**
     * @brief loggedIn check if the user is logged in
     * @return bool of true if logged in false if not
     */
    bool loggedIn() const {return _loggedIn;}

private slots:
    /**
     * @brief on_pushButton_login_clicked checks if the username and password is correct,
     * will display a QMessageBox for correct login or incorrect
     */
    void on_pushButton_login_clicked();
    /**
     * @brief on_pushButton_clicked closes the window
     */
    void on_pushButton_clicked();

signals:
    /**
     * @brief loginSuccess signal
     * @param name username
     */
    void loginSuccess(QString name);

private:
    /** MainWindow *
     * @brief ui
     * main ui form
     */
    Ui::Login *ui;
    /** bool
     * @brief _loggedIn
     * bool to check if logged in successfully
     */
    bool _loggedIn;
};

#endif // LOGIN_H
