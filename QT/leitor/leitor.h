#ifndef LEITOR_H
#define LEITOR_H


#include <QDialog>
#include "get_set2.h"

namespace Ui {
class Leitor;
}

class Leitor : public QDialog
{
    Q_OBJECT

public:
    explicit Leitor(QWidget *parent = 0);
    ~Leitor();
    void p(QList<get_set>);
    void preenche(QStringList lista);

private slots:
    void on_tbw_clicked(const QModelIndex &index);

private:
    Ui::Leitor *ui;
    int *id;
    QList<get_set> b;
    int sel;
};

#endif // LEITOR_H
