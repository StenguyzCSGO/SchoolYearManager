#include "viewList.h"
#include <QListWidgetItem>

/**
 * @brief Constructeur de la classe ViewList
 * @param listWidget Le widget de type QListWidget où afficher la liste des étudiants
 * @param _promotion L'objet Promotion qui contient la liste des étudiants
 * Initialise la classe en créant un contrôleur pour la suppression des étudiants et en mettant à jour la vue avec les étudiants actuels.
 */
ViewList::ViewList(QListWidget* listWidget, Promotion* _promotion)
    : list(listWidget), promo(_promotion)
{
    controllerRemoveList = new ControllerRemoveList(listWidget, _promotion);  // Crée un contrôleur pour la suppression
    update();
}

/**
 * @brief Met à jour la liste des étudiants dans le QListWidget
 * Vide la liste actuelle du QListWidget et y ajoute la liste des étudiants de la promotion.
 */
void ViewList::update()
{
    list->clear();
    list->addItems(promo->getList());
}

/**
 * @brief Supprime les étudiants sélectionnés dans la liste
 * Appelle le contrôleur pour supprimer les étudiants sélectionnés de la liste de la promotion.
 */
void ViewList::removeList()
{
    controllerRemoveList->control();
}
