#include "controllerremovelist.h"

/**
 * @brief Constructeur du contrôleur de suppression d'étudiant par sélection dans la liste
 * @param listWidget Liste contenant les étudiants
 * @param promotion Référence vers la promotion
 */
ControllerRemoveList::ControllerRemoveList(QListWidget *listWidget, Promotion *_promotion)
    : list(listWidget), promo(_promotion)
{
}

/**
 * @brief Méthode qui gère la suppression d'étudiants sélectionnés dans la liste
 * Supprime les étudiants sélectionnés dans la liste et met à jour la vue.
 */
void ControllerRemoveList::control()
{
    QList<QListWidgetItem*> selectedItem = list->selectedItems();
    if (!selectedItem.isEmpty()) {
        for (QListWidgetItem* item : selectedItem) {
            QString studentText = item->text();
            promo->remove(studentText);
        }
        promo->notifyObserver();
    }
}
