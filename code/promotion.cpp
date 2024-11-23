#include "promotion.h"
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QStringList>

Promotion::Promotion(QString filename) {
    QString filePath = QDir::currentPath()+"/../../../data/"+filename;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Impossible d'ouvrir le fichier :" << filePath;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(';');

        if (fields.size() == 5) {
            Student student(fields[0].trimmed(),   // cardID
                            fields[1].trimmed(),   // firstname
                            fields[2].trimmed(),   // lastname
                            fields[4].trimmed(),  // department
                            fields[3].trimmed());   // bac
            students.append(student);
            qDebug() << "[+] Etudiant ajouter: " << student.getFirstname() << student.getLastname();
        }
    }

    file.close();
    qDebug() << "[+] Promotion chargée avec succès depuis" << filePath;
}

/**
 * @brief Ajouter un étudiant à la promotion
 * @param etu L'étudiant à ajouter
*/
void Promotion::add(const Student &etu) {
    students.append(etu);
    qDebug() << "[+] Étudiant ajouté :" << etu;
}

/**
 * @brief Supprimer un étudiant de la promotion par son texte d'affichage
 * @param listName Le texte de l'étudiant dans la vue
*/
void Promotion::remove(const QString &listName) {
    for (auto it = students.begin(); it != students.end();) {
        if (it->getText() == listName) {
            it = students.erase(it);
            qDebug() << "[-] Étudiant supprimé correspondant à :" << listName;
        } else {
            ++it;
        }
    }
    qDebug() << "[!] Aucun étudiant trouvé pour suppression avec le nom :" << listName;
}

/**
 * @brief Supprimer un étudiant spécifique de la promotion
 * @param etu L'étudiant à supprimer
*/
void Promotion::remove(const Student &etu) {
    for (int i = 0; i < students.size(); ++i) {
        if (students[i].getCardID() == etu.getCardID()) {
            students.removeAt(i);
            qDebug() << "[-] Étudiant supprimé :" << etu;
            return;
        }
    }
    qDebug() << "[!] Étudiant non trouvé pour suppression :" << etu;
}

/**
 * @brief Trouver un étudiant par son ID de carte
 * @param cardID L'ID de l'étudiant
 * @return L'étudiant trouvé
*/
Student Promotion::find(QString cardID) const {
    for (const Student &etu : students) {
        if (etu.getCardID() == cardID) {
            qDebug() << "[*] Étudiant trouvé avec l'ID :" << cardID;
            return etu;
        }
    }

    qDebug() << "[!] Étudiant non trouvé avec l'ID :" << cardID;
    return Student();
}

/**
 * @brief Retourner la liste des étudiants sous forme de texte
 * @return Liste des étudiants
*/
QStringList Promotion::getList() const {
    QStringList list;
    for (const Student &student : students) {
        list.append(student.getText());
    }
    return list;
}

/**
 * @brief Afficher les informations des étudiants
 * @param os Flux de sortie
 * @param dt Promotion
 * @return Flux de sortie mis à jour
*/
QDebug operator<<(QDebug os, const Promotion& dt)
{
    for (const Student& student : dt.students)
    {
        os << student << "\n";
    }

    return os;
}

/**
 * @brief Retourner le nombre d'étudiants par département
 * @return Liste des départements avec le nombre d'étudiants
*/
QMap<QString, int> Promotion::getDepartementList() const
{
    QMap<QString, int> departmentCounts;

    for (const Student &student : students)
    {
        QString department = student.getDepartment();
        departmentCounts[department] = departmentCounts.value(department, 0) + 1;
    }

    return departmentCounts;
}

/**
 * @brief Retourner le nombre d'étudiants par bac
 * @return Liste des bacs avec le nombre d'étudiants
*/
QMap<QString, int> Promotion::getBacList() const
{
    QMap<QString, int> bacCounts{
        {"S", 0},
        {"ES", 0},
        {"L", 0},
        {"STI", 0},
    };

    for (const Student& student : students)
    {
        QString bac = student.getBac();
        if (bacCounts.contains(bac)) {
            bacCounts[bac]++;
        } else {
            bacCounts.insert(bac, 1);
        }
    }

    return bacCounts;
}
