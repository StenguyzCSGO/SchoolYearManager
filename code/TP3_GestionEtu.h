#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TP3_GestionEtu.h"
#include "promotion.h"
#include "viewList.h"
#include "viewForms.h"
#include "viewPieChart.h"
#include "viewHistogram.h"

/**
 * @brief Classe principale de l'application de gestion des étudiants
 * @details Gère l'interface et la logique de l'application
 */
class TP3_GestionEtu : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur
     * @param parent Parent du widget
     */
    TP3_GestionEtu(QWidget *parent = nullptr);

    /**
     * @brief Destructeur
     */
    ~TP3_GestionEtu();

private:
    Ui::TP3_GestionEtuClass ui; /**< Interface utilisateur */
    Promotion* promo; /**< Promotion des étudiants */

    ViewList* listView; /**< Vue liste des étudiants */
    ViewForms* listForm; /**< Vue formulaire des étudiants */
    ViewPieChart* pieChartView; /**< Vue graphique en camembert */
    ViewHistogram* histogramView; /**< Vue graphique en histogramme */
};
