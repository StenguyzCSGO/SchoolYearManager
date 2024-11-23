#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QListWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QString>
#include <QRegularExpression>
#include <QStringList>
#include <QMessageBox>
#include "promotion.h"

/**
 * @brief Interface pour les contrôleurs
 * @details Définition d'une méthode virtuelle pure pour le contrôle.
 */
class Controller
{
public:
    /**
     * @brief Méthode virtuelle pure pour le contrôle
     */
    virtual void control()=0;
};

#endif // CONTROLLER_H
