#ifndef ADDEDIT_H
#define ADDEDIT_H

#include <QDialog>
#include <QSignalMapper>
#include "get_set.h"
#include "get_set2.h"

namespace Ui {
class addEdit;
}

class addEdit : public QDialog
{
    Q_OBJECT

public:
    explicit addEdit(QWidget *parent = 0);
    void modoI();
    void modoA(int);
    ~addEdit();

private slots:
    void on_pushButton_5_clicked();
    void DeletePressed(int row);

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_btPasta_clicked();

    void on_pushButton_clicked();

private:
    Ui::addEdit *ui;
    QList<get_set2> listaEP;
    int mod, qp, qEP;
    QSignalMapper *signalMapper_;
    QSignalMapper *signalMapper2;
    void preencheT();
};

#endif // ADDEDIT_H
