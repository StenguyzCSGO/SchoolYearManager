#ifndef CONTROLLERREMOVELIST_H
#define CONTROLLERREMOVELIST_H

#include "controller.h"

/**
 * @brief Contrôleur pour supprimer un étudiant via une liste
 * @details Hérite de Controller, supprime un étudiant sélectionné dans une liste.
 */
class ControllerRemoveList : public Controller
{
public:
    /**
     * @brief Constructeur
     * @param listWidget Liste d'étudiants à partir de laquelle supprimer
     * @param _promotion Instance de Promotion
     */
    ControllerRemoveList(QListWidget* listWidget, Promotion* _promotion);

    /**
     * @brief Contrôle la suppression d'un étudiant via la liste
     */
    void control() override;

private:
    QListWidget* list; /**< Liste des étudiants */
    Promotion* promo; /**< Référence à la promotion */
};

#endif // CONTROLLERREMOVELIST_H
