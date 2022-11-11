#include "superpaintmw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SuperPaintMW w;
    w.show();

    return a.exec();
}

/*
 * Coder les méthodes Contains des graphicobjects
 * Finir la sélection
 */


/* TODO LIST GENERALE :
 * Finir les objets graphiques
 * Selections & modifications objets
 * Changer l'épaisseur des lignes....
 * Remplissages et couleurs
 * Ne pas avoir a recliquer sur le boutton pour continuer de dessiner
 * Exportations/importations
 * Prendre en compte les modificateurs (ctrl, shift, alt...)
 * Changer le curseur, icones, habillages.....
 *
 */
