#ifndef CONTROLLERREMOVEID_H
#define CONTROLLERREMOVEID_H

#include "controller.h"

/**
 * @brief Contrôleur pour supprimer un étudiant par ID
 * @details Hérite de Controller, supprime un étudiant de la promo via l'ID.
 */
class ControllerRemoveId : public Controller
{
public:
    /**
     * @brief Constructeur
     * @param lineEdit Champ pour l'ID à supprimer
     * @param promotion Instance de Promotion
     */
    ControllerRemoveId(QLineEdit* lineEdit, Promotion* promotion);

    /**
     * @brief Contrôle la suppression d'un étudiant par ID
     */
    void control() override;

private:
    QLineEdit *lineEdit; /**< Champ pour l'ID à supprimer */
    Promotion *promo; /**< Référence à la promotion */
};

#endif // CONTROLLERREMOVEID_H
