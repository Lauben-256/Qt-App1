#ifndef MARIADIALOG_H
#define MARIADIALOG_H

#include <QDialog>

namespace Ui {
class mariaDialog;
}

class mariaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit mariaDialog(QWidget *parent = nullptr);
    ~mariaDialog();

private:
    Ui::mariaDialog *ui;
};

#endif // MARIADIALOG_H
