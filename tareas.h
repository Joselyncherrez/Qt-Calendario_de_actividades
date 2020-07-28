/*Autor: Joselyn Chérrez
 *
 * PROGRAMACIÓN ORIENTADA A OBJETOS
 *
 */

#ifndef TAREAS_H
#define TAREAS_H

#include <QObject>
#include <QDateTimeEdit>


class Tareas : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nombre READ nombre )
    Q_PROPERTY(int prioridad READ prioridad)
    Q_PROPERTY(QString tipo READ tipo)


public:
    explicit Tareas(QObject *parent = nullptr);
    Tareas(int numero,QString tipo);

    // getters
    int numero()const;
    QString nombre() const;
    int prioridad()const;
    QString tipo()const;

    //Setters

signals:


private:
    QString m_nombre;
    int m_prioridad;
    QString m_tipo;
    int m_numero;

};

#endif // TAREAS_H
