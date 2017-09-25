//Simple Gaussian Elimination Method Program V 1.0.0
// Programa del metodo de eliminacion Gaussiana simple V 1.0.0
#ifndef GAUSS_H
#define GAUSS_H

#include <QMainWindow>

namespace Ui {
class Gauss;
}

class Gauss : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gauss(QWidget *parent = 0);
    ~Gauss();
    //double numero;
    // Variables declaration.
    double x1, x2, x3, x4;// This variables will save the found values.
    double matriz[4][4];// Main matrix, will save the value of 16 numbers provided by the user.
    double indep[4][1];// This matrix will save 4 independent values, provided by the user.
    double tempo[1][4];// This temporal matrix will save rows for the exchange.
    double tempo2[1][4];// This another temporal matrix will save rows for the exchange.
    double ind1, ind2;// These variables will save independent values for the exchange.
    int i=0, j=0; // These variables will controll the row and column number in the matix and the table.
public slots:
    // Slots declaration.
    void ejecutar();// Slot for start the method.
    void limpiar();// Slot for clear the user interface fields.
    void agregar();// Slot for add data provided by the user.
private:
    Ui::Gauss *ui;
};

#endif // GAUSS_H
