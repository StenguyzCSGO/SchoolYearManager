#pragma once
#include "promotion.h"
#include <QWidget>
#include <QBarSeries>
#include <QChart>
#include <QChartView>
#include <QGridLayout>
#include <QValueAxis>
#include <QBarCategoryAxis>
#include <QBarSet>

QT_USE_NAMESPACE

    /**
 * @brief Vue histogramme pour afficher la répartition des bacs
 * @details Affiche un graphique en barres des bacs d'une promotion
 */
    class ViewHistogram : public QObject, public Observer
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param _promo Promotion des étudiants
     * @param _widget Widget où afficher le graphique
     */
    ViewHistogram(Promotion* _promo, QWidget* _widget);

    /**
     * @brief Met à jour l'histogramme selon les données de la promotion
     */
    void update() override;

private:
    Promotion* promo; /**< Promotion des étudiants */
    QWidget* widget; /**< Widget contenant l'histogramme */
    QBarSeries* series; /**< Série de barres à afficher */
    QValueAxis* axisY; /**< Axe des valeurs (axe Y) */
};
