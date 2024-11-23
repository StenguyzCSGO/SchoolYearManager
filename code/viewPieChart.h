#pragma once
#include "promotion.h"
#include <QWidget>
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QGridLayout>
#include <QChartGlobal>

QT_USE_NAMESPACE

    /**
 * @brief Classe pour gérer la vue du graphique en camembert
 * @details Affiche et met à jour un graphique en camembert des données de la promotion
 */
    class ViewPieChart : public QObject, public Observer
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param _promo Promotion des étudiants
     * @param _widget Widget pour afficher le graphique
     */
    ViewPieChart(Promotion* _promo, QWidget* _widget);

    /**
     * @brief Met à jour le graphique en fonction des données de la promotion
     */
    void update() override;

private:
    Promotion* promo; /**< Promotion des étudiants */
    QWidget* widget; /**< Widget pour afficher le graphique */
    QPieSeries* series; /**< Série de données pour le graphique en camembert */
};
