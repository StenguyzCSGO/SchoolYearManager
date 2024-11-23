#include "viewForms.h"

/**
 * @brief Constructeur de la classe ViewForms
 * @param _promo L'objet Promotion pour accéder à la liste des étudiants
 * @param _lineEdit Le champ de texte pour la suppression d'un étudiant
 * @param _id Le champ de texte pour l'ID de l'étudiant à ajouter
 * @param _firstname Le champ de texte pour le prénom de l'étudiant
 * @param _lastname Le champ de texte pour le nom de l'étudiant
 * @param _bac La combobox pour choisir le bac de l'étudiant
 * @param _departement La combobox pour choisir le département de l'étudiant
 * Crée les objets contrôleurs et appelle les méthodes d'initialisation et de mise à jour.
 */
ViewForms::ViewForms(Promotion *_promo, QLineEdit* _lineEdit, QLineEdit *_id, QLineEdit *_firstname, QLineEdit *_lastname, QComboBox *_bac, QComboBox *_departement)
    : promo(_promo), lineEdit(_lineEdit), id(_id), firstname(_firstname), lastname(_lastname), bac(_bac), departement(_departement)
{
    controllerRemoveId = new ControllerRemoveId(lineEdit, promo);
    controllerAdd = new ControllerAdd(promo, id, firstname, lastname, bac, departement);
    init();
    update();
}

/**
 * @brief Initialise les éléments de la vue des formulaires
 * Ajoute les items pour le bac et charge les départements depuis le fichier CSV dans la combobox correspondante.
 */
void ViewForms::init()
{
    QStringList listBAC;
    listBAC << "S" << "ES" << "L" << "STI";
    bac->addItems(listBAC);

    // Lecture du fichier departement.csv
    QString filePath = QDir::currentPath() + "/../../../data/departement.csv";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Erreur", "Impossible d'ouvrir le fichier des departements francais : " + filePath);
        return;
    }

    QTextStream in(&file);
    departement->clear(); // clear la combobox avant de la remplir pour etre sur

    while (!in.atEnd()) {
        QString line = in.readLine();
        // Skip les lignes vides
        if (line.trimmed().isEmpty())
            continue;

        // Split la ligne en plusieurs colonnes en utilisant le séparateur ','
        QStringList columns = line.split(',');

        // Ajouter à la combobox le département
        QString numero = columns[1].remove('"').trimmed();
        departement->addItem(numero);
    }
    file.close();
}

/**
 * @brief Met à jour les champs du formulaire
 * Efface les champs d'ID, prénom, nom, et réinitialise les combobox.
 */
void ViewForms::update()
{
    id->clear();
    firstname->clear();
    lastname->clear();

    // Désélectionner les combobox
    bac->setCurrentIndex(-1);
    departement->setCurrentIndex(-1);
}

/**
 * @brief Ajoute un étudiant
 * Appelle la méthode de contrôle du contrôleur d'ajout pour ajouter un étudiant.
 */
void ViewForms::add() {
    controllerAdd->control();
}

/**
 * @brief Supprime un étudiant par son ID
 * Appelle la méthode de contrôle du contrôleur de suppression d'ID.
 */
void ViewForms::removeId()
{
    controllerRemoveId->control();
}
