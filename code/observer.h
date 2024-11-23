#pragma once
#include <QList>

/**
 * @brief Interface pour les observateurs
 * @details Classe de base pour un observateur, doit implementer update().
 */
class Observer {
public:
    virtual ~Observer() = default;
    /**
     * @brief Met à jour l'observateur
     * @details À implémenter dans la classe dérivée
     */
    virtual void update() = 0;
};

/**
 * @brief Classe de base pour un sujet observable
 * @details Gère les observers et les notifie lors de changements
 */
class Observable {
protected:
    QList<Observer*> observers; /**< Liste des observateurs */
public:
    virtual ~Observable() = default;

    /**
     * @brief Ajoute un observateur
     * @param observer Observateur à ajouter
     */
    void addObserver(Observer* observer) { observers.append(observer); }

    /**
     * @brief Supprime un observateur
     * @param observer Observateur à supprimer
     */
    void removeObserver(Observer* observer) { observers.removeAll(observer); }

    /**
     * @brief Notifie tous les observateurs
     * @details Appelle update() sur chaque observateur
     */
    void notifyObserver() const { for(Observer* observer : observers) observer->update();}
};
