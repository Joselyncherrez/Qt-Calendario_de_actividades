/*Autor: Joselyn Chérrez
 *
 * PROGRAMACIÓN ORIENTADA A OBJETOS
 *
 */

#ifndef AGREGAR_H
#define AGREGAR_H

#include <QDialog>
#include "tareas.h"

namespace Ui {
class Agregar;
}

class Agregar : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar(QWidget *parent = nullptr);
    ~Agregar();

private:
    Ui::Agregar *ui;
    QList<Tareas*> m_tipo;
    Tareas *tareas;
    void inicializarDatos();
    void inicializarWidgets();

public slots:
    void agregar();



private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_inAlta_clicked();
    void on_inMedia_clicked();
    void on_inBaja_clicked();
};

#endif // AGREGAR_H
