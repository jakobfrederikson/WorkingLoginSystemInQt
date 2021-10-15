#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <QFile>
#include <QDebug>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    bool foundUser = false;

    QFile login("./login.csv");

    // This is like vector<string>. Our CSV data will be put into this list for us to process.
    QStringList loginData;

    if(login.open(QFile::ReadOnly))
    {
        // I assume this is like stringstream. It works the same.
        QTextStream in(&login);

        // Go through the entire CSV and chuck it all into the loginData list.
        while (!in.atEnd())
        {
            QString line = login.readLine().replace("\r\n","");
            loginData.append(line.split(','));
        }
    }
    else
    {
        QMessageBox::warning(this, "Sign Up", login.errorString(), "Okay");
    }

    // Sort through the login file to check if username and password is correct.
    for (int i = 0; i < loginData.size(); i++)
    {
        // If both username and password are correct, set the boolean values to true.
        if (username == loginData[i] &&
            password == loginData[i + 1])
        {
            foundUser = true;
            break;
        }
        qDebug() << loginData[i];
    }
    login.close();

    if(foundUser == true)
    {
        QMessageBox::information(this, "Login", "Username and password is correct.", "Ok");

        // Reset to false incase another user wants to sign in later.
        foundUser = false;
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and password are incorrect.", "Ok");
    }
}

void MainWindow::on_pushButton_signUp_clicked()
{
    // Create sign up window object and show it.
    signUpUi = new SignUp(this);
    signUpUi->show();
}

