#ifndef ADDEDIT_H
#define ADDEDIT_H
#include "get_set2.h"

#include <QDialog>
#include <QSignalMapper>


namespace Ui {
class addEdit;
}

class addEdit : public QDialog
{
    Q_OBJECT

public:
    explicit addEdit(QWidget *parent = 0);
    ~addEdit();
    void insetCap(get_set);
    void preencheT();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void DeletePressed(int row);

    void Abre(int row);

    void on_pushButton_2_clicked();

private:
    Ui::addEdit *ui;
    QList<get_set> l;
    QStringList lista;
    QSignalMapper *signalMapper_;
    QSignalMapper *signalMapper2;
    int linha;

};

#endif // ADDEDIT_H
