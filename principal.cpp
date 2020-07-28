/*Autor: Joselyn Chérrez
 *
 * PROGRAMACIÓN ORIENTADA A OBJETOS
 *
 */

#include "principal.h"
#include "ui_principal.h"
#include "tareas.h"
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    inicializarDatos();
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_actionAgregar_triggered()
{

    Agregar *ventana1 = new Agregar(this);
    ventana1->setModal(true);
    ventana1->show();
}
void Principal::inicializarDatos()
{
    m_tipo.append(new Tareas(1,tr("Universidad")));
    m_tipo.append(new Tareas(2,tr("Familiar")));
    m_tipo.append(new Tareas(3,tr("Personales")));
    inicializarWidgets();
}

void Principal::inicializarWidgets()
{
    /*for (int i = 0; i< m_tipo.length(); ++i) {
        ui->inTipo->addItem(m_tipo.at(i)->tipo());
    }*/

    QStringList cabecera = {tr("#"),tr("Nombre"),tr("Tipo"),tr("Fecha")};
    QString nombre;
    ui->outTareas->setColumnCount(4);
    ui->outTareas->setHorizontalHeaderLabels(cabecera);
    /*int index = ui->inTipo->currentIndex();
    Tareas *t = m_tipo.at(index);*/

   int posicion = ui->outTareas->rowCount();
   ui->outTareas->insertRow(posicion);
   ui->outTareas->setItem(posicion,0, new QTableWidgetItem(nombre));
   //ui->outTareas->setItem(posicion,1,new QTableWidgetItem(t->tipo()));

}

void Principal::on_actionSalir_triggered()
{
       this->close();

}

void Principal::on_actionFinalizar_triggered()
{
       QMessageBox msgBox;
    msgBox.setText(tr("Tarea Finalizada.."));
    msgBox.addButton(tr("Listo"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("Cancelar"), QMessageBox::RejectRole);

    int guardar = msgBox.exec();
    switch (guardar) {
    case QMessageBox::AcceptRole:
        break;
    case QMessageBox::RejectRole:
        break;
    default:
        break;
    }
}
