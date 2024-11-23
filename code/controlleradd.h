#ifndef CONTROLLERADD_H
#define CONTROLLERADD_H

#include "controller.h"

/**
 * @brief Contrôleur pour l'ajout d'étudiants
 * @details Hérite de Controller, gère l'ajout d'un étudiant dans la promo.
 */
class ControllerAdd : public Controller
{
public:
    /**
     * @brief Constructeur
     * @param _promo Instance de Promotion
     * @param _id Champ de l'identifiant
     * @param _firstname Champ du prénom
     * @param _lastname Champ du nom
     * @param _bac Liste des bacs
     * @param _departement Liste des départements
     */
    ControllerAdd(Promotion* _promo, QLineEdit* _id, QLineEdit* _firstname, QLineEdit* _lastname, QComboBox* _bac, QComboBox* _departement);

    /**
     * @brief Contrôle l'ajout d'un étudiant
     */
    void control() override;

private:
    Promotion* promo; /**< Référence à la promotion */
    QLineEdit* id; /**< Champ pour l'ID */
    QLineEdit* firstname; /**< Champ pour le prénom */
    QLineEdit* lastname; /**< Champ pour le nom */
    QComboBox* bac; /**< Liste déroulante des bacs */
    QComboBox* departement; /**< Liste déroulante des départements */
};

#endif // CONTROLLERADD_H
