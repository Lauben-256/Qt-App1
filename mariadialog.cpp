#include "mariadialog.h"
#include "ui_mariadialog.h"

mariaDialog::mariaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mariaDialog)
{
    ui->setupUi(this);
}

mariaDialog::~mariaDialog()
{
    delete ui;
}
