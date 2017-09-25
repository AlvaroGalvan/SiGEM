//Simple Gaussian Elimination Method Program V 1.0.0
// Programa del metodo de eliminacion Gaussiana simple V 1.0.0
#include "gauss.h"
#include "ui_gauss.h"
#include <QTableWidgetItem>// Library for allow the use of items from a table widget.

Gauss::Gauss(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gauss)
{
    ui->setupUi(this);
    setWindowTitle("Metodo de Eliminacion Gaussiana"); //Prints the method's name at window title.
    // Connections between push buttons and slots
    connect(ui->Inicia,SIGNAL(clicked()),this,SLOT(ejecutar())); //Button and slot for start the method.
    connect(ui->Limpia,SIGNAL(clicked()),this,SLOT(limpiar())); //Button and slot for clear the fields from user interface.
    connect(ui->Agrega,SIGNAL(clicked()),this,SLOT(agregar())); //Button for add items to the table.
    ui->Inicia->setDisabled(true);// Disables the start button till all items from table been added.
    ui->Limpia->setDisabled(true);// Disables the clear button.
}

void Gauss::agregar(){ // With this slot the user will add items from spinboxes to the table.
        ui->Limpia->setDisabled(false);// The start button activates when the user adds a row of data.
        // All the spinboxes collects the equations variables and saves it in a 4x4 matrix.
        matriz[i][0]=ui->valorx1->value();
        matriz[i][1]=ui->valorx2->value();
        matriz[i][2]=ui->valorx3->value();
        matriz[i][3]=ui->valorx4->value();
        // This spinbox collects the value of the independent variables and saves it in a 4x1 matrix.
        indep[i][0]=ui->valori->value();
        // The introduced values shows at his respective table position.
        ui->Tabla->setItem(i,0,new QTableWidgetItem(ui->valorx1->text()));//x1
        ui->Tabla->setItem(i,1,new QTableWidgetItem(ui->valorx2->text()));//x2
        ui->Tabla->setItem(i,2,new QTableWidgetItem(ui->valorx3->text()));//x3
        ui->Tabla->setItem(i,3,new QTableWidgetItem(ui->valorx4->text()));//x4
        ui->Tabla->setItem(i,4,new QTableWidgetItem(ui->valori->text()));//=
        i++;// Sums one number for the row counter.
        if(i==4){ //If the row counter reaches this limit:
            ui->Agrega->setDisabled(true); //The start button enables.
            ui->Inicia->setDisabled(false); //The add button disables.
        }
}
void Gauss::ejecutar(){// This slot starts the method.
    for(i=4;i>=0;i--){// This cycle analyzes if the first row of the main matrix have zeros.
            if(matriz[0][i]==0){//If it haves zeros:
                // Exchanges row positions for the independent variables.
                ind1=indep[0][0];// A temporal variable takes the value of first independent variable.
                ind2=indep[i+1][0];// Another temporal variable takes the value of the next independent variable.
                for(j=0;j<4;j++){// This cycle exchanges row positions for the x variables.
                    tempo[0][j]=matriz[0][j];// A temporal matrix saves the first row.
                    tempo2[0][j]=matriz[i+1][j];// Another temporal matrix saves the next row.
                    matriz[i+1][j]=tempo[0][j];// Puts the first row on the next row.
                    matriz[0][j]=tempo2[0][j];// Puts the next row on the first row.
                    indep[i+1][0]=ind1;// Puts the first independent variable on next row.
                    indep[0][0]=ind2;// Puts the next variable on previous row.
                }
            }
        }
    // The method starts.
    for(i=0;i<4;i++){//This cycle analyzes rows.
        for(j=0;j<i;j++){//This cycle analyzes columns.
            // This line turns zero the matrix position.
            matriz[i][j]=(matriz[i][j]-(matriz[0][j]*(matriz[i][j]/matriz[0][j])));
        }
    }
    x4=(indep[3][0]/matriz[3][3]);//Finds the x4 value.
    x3=(indep[2][0]-(matriz[2][3]*x4))/(matriz[2][2]);//Finds the x3 value, with the previos variable.
    //Finds the x2 variable, with the two previous variables.
    x2=(indep[1][0]-(matriz[1][2]*x3)-(matriz[1][3]*x4))/(matriz[1][1]);
    //Finds the x1 value, with the three previous variables.
    x1=(indep[0][0]-(matriz[0][1]*x2)-(matriz[0][2]*x3)-(matriz[0][3]*x4))/(matriz[0][0]);
    //Show all the found values, on a independent LCD number.
    ui->show1->display(x1);
    ui->show2->display(x2);
    ui->show3->display(x3);
    ui->show4->display(x4);
}
void Gauss::limpiar(){// This slot clears all the user interface fields, when the clear button been clicked.
    //Clears all spinboxes
    ui->valorx1->setValue(0.0);
    ui->valorx2->setValue(0.0);
    ui->valorx3->setValue(0.0);
    ui->valorx4->setValue(0.0);
    ui->valori->setValue(0.0);
    ui->Tabla->clearContents();// Clears the table widget contents.
    // Clears all the LCD numbers.
    ui->show1->display(0.0);
    ui->show2->display(0.0);
    ui->show3->display(0.0);
    ui->show4->display(0.0);
    ui->Inicia->setDisabled(true);// Disables the start button .
    ui->Agrega->setDisabled(false);// Enables the add button.
    i=0;// The row counter goes to zero, for start over the data introduction.
}

Gauss::~Gauss()
{
    delete ui;
}
