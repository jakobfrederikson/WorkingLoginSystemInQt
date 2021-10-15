#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
    static bool back;

private slots:
    void on_pushButton_signUp_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
