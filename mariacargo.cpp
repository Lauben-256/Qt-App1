#include "mariacargo.h"
#include "ui_mariacargo.h"

MariaCargo::MariaCargo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MariaCargo)
{
    ui->setupUi(this);

    ui -> username -> setPlaceholderText("Enter Your Username");
    ui -> password -> setPlaceholderText("Enter Your Password");
    ui -> email -> setPlaceholderText("Enter Your Email");
    ui -> phone -> setPlaceholderText("Enter Your Phone");

    ui -> usernameLogin -> setPlaceholderText("Please Enter Your username");
    ui -> passwordLogin -> setPlaceholderText("Please Enter Your Password");


}

MariaCargo::~MariaCargo()
{
    delete ui;
}


void MariaCargo::on_registerBtn_clicked()
{
    qDebug() << "Register button worked";

    // Connecting to the database
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("password");
    database.setDatabaseName("MariaCargoDatabase");

        if(database.open())
        {
            // Retrieve Data From Input Fields
            //qDebug() << "Let's see if this function was called ";

            QString username = ui -> username -> text();
            QString password = ui -> password -> text();
            QString email = ui -> email -> text();
            QString Phone = ui -> phone -> text();

            // Run Our Insert

            QSqlQuery qry;

            qry.prepare("INSERT INTO users (username, password, email, Phone) "
                        "VALUES (:username, :password, :email, :Phone)");

            qry.bindValue(":username", username);
            qry.bindValue(":password", password);
            qry.bindValue(":email", email);
            qry.bindValue(":Phone", Phone);

            if(qry.exec())
            {
                QMessageBox::information(this, "Inserted", "Data Inserted Successfully");
            }
            else
            {
                QMessageBox::information(this, "Not Inserted", "Data Not Intserted");
            }

        }
        else
        {
            QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
        }


}

void MariaCargo::on_loginBtn_clicked()
{
    //qDebug() << "Login Button Called ";

    // Connecting to the database
    database = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("password");
    database.setDatabaseName("MariaCargoDatabase");

    QString username = ui -> usernameLogin -> text();
    QString password = ui -> passwordLogin -> text();

    // Check if database is open
    if(database.open())
    {
        // Creating My Querries
        //QMessageBox::information(this, "Database Connected", "Database Connected Successfully" );
        QSqlQuery query(QSqlDatabase::database("MyConnect"));

        query.prepare(QString("SELECT * FROM users WHERE username = :username AND password = :password"));;

        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if(!query.exec())
        {
            QMessageBox::information(this, "Failed", "Query Failed To Execute");
        }
        else
        {
            while(query.next())
            {
                QString usernameFromDB = query.value(1).toString();
                QString passwordFromDB = query.value(2).toString();

                if(usernameFromDB == username && passwordFromDB == password)
                {
                    QMessageBox::information(this, "Success", "Login Success");

                    mariaDialog dialog;
                    dialog.setModal(true);
                    dialog.exec();
                }
            }
        }

    }
    else
    {
        QMessageBox::information(this, "Database Failed", "Database Not Connected" );
    }



}
