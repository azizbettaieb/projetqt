#ifndef COMMANDE_H
#define COMMANDE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Commande
{
private:
    QString nom, payment;
    int id, quantite;
    double prix;

public:
    // Constructeur paramétré
    Commande();
    Commande(int , QString , int , float , QString );
    Commande(QString , int , float , QString );
    // Méthode pour ajouter une commande dans la base de données
    bool ajouter();

    // Méthode pour afficher toutes les commandes
    QSqlQueryModel* afficher();

    // Méthode pour supprimer une commande par son ID
    bool supprimer(int id);
    QString getNom() const;
    void setNom(const QString &newNom);
    QString getPayment() const;
    void setPayment(const QString &newPayment);
    int getId() const;
    void setId(int newId);
    int getQuantite() const;
    void setQuantite(int newQuantite);
    double getPrix() const;
    void setPrix(float newPrix);
    bool modifier();
    QSqlQueryModel *search(const QString &searchTerm, const QString &searchBy);
    QSqlQueryModel *filter(const QString &filterBy, const QString &sortOrder);
    QMap<QString, double> retrieveGroupedData(const QString &groupBy);
};

#endif // COMMANDE_H
