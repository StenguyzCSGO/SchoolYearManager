#include "viewPieChart.h"

/**
 * @brief Constructeur de la classe ViewPieChart
 * @param _promo L'objet Promotion qui contient les données des étudiants
 * @param _widget Le widget où le graphique en secteurs (pie chart) sera affiché
 * Initialise la classe, crée le graphique en secteurs et ajoute la série de données pour la répartition géographique des départements.
 */
ViewPieChart::ViewPieChart(Promotion* _promo, QWidget* _widget)
    : promo(_promo), widget(_widget), series(new QPieSeries())
{
    QChart* pieChart = new QChart();
    pieChart->addSeries(series);
    pieChart->setTitle("Répartition géographique des départements");
    pieChart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView* chartView = new QChartView(pieChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(chartView, 0, 0);
    layout->setContentsMargins(0, 0, 0, 0);

    widget->setLayout(layout);

    update();
}

/**
 * @brief Met à jour les données du graphique en secteurs avec les informations des départements
 * Vide la série actuelle et ajoute les tranches du graphique basées sur la répartition des départements dans la promotion.
 */
void ViewPieChart::update()
{
    series->clear();

    QMap<QString, int> departmentCounts = promo->getDepartementList();

    for (auto depIt = departmentCounts.constBegin(); depIt != departmentCounts.constEnd(); ++depIt)
    {
        QString department = depIt.key();  // Nom  département
        int count = depIt.value();  // Nb etu a ce departemejt

        QPieSlice* slice = series->append(department, count);

        slice->setLabelVisible(true);
        slice->setLabel(department + " : " + QString::number(count));

        slice->setLabelPosition(QPieSlice::LabelOutside);
        slice->setLabelArmLengthFactor(0.25);
    }

    widget->repaint();
}
