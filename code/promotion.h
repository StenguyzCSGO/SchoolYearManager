#pragma once
#include <QList>
#include <QDebug>
#include "student.h"
#include "observer.h"

/**
 * @brief Gestion des étudiants dans une promotion
 * @details Contient la liste des étudiants et permet de les ajouter, supprimer et retrouver
 */
class Promotion : public Observable
{
private:
    QList<Student> students; /**< Liste des étudiants */

public:
    /**
     * @brief Constructeur avec chargement d'un fichier
     * @param filename Fichier contenant les étudiants à charger
     */
    Promotion(QString filename);

    /**
     * @brief Destructeur
     */
    ~Promotion() { qDebug() << "[-] Promotion"; }

    /**
     * @brief Ajoute un étudiant
     * @param student Étudiant à ajouter
     */
    void add(const Student&);

    /**
     * @brief Supprime un étudiant
     * @param student Étudiant à supprimer
     */
    void remove(const Student&);

    /**
     * @brief Supprime un étudiant par son ID
     * @param id ID de l'étudiant à supprimer
     */
    void remove(const QString &);

    /**
     * @brief Trouve un étudiant par son nom
     * @param name Nom de l'étudiant à rechercher
     * @return L'étudiant correspondant
     */
    Student find(QString) const;

    /**
     * @brief Retourne la liste des étudiants sous forme de QStringList
     * @return Liste des étudiants
     */
    QStringList getList() const;

    /**
     * @brief Surcharge de l'opérateur << pour afficher la promotion
     * @param os Flux de sortie
     * @param dt Promotion à afficher
     * @return Flux modifié
     */
    friend QDebug operator<<(QDebug os, const Promotion& dt);

    /**
     * @brief Retourne une map des bacs avec le nombre d'étudiants par bac
     * @return QMap des bacs
     */
    QMap<QString, int> getBacList() const;

    /**
     * @brief Retourne une map des départements avec le nombre d'étudiants par département
     * @return QMap des départements
     */
    QMap<QString, int> getDepartementList() const;
};

/**
 * @brief Surcharge de l'opérateur << pour afficher la promotion
 * @param os Flux de sortie
 * @param dt Promotion à afficher
 * @return Flux modifié
 */
QDebug operator<<(QDebug os, const Promotion& dt);
