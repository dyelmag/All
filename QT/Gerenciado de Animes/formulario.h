#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QDialog>

namespace Ui {
class Formulario;
}

class Formulario : public QDialog
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = 0);
    ~Formulario();
    void par(QString p1, QString p2);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Formulario *ui;
};

#endif // FORMULARIO_H
