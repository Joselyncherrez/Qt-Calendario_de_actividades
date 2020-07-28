/*Autor: Joselyn Chérrez
 *
 * PROGRAMACIÓN ORIENTADA A OBJETOS
 *
 */
#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Obejto para manejar las traducciones
    QTranslator traduccion;
    //Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas <<"Inglés" << "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                   "Idioma",
                                   "Seleccione un idioma",
                                   idiomas);
    //Dependiendo del idioma seleccionado, carga el archivo de traduccion
    if (idiomaSeleccionado == "Inglés"){
        traduccion.load(":/Calendario_de_tareas_en.qm");
    }
    //Si es diferente de español, se instala la traduccion en TODA la aplicacion
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traduccion);
    }

    //Muestra la ventana principal
    Principal w;
    w.show();
    return a.exec();
}
