#include "controllerremoveid.h"

/**
 * @brief Constructeur du contrôleur de suppression d'étudiant par ID
 * @param lineEdit Champ pour saisir l'ID de l'étudiant à supprimer
 * @param promotion Référence vers la promotion
 */
ControllerRemoveId::ControllerRemoveId(QLineEdit *lineEdit, Promotion *promotion)
    : lineEdit(lineEdit), promo(promotion)
{
}

/**
 * @brief Méthode qui gère la suppression d'un étudiant par son ID
 * Vérifie que l'ID est valide et supprime l'étudiant si trouvé.
 */
void ControllerRemoveId::control()
{
    QString text = lineEdit->text();
    if (!text.isEmpty()) {
        if (text.length() == 3 && text.contains(QRegularExpression("^[0-9]{3}$"))) {
            promo->remove(promo->find(text));
            promo->notifyObserver();
        }
    }
}
