/*Autor: Joselyn Chérrez
 *
 * PROGRAMACIÓN ORIENTADA A OBJETOS
 *
 */

#include "agregar.h"
#include "ui_agregar.h"
#include <QDate>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Agregar::Agregar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar)
{
    ui->setupUi(this);
    inicializarDatos();
    connect(ui->cmdAgregar, SIGNAL(clicked(bool)),
            this, SLOT(agregar()));
}

Agregar::~Agregar()
{
    delete ui;

}

void Agregar::inicializarDatos()
{

    //Combo box
    m_tipo.append(new Tareas(1,tr("Universidad")));
    m_tipo.append(new Tareas(2,tr("Familiar")));
    m_tipo.append(new Tareas(3,tr("Personales")));
    m_tipo.append(new Tareas(4,tr("Compras")));
    m_tipo.append(new Tareas(5,tr("Habitación")));
    m_tipo.append(new Tareas(6,tr("Casa en General")));

    inicializarWidgets();
}

void Agregar::inicializarWidgets()
{
    for (int i = 0; i< m_tipo.length(); ++i) {
        ui->inTipo->addItem(m_tipo.at(i)->tipo());
    }

    QStringList cabecera = {tr("Nombre"),tr("Tipo"),tr("Fecha")};
    ui->outDetalle_tareas->setColumnCount(3);
    ui->outDetalle_tareas->setHorizontalHeaderLabels(cabecera);

}

void Agregar::agregar()
{

    //Obtener datos

    QString nombre = ui->inNombre->text();
    QDate fecha=ui->dateEdit->date();
    int index = ui->inTipo->currentIndex();
    Tareas *t = m_tipo.at(index);

   int posicion = ui->outDetalle_tareas->rowCount();
   ui->outDetalle_tareas->insertRow(posicion);
   ui->outDetalle_tareas->setItem(posicion,0, new QTableWidgetItem(nombre));
   ui->outDetalle_tareas->setItem(posicion,1,new QTableWidgetItem(t->tipo()));
   ui->outDetalle_tareas->setItem(posicion,2,new QTableWidgetItem(fecha.toString()));

   //La aplicación guardará automaticamente la nueva tarea
   QMessageBox mensajeBox;
           QString fileName = "Tareas.csv";
               if (fileName.isEmpty()) {
                   return;
               }

               QFile file(fileName);
               if (!file.open(QIODevice::WriteOnly |   QFile::Text)) {
                   QMessageBox::information(this, tr("No se puede abrir el archivo"),
                   file.errorString());
                   return;
               }

               QTextStream out(&file);
               int rowCount = ui->outDetalle_tareas->rowCount();
               int colCount = ui->outDetalle_tareas->columnCount();

               for (int i = 0; i < rowCount; i++) {

                   for (int j = 0; j < colCount; j++) {
                       if (j > 0) {
                           out << ";";
                       }
                       QTableWidgetItem* item = ui->outDetalle_tareas->item(i,j);
                       out << item->data(Qt::DisplayRole).toString();
                   }
                   out << "\n";
               }
               mensajeBox.setText(tr("Se guardó en el archivo:") + fileName);
               mensajeBox.exec();


}



void Agregar::on_buttonBox_accepted()
{
    this->accept();
}

void Agregar::on_buttonBox_rejected()
{
    this->reject();
}
//Prioridad
void Agregar::on_inAlta_clicked()
{
    ui->inAlta->setStyleSheet("color : red");
}

void Agregar::on_inMedia_clicked()
{
    ui->inMedia->setStyleSheet("color: orange");
}

void Agregar::on_inBaja_clicked()
{
    ui->inBaja->setStyleSheet("color: yellow");
}
