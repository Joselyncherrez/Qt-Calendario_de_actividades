/*Autor: Joselyn Chérrez
 *
 * PROGRAMACIÓN ORIENTADA A OBJETOS
 *
 */

#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <agregar.h>
#include "tareas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionAgregar_triggered();

    void on_actionSalir_triggered();

    void on_actionFinalizar_triggered();

private:
    Ui::Principal *ui;
    QList<Tareas*> m_tipo;
        Tareas *tareas;
        void inicializarDatos();
        void inicializarWidgets();

    public slots:
      //  void agregar();
};
#endif // PRINCIPAL_H
