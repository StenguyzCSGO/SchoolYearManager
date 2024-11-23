#include "TP3_GestionEtu.h"
#include "promotion.h"
#include <QApplication>
#include <QDebug>

/**
 * @brief Point d'entrée de l'application
 * Initialisation de l'application Qt et affichage de l'interface.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Interface (data are loaded here)
    TP3_GestionEtu w;
    w.show();

    return a.exec();
}
