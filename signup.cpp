#include "signup.h"
#include "ui_signup.h"
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_signUp_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QFile login("./login.csv");

    if(login.open(QIODevice::WriteOnly | QFile::Append | QFile::Text))
    {
        QTextStream output(&login);
        output << username << "," << password << "\n";
        QMessageBox::information(this, "Sign Up", "Sign up successful.", "Okay");
    }
    else
    {
        QMessageBox::warning(this, "Sign Up", "Cannot sign up.", "Okay");
    }

    login.close();
}


void SignUp::on_pushButton_close_clicked()
{
    close();
}

