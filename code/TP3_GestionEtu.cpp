#include "TP3_GestionEtu.h"
#include <QDir>

/**
 * @brief Constructeur de la classe TP3_GestionEtu
 * @param parent Le widget parent (optionnel)
 * Initialise l'interface utilisateur, crée la promotion à partir du fichier CSV, crée les vues (graphique, liste, formulaires),
 * et établit les connexions avec les boutons pour les actions de suppression et d'ajout d'étudiant.
 */
TP3_GestionEtu::TP3_GestionEtu(QWidget *parent)
    : QMainWindow(parent), promo(nullptr)
{
    ui.setupUi(this);
    this->showMaximized();

    // Créer la promotion
    promo = new Promotion("promoDUT.csv");

    // Créer les graphiques
    ViewPieChart* viewPieChart = new ViewPieChart(promo, ui.groupBox_department);
    ViewHistogram* viewHistogram = new ViewHistogram(promo, ui.groupBox_bacs);

    // Créer les vues
    listView = new ViewList(ui.listWidget, promo);
    listForm = new ViewForms(promo, ui.lineEdit_remove_number, ui.lineEdit_add_number, ui.lineEdit_add_firstname, ui.lineEdit_add_lastname, ui.lineEdit_add_BAC, ui.lineEdit_add_department);

    // Ajouter les vues comme observateurs
    connect(ui.pushButton_delete_list, &QPushButton::clicked, listView, &ViewList::removeList);
    connect(ui.pushButton_delete_number, &QPushButton::clicked, listForm, &ViewForms::removeId);
    connect(ui.pushButton_addStudent, &QPushButton::clicked, listForm, &ViewForms::add);

    // Gérer les observateurs
    promo->addObserver(listView);
    promo->addObserver(viewPieChart);
    promo->addObserver(viewHistogram);
}

/**
 * @brief Destructeur de la classe TP3_GestionEtu
 * Libère la mémoire allouée pour l'objet promo.
 */
TP3_GestionEtu::~TP3_GestionEtu(){
    delete promo;
}
