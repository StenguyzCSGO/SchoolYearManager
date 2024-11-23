#include "viewHistogram.h"

/**
 * @brief Constructeur de la classe ViewHistogram
 * @param _promo L'objet Promotion pour accéder aux données des étudiants
 * @param _widget Le widget dans lequel afficher le graphique
 * Initialise le graphique en créant une série de barres, un axe X pour le bac, et un axe Y pour le nombre d'étudiants.
 * Le graphique est ensuite ajouté à un layout qui est attribué au widget.
 */
ViewHistogram::ViewHistogram(Promotion* _promo, QWidget* _widget)
    : promo(_promo), widget(_widget), series(new QBarSeries())
{
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des bacs");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // axe X
    QStringList categories;
    categories << "Bacs";
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // axe Y
    axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Légende
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // affichage
    QGridLayout* chartLayout = new QGridLayout;
    chartLayout->addWidget(chartView, 0, 0);
    chartLayout->setContentsMargins(0, 0, 0, 0);

    widget->setLayout(chartLayout);

    update();
}

/**
 * @brief Met à jour le graphique avec les dernières données
 * Récupère les données des bacs et les ajoute à la série de barres.
 * Met également à jour l'axe Y pour s'assurer qu'il englobe tous les compteurs.
 */
void ViewHistogram::update()
{
    int maxY = 0;
    series->clear();

    QMap<QString, int> bacCounts = promo->getBacList();

    for (auto bacIt = bacCounts.constBegin(); bacIt != bacCounts.constEnd(); ++bacIt)
    {
        QString bac = bacIt.key();  // Nom du bac
        int count = bacIt.value();  // Nb etu pour ce bac

        QBarSet* set0 = new QBarSet(bac);
        *set0 << count;
        series->append(set0);

        if (count > maxY)
            maxY = count;
    }

    axisY->setRange(0, maxY);

    widget->repaint();
}
