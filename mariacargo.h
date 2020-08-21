#ifndef MARIACARGO_H
#define MARIACARGO_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <mariadialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MariaCargo; }
QT_END_NAMESPACE

class MariaCargo : public QMainWindow
{
    Q_OBJECT

public:
    MariaCargo(QWidget *parent = nullptr);
    ~MariaCargo();

private slots:
    void on_registerBtn_clicked();

    void on_loginBtn_clicked();

private:
    Ui::MariaCargo *ui;
    QSqlDatabase database;
};
#endif // MARIACARGO_H
