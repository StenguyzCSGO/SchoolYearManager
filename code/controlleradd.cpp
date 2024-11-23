#include "controlleradd.h"

/**
 * @brief Constructeur du contrôleur d'ajout d'étudiant
 * @param _promo Référence vers la promotion
 * @param _id Champ pour l'identifiant de l'étudiant
 * @param _firstname Champ pour le prénom de l'étudiant
 * @param _lastname Champ pour le nom de l'étudiant
 * @param _bac ComboBox pour le bac de l'étudiant
 * @param _departement ComboBox pour le département de l'étudiant
 */
ControllerAdd::ControllerAdd(Promotion* _promo, QLineEdit* _id, QLineEdit* _firstname, QLineEdit* _lastname, QComboBox* _bac, QComboBox* _departement)
    : promo(_promo), id(_id), firstname(_firstname), lastname(_lastname), bac(_bac), departement(_departement)
{

}

/**
 * @brief Méthode qui gère l'ajout d'un étudiant à la promotion
 * Vérifie les champs, formate les champs, et ajoute l'étudiant si tout est valide.
 */
void ControllerAdd::control()
{
    QRegularExpression regex("[^a-zA-Z0-9]");
    QString studentId = id->text().trimmed();
    QString studentFirstname = firstname->text().trimmed().replace(regex, "").toUpper();
    QString studentLastname = lastname->text().trimmed().replace(regex, "").toUpper();
    QString studentBac = bac->currentText().trimmed();
    QString studentDepartement = departement->currentText().trimmed();

    if (studentId.isEmpty()) {
        QMessageBox::warning(0, "Erreur", "Veuillez saisir l'identifiant de l'étudiant.");
        return;
    }
    Student existingStudent = promo->find(studentId);
    if (!existingStudent.getCardID().isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Un étudiant avec cet identifiant existe déjà.");
        return;
    }
    if (studentFirstname.isEmpty()) {
        QMessageBox::warning(0, "Erreur", "Veuillez saisir le prénom de l'étudiant.");
        return;
    }
    if (studentLastname.isEmpty()) {
        QMessageBox::warning(0, "Erreur", "Veuillez saisir le nom de l'étudiant.");
        return;
    }
    if (studentBac.isEmpty()) {
        QMessageBox::warning(0, "Erreur", "Veuillez sélectionner le bac de l'étudiant.");
        return;
    }
    if (studentDepartement.isEmpty()) {
        QMessageBox::warning(0, "Erreur", "Veuillez sélectionner le département de l'étudiant.");
        return;
    }
    Student newStudent(studentId, studentFirstname, studentLastname, studentBac, studentDepartement);
    promo->add(newStudent);
    promo->notifyObserver();
}
