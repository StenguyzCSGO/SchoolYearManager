#include "student.h"

/**
 * @brief Constructeur de la classe Student
 * @param cardID L'ID de l'étudiant
 * @param firstname Le prénom de l'étudiant
 * @param lastname Le nom de l'étudiant
 * @param bac Le bac de l'étudiant
 * @param department Le département de l'étudiant
*/
Student::Student(QString cardID, QString firstname, QString lastname, QString bac, QString department):
    cardID(cardID), firstname(firstname), lastname(lastname), bac(bac), department(department)
{
}

/**
 * @brief Afficher les informations d'un étudiant
 * @param os Flux de sortie
 * @param dt L'étudiant à afficher
 * @return Flux de sortie mis à jour
*/
QDebug operator<<(QDebug os, const Student& dt)
{
    os << dt.cardID << " " << dt.firstname << " " << dt.lastname << " " << dt.bac << " " << dt.department;

    return os;
}
