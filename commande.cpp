#include "commande.h"
#include "qsqlerror.h"
#include <QDebug>

QString Commande::getNom() const
{
    return nom;
}

void Commande::setNom(const QString &newNom)
{
    nom = newNom;
}

QString Commande::getPayment() const
{
    return payment;
}

void Commande::setPayment(const QString &newPayment)
{
    payment = newPayment;
}

int Commande::getId() const
{
    return id;
}

void Commande::setId(int newId)
{
    id = newId;
}

int Commande::getQuantite() const
{
    return quantite;
}

void Commande::setQuantite(int newQuantite)
{
    quantite = newQuantite;
}

double Commande::getPrix() const
{
    return prix;
}

void Commande::setPrix(float newPrix)
{
    prix = newPrix;
}

Commande::Commande(){}

Commande::Commande(int id, QString nom, int quantite, float prix, QString payment)
{
    this -> id=id;
    this ->nom=nom;
    this ->quantite=quantite;
    this ->prix=prix;
    this ->payment=payment;
}
Commande::Commande(QString nom, int quantite, float prix, QString payment)
{
    this ->nom=nom;
    this ->quantite=quantite;
    this ->prix=prix;
    this ->payment=payment;
}

// Méthode pour ajouter une commande dans la base de données
bool Commande::ajouter() {

    qDebug() << "prix type:" << typeid(prix).name();  // Should show float or double type
    QSqlQuery query;
    query.prepare("INSERT INTO COMMANDES (NOM, QUANTITE, PRIX, PAYMENT)"
                  "VALUES (:Nom, :Quantite, :Prix, :Payment)");
    query.bindValue(":Nom",nom);
    query.bindValue(":Quantite",QVariant(quantite));
    query.bindValue(":Prix",QVariant(prix));
    query.bindValue(":Payment",payment);
    // query.bindValue(":prix", prix, QMetaType::Float);  // Bind explicitly as a float
    qDebug() << "prix :" << getPrix() ;

    if (!query.exec()) {
        // Log a detailed error message with both the text and error code
        qDebug() << "Error adding ordonnance:"
                 << query.lastError().text()  // Error message text
                 << "Error code:" << query.lastError().nativeErrorCode();  // Optional, for specific database error codes
        return false;  // Return false to indicate failure
    } else {
        qDebug() << "Ordonnance added successfully.";
        return true;  // Return true to indicate success
    }
}

// Méthode pour afficher toutes les commandes
QSqlQueryModel* Commande::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM commandes");
    return model;
}

// Méthode pour supprimer une commande par son ID
bool Commande::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM COMMANDES WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();  // Exécuter la requête
}

bool Commande::modifier() {
    // qDebug() << "prix type:" << typeid(prix).name();  // Log the type of 'prix'

    // Create a QSqlQuery to execute the UPDATE statement
    QSqlQuery query;

    // Prepare the SQL UPDATE query to modify the record based on the 'id'
    query.prepare("UPDATE COMMANDES "
                  "SET NOM = :Nom, QUANTITE = :Quantite, PRIX = :Prix, PAYMENT = :Payment "
                  "WHERE ID = :ID");

    // Bind the values for the parameters in the SQL query
    query.bindValue(":Nom", nom);  // Bind the 'nom' value
    query.bindValue(":Quantite", QVariant(quantite));  // Bind the 'quantite' value
    query.bindValue(":Prix", QVariant(prix));  // Bind the 'prix' value
    query.bindValue(":Payment", payment);  // Bind the 'payment' value
    query.bindValue(":ID", id);  // Bind the 'ID' of the commande to be updated


    // Execute the update query
    if (!query.exec()) {
        // If the query fails, log an error message with the text and error code
        qDebug() << "Error updating ordonnance:"
                 << query.lastError().text()  // Error message text
                 << "Error code:" << query.lastError().nativeErrorCode();  // Optional, for specific database error codes
        return false;  // Return false to indicate failure
    } else {
        // If the update is successful, log a success message
        qDebug() << "Ordonnance updated successfully.";
        return true;  // Return true to indicate success
    }
}

QSqlQueryModel* Commande::search(const QString &searchTerm, const QString &searchBy) {
    QSqlQueryModel *model = new QSqlQueryModel();

    // Ensure the searchBy value is valid (either "Nom" or "Payment")
    QString queryStr;
    if (searchBy == "Nom") {
        queryStr = "SELECT * FROM commandes WHERE Nom LIKE :searchTerm";
    } else if (searchBy == "Payment") {
        queryStr = "SELECT * FROM commandes WHERE Payment LIKE :searchTerm";
    } else {
        queryStr = "SELECT * FROM commandes";
    }

    // Prepare the query
    QSqlQuery query;
    query.prepare(queryStr);

    // Add the search term with wildcards for LIKE condition (to match anywhere in the word)
    query.bindValue(":searchTerm", "%" + searchTerm + "%");

    // Execute the query and set the model
    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Error executing search query:" << query.lastError();
    }

    return model;
}

QSqlQueryModel* Commande::filter(const QString &filterBy, const QString &sortOrder)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr;
    // Build the SQL query based on the filter and sort order
    if ( sortOrder == "RIEN"){
        queryStr = "SELECT * FROM commandes"; // Default query without sorting
    } else if (filterBy == "Nom") {
        queryStr = QString("SELECT * FROM commandes ORDER BY Nom %1").arg(sortOrder);
    } else if (filterBy == "Payment") {
        queryStr = QString("SELECT * FROM commandes ORDER BY Payment %1").arg(sortOrder);
    } else if (filterBy == "Quantite") {
        queryStr = QString("SELECT * FROM commandes ORDER BY Quantite %1").arg(sortOrder);
    } else {
        queryStr = "SELECT * FROM commandes"; // Default query without sorting
    }

    // Prepare and execute the query
    QSqlQuery query;
    query.prepare(queryStr);

    // Execute the query and set the model
    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Error executing filter query:" << query.lastError();
    }

    return model;
}

QMap<QString, double> Commande::retrieveGroupedData(const QString &groupBy)
{
    QMap<QString, double> groupedData;  // To store group -> count of occurrences

    // Ensure that the grouping is either by "Nom" or "Payment"
    if (groupBy != "Nom" && groupBy != "Payment") {
        qWarning() << "Invalid groupBy parameter. It must be 'Nom' or 'Payment'.";
        return groupedData; // return empty map if invalid groupBy
    }

    // Build the SQL query for grouping and counting occurrences
    QString queryStr = QString("SELECT %1, COUNT(*) AS occurrenceCount FROM commandes GROUP BY %1")
                           .arg(groupBy);

    // Prepare and execute the query
    QSqlQuery query;
    query.prepare(queryStr);

    if (query.exec()) {
        // Fetch the results and populate the map
        while (query.next()) {
            QString groupValue = query.value(0).toString(); // Group by Nom or Payment
            double occurrenceCount = query.value(1).toDouble(); // Count of occurrences for this group
            groupedData[groupValue] = occurrenceCount;  // Insert or update the map
        }
    } else {
        qDebug() << "Error executing grouped query:" << query.lastError();
    }

    return groupedData;  // Return the map with grouped data
}
