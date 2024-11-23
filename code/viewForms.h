#pragma once
#include <QObject>
#include <QDir>
#include "controlleradd.h"
#include "controllerremoveid.h"

/**
 * @brief Vue des formulaires de gestion des étudiants
 * @details Permet l'ajout et la suppression des étudiants via des formulaires
 */
class ViewForms : public QObject, public Observer
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param _promo Promotion des étudiants
     * @param _lineEdit Champ pour saisir l'ID
     * @param _id Champ pour saisir l'ID de l'étudiant
     * @param _firstname Champ pour saisir le prénom
     * @param _lastname Champ pour saisir le nom
     * @param _bac ComboBox pour sélectionner le bac
     * @param _departement ComboBox pour sélectionner le département
     */
    ViewForms(Promotion* _promo, QLineEdit* _lineEdit, QLineEdit* _id, QLineEdit* _firstname, QLineEdit* _lastname, QComboBox* _bac, QComboBox* _departement);

    /**
     * @brief Initialise la vue
     */
    void init();

    /**
     * @brief Met à jour la vue lors des changements
     */
    void update() override;

    /**
     * @brief Ajoute un étudiant à la promotion
     */
    void add();

    /**
     * @brief Supprime un étudiant par ID
     */
    void removeId();

private:
    Promotion* promo; /**< Promotion des étudiants */
    ControllerAdd* controllerAdd; /**< Contrôleur pour l'ajout */
    ControllerRemoveId* controllerRemoveId; /**< Contrôleur pour la suppression par ID */
    QLineEdit* lineEdit; /**< Champ de texte pour l'ID */
    QLineEdit* id; /**< Champ de texte pour l'ID étudiant */
    QLineEdit* firstname; /**< Champ de texte pour le prénom */
    QLineEdit* lastname; /**< Champ de texte pour le nom */
    QComboBox* bac; /**< ComboBox pour le bac */
    QComboBox* departement; /**< ComboBox pour le département */
};
