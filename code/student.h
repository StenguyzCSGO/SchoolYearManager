#pragma once
#include <QDebug>
#include <QString>

/**
 * @brief Infos d'un étudiant
 * @details Contient les données personnelles d'un étudiant
 */
class Student
{
private:
    QString cardID; /**< ID de la carte étudiante */
    QString firstname; /**< Prénom de l'étudiant */
    QString lastname; /**< Nom de l'étudiant */
    QString bac; /**< Bac de l'étudiant */
    QString department; /**< Département de l'étudiant */

public:
    /**
     * @brief Constructeur d'un étudiant
     * @param cardID ID de la carte étudiante
     * @param firstname Prénom de l'étudiant
     * @param lastname Nom de l'étudiant
     * @param bac Bac de l'étudiant
     * @param department Département de l'étudiant
     */
    Student(QString =QString(), QString =QString(), QString =QString(), QString =QString(), QString =QString());

    /**
     * @brief Retourne l'ID de la carte étudiante
     * @return ID de la carte étudiante
     */
    const QString getCardID() const { return cardID; }

    /**
     * @brief Retourne le prénom de l'étudiant
     * @return Prénom de l'étudiant
     */
    const QString getFirstname() const { return firstname; }

    /**
     * @brief Retourne le nom de l'étudiant
     * @return Nom de l'étudiant
     */
    const QString getLastname() const { return lastname; }

    /**
     * @brief Retourne le bac de l'étudiant
     * @return Bac de l'étudiant
     */
    const QString getBac() const { return bac; }

    /**
     * @brief Retourne le département de l'étudiant
     * @return Département de l'étudiant
     */
    const QString getDepartment() const { return department; }

    /**
     * @brief Retourne une représentation textuelle de l'étudiant
     * @return Texte représentant l'étudiant
     */
    const QString getText() const { return cardID + " - " + lastname + " " + firstname + " (" + department + ")"; }

    /**
     * @brief Surcharge de l'opérateur << pour afficher un étudiant
     * @param os Flux de sortie
     * @param dt Étudiant à afficher
     * @return Flux modifié
     */
    friend QDebug operator<<(QDebug os, const Student& dt);
};

/**
 * @brief Surcharge de l'opérateur << pour afficher un étudiant
 * @param os Flux de sortie
 * @param dt Étudiant à afficher
 * @return Flux modifié
 */
QDebug operator<<(QDebug os, const Student& dt);
