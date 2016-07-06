#ifndef ADDCAP_H
#define ADDCAP_H

#include <QDialog>

namespace Ui {
class addCap;
}

class addCap : public QDialog
{
    Q_OBJECT

public:
    explicit addCap(QWidget *parent = 0);
    ~addCap();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::addCap *ui;
    QStringList l;
};

#endif // ADDCAP_H
