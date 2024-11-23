#pragma once
#include <QListWidget>
#include <QLineEdit>
#include <QObject>
#include "promotion.h"
#include "controllerremovelist.h"

/**
 * @brief Classe pour gérer la vue de liste d'étudiants
 * @details Affiche et met à jour la liste des étudiants dans un QListWidget
 */
class ViewList :public QObject, public Observer
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param listWidget Liste d'affichage des étudiants
     * @param _promotion Promotion des étudiants
     */
    ViewList(QListWidget* listWidget, Promotion* _promotion);

    /**
     * @brief Met à jour la liste des étudiants affichée
     */
    void update() override;

    /**
     * @brief Supprime l'étudiant sélectionné de la liste
     */
    void removeList();

private:
    QListWidget* list; /**< Liste des étudiants affichée */
    Promotion* promo; /**< Promotion des étudiants */
    ControllerRemoveList* controllerRemoveList; /**< Contrôleur pour la suppression d'un étudiant */
};
