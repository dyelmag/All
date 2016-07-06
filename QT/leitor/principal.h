#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "mangadao.h"

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    void preenche(QStringList);
    void teste(int);
    ~Principal();
    void preencheTB(QList<get_set2>);

private slots:
    void on_actionAbrir_triggered();

    void on_tbw_clicked(const QModelIndex &index);

    void on_add_clicked();

    void on_abrir_clicked();

private:
    Ui::Principal *ui;
    int *id;
    int sel, r;
};

#endif // PRINCIPAL_H
