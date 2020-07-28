/*Autor: Joselyn Chérrez
 *
 * PROGRAMACIÓN ORIENTADA A OBJETOS
 *
 */

#include "tareas.h"


Tareas::Tareas(QObject *parent) : QObject(parent)
{
    m_numero = 0;
    m_tipo = "";

}

Tareas::Tareas(int numero,QString tipo){
    m_numero = numero;
    m_tipo = tipo;


}
int Tareas::numero() const
{
    return m_numero;
}

QString Tareas::nombre() const
{
    return  m_nombre;
}

int Tareas::prioridad() const
{
    return m_prioridad;
}

QString Tareas::tipo() const
{
    return m_tipo;
}
