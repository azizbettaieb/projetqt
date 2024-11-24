#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QButtonGroup>
// Widget used to display charts
#include <QtCharts/QChartView>
// Used to draw bars representing data provided
// grouped into categories
#include <QtCharts/QBarSeries>
// Represents 1 set of bars in a bar chart
#include <QtCharts/QBarSet>
// Displays the color used to represent each
// QBarSet
#include <QtCharts/QLegend>
// Adds categories to the charts axes
#include <QtCharts/QBarCategoryAxis>
// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>
// Used to create a line chart
#include <QtCharts/QLineSeries>
// Used to change names on axis
#include <QtCharts/QCategoryAxis>
// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QAbstractItemModel>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QTextTableCell>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadCommandes();

    connect(ui->Radio_NomFiltre, &QRadioButton::toggled, this, &MainWindow::on_radioButton_toggled);
    connect(ui->Radio_PaymentFiltre, &QRadioButton::toggled, this, &MainWindow::on_radioButton_toggled);
    connect(ui->Radio_QuantiteFiltre, &QRadioButton::toggled, this, &MainWindow::on_radioButton_toggled);
    ui->Radio_Asc->setChecked(true);
    connect(ui->Radio_Asc, &QRadioButton::toggled, this, &MainWindow::on_radioButton_order_toggled);
    connect(ui->Radio_Desc, &QRadioButton::toggled, this, &MainWindow::on_radioButton_order_toggled);
    connect(ui->Radio_RienFilter, &QRadioButton::toggled, this, &MainWindow::on_radioButton_order_toggled);
    setCentralWidget(ui->centralwidget);

    ui->Radio_ChartNom->setChecked(true);
    connect(ui->Radio_ChartNom, &QRadioButton::toggled, this, &MainWindow::on_radioButton_chart_order_toggled);
    connect(ui->Radio_ChartPayment, &QRadioButton::toggled, this, &MainWindow::on_radioButton_chart_order_toggled);
}


void MainWindow::on_radioButton_chart_order_toggled()
{
    QString filterBy;
    filterBy.clear();
    if (ui->Radio_ChartNom->isChecked()) {
        qDebug() << "Nom radio button is checked";
        filterBy = "Nom";
    } else if (ui->Radio_ChartPayment->isChecked()) {
        qDebug() << "Payment radio button is checked";
        filterBy = "Payment";
    }
    QMap<QString, double> groupedData = C.retrieveGroupedData(filterBy);
    QMapIterator<QString, double> i(groupedData);
    updateChart(i);
}
// filtre
void MainWindow::on_radioButton_toggled(bool checked)
{
    if (checked) {
        QString filterBy;  // The column to filter by (Nom, Payment, Quantite)
        QString sortOrder; // The order for sorting (ASC or DESC)
        filterBy.clear();
        // Determine the filter column
        if (ui->Radio_NomFiltre->isChecked()) {
            qDebug() << "Nom radio button is checked";
            filterBy = "Nom";
        } else if (ui->Radio_PaymentFiltre->isChecked()) {
            qDebug() << "Payment radio button is checked";
            filterBy = "Payment";
        } else if (ui->Radio_QuantiteFiltre->isChecked()) {
            qDebug() << "Quantite radio button is checked";
            filterBy = "Quantite";
        }

        // Determine the sort order (ascending or descending)
        if (ui->Radio_Asc->isChecked()) {
            sortOrder = "ASC";
        } else if (ui->Radio_Desc->isChecked()) {
            sortOrder = "DESC";
        }else if (ui->Radio_RienFilter->isChecked()) {
            sortOrder = "rien";
        }

        // Now call the filter function with the chosen parameters
        QSqlQueryModel *filteredModel = C.filter(filterBy, sortOrder);

        // Set the model to display data in tableView
        ui->tableView->reset();
        ui->tableView->setModel(filteredModel);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}
// filtre
void MainWindow::on_radioButton_order_toggled(bool checked)
{
    if (checked) {
        QString filterBy;  // The column to filter by (Nom, Payment, Quantite)
        QString sortOrder; // The order for sorting (ASC or DESC)
        filterBy.clear();
        // Determine the filter column
        if (ui->Radio_NomFiltre->isChecked()) {
            qDebug() << "Nom radio button is checked";
            filterBy = "Nom";
        } else if (ui->Radio_PaymentFiltre->isChecked()) {
            qDebug() << "Payment radio button is checked";
            filterBy = "Payment";
        } else if (ui->Radio_QuantiteFiltre->isChecked()) {
            qDebug() << "Quantite radio button is checked";
            filterBy = "Quantite";
        }

        // Determine the sort order (ascending or descending)
        if (ui->Radio_Asc->isChecked()) {
            sortOrder = "ASC";
        } else if (ui->Radio_Desc->isChecked()) {
            sortOrder = "DESC";
        }else if (ui->Radio_RienFilter->isChecked()) {
            sortOrder = "RIEN";
        }

        // Now call the filter function with the chosen parameters
        QSqlQueryModel *filteredModel = C.filter(filterBy, sortOrder);

        // Set the model to display data in tableView
        ui->tableView->reset();
        ui->tableView->setModel(filteredModel);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_supprimer_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt(); // Supposons que vous avez un champ pour saisir l'ID
    // Créer une instance de la classe Commande (l'objet peut être utilisé pour d'autres méthodes, mais ici c'est pour accéder à supprimer)
    C.setId(id);
    // Appeler la méthode supprimer() de l'objet Commande
    bool test = C.supprimer(id);
    // Vérifier si la suppression a réussi
    if (test) {
        QMessageBox::information(this, "Succès", "Commande supprimée avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression de la commande.");
    }
    ClearLinesView();
    loadCommandes();
}


void MainWindow::on_Ajouter_2_clicked()
{
    //    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom_2->text();
    QString quantite = ui->lineEdit_quantite_2->text();
    QString prix = ui->lineEdit_prix_2->text();
    QString payment = ui->lineEdit_payment_2->text();
    int quantite_ToInt = quantite.toInt();
    double prix_ToDouble = prix.toDouble();
    C.setPrix(prix_ToDouble);
    C.setNom(nom);
    C.setPayment(payment);
    C.setQuantite(quantite_ToInt);
    bool test=C.ajouter();
    if (test) {
        QMessageBox::information(this, "Succès", "Commande ajoutée avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de la commande.");
    }
    ClearLinesView();
    loadCommandes();
}

void MainWindow::loadCommandes()
{
    // Load Ordonnance data into the table view
    QSqlQueryModel *model = new QSqlQueryModel(this);

    model->setQuery("SELECT * From COMMANDES");

    // Set the model to display data in tableView
    ui->tableView->reset();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    ClearLinesView();
    // Get the row number of the clicked cell
    int row = index.row();

    // Get the model associated with the table view
    QAbstractItemModel *model = ui->tableView->model();

    // Extract data from each column in the selected row
    QModelIndex idIndex = model->index(row, 0); // Assuming 'id' is in the first column (index 0)
    QModelIndex nomIndex = model->index(row, 1); // Assuming 'nom' is in the second column (index 1)
    QModelIndex quantiteIndex = model->index(row, 2); // 'quantite' in the third column (index 2)
    QModelIndex prixIndex = model->index(row, 3); // 'prix' in the fourth column (index 3)
    QModelIndex paymentIndex = model->index(row, 4); // 'payment' in the fifth column (index 4)

    // Extract the data from each column (convert to appropriate types)
    int id = model->data(idIndex).toInt();        // Assuming 'id' is an integer
    QString nom = model->data(nomIndex).toString(); // Assuming 'nom' is a string
    int quantite = model->data(quantiteIndex).toInt();  // Assuming 'quantite' is an integer
    double prix = model->data(prixIndex).toDouble();   // Assuming 'prix' is a double
    QString payment = model->data(paymentIndex).toString(); // Assuming 'payment' is a string

    // You can now use these variables as needed
    qDebug() << "id:" << id;
    qDebug() << "nom:" << nom;
    qDebug() << "quantite:" << quantite;
    qDebug() << "prix:" << prix;
    qDebug() << "payment:" << payment;

    // Populate the QLineEdits with the extracted data
    ui->lineEdit_id_2->setText(QString::number(id)); // Set 'id' to the corresponding line edit
    ui->lineEdit_nom_2->setText(nom); // Set 'nom' to the corresponding line edit
    ui->lineEdit_quantite_2->setText(QString::number(quantite)); // Set 'quantite' to the corresponding line edit
    ui->lineEdit_prix_2->setText(QString::number(prix, 'f', 2)); // Set 'prix' to the corresponding line edit, format as a float (2 decimals)
    ui->lineEdit_payment_2->setText(payment); // Set 'payment' to the corresponding line edit
    ui->lineEdit_id_2->setDisabled(true);
}

void MainWindow::ClearLinesView(){
    ui->lineEdit_id_2->clear();
    ui->lineEdit_nom_2->clear();
    ui->lineEdit_quantite_2->clear();
    ui->lineEdit_prix_2->clear();
    ui->lineEdit_payment_2->clear();
}

void MainWindow::on_mettre_a_jour_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    QString nom = ui->lineEdit_nom_2->text();
    QString quantite = ui->lineEdit_quantite_2->text();
    QString prix = ui->lineEdit_prix_2->text();
    QString payment = ui->lineEdit_payment_2->text();
    int quantite_ToInt = quantite.toInt();
    double prix_ToDouble = prix.toDouble();
    C.setPrix(prix_ToDouble);
    C.setNom(nom);
    C.setPayment(payment);
    C.setQuantite(quantite_ToInt);
    C.setId(id);
    bool test=C.modifier();
    if (test) {
        QMessageBox::information(this, "Succès", "Commande modifier avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de la commande.");
    }
    ClearLinesView();
    loadCommandes();
    ui->lineEdit_id_2->setDisabled(false);
}


void MainWindow::on_Search_LineEdit_textChanged(const QString &arg1)
{
    QString searchBy;
    searchBy.clear();
    if (ui->Radio_Nom->isChecked()){
        qDebug() << "Nom";
        searchBy = "Nom";
    }else if (ui->Radio_Payment->isChecked()){
        qDebug() << "Payment";
        searchBy = "Payment";
    }

    qDebug() << "arg edit:" << arg1;
    // Load Ordonnance data into the table view
    QSqlQueryModel *model = C.search(arg1,searchBy);;


    // Set the model to display data in tableView
    ui->tableView->reset();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}


void MainWindow::on_groupBox_3_clicked()
{
    // bool checkedButton = ui->buttonGroup->isChecked();
    QAbstractButton *checkedButton = buttonGroup->checkedButton();

    if (checkedButton) {
        if (checkedButton == ui->Radio_NomFiltre) {
            qDebug() << "Nom radio button is checked";
        } else if (checkedButton == ui->Radio_PaymentFiltre) {
            qDebug() << "Payment radio button is checked";
        }
    } else {
        qDebug() << "No radio button is checked";
    }
    // Check if the radio buttons inside the group box are checked
    // if (ui->Radio_NomFiltre->isChecked()) {
    //     qDebug() << "Nom radio button is checked";
    // } else if (ui->Radio_PaymentFiltre->isChecked()) {
    //     qDebug() << "Payment radio button is checked";
    // } else {
    //     qDebug() << "No radio button is checked";
    // }
}


void MainWindow::on_pushButton_5_clicked()
{
    QString filterBy;
    filterBy.clear();
    if (ui->Radio_ChartNom->isChecked()) {
        qDebug() << "Nom radio button is checked";
        filterBy = "Nom";
    } else if (ui->Radio_ChartPayment->isChecked()) {
        qDebug() << "Payment radio button is checked";
        filterBy = "Payment";
    }
    QMap<QString, double> groupedData = C.retrieveGroupedData(filterBy);
    QMapIterator<QString, double> i(groupedData);
    updateChart(i);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_page2a1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::updateChart(QMapIterator<QString, double> i)
{
    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();
    int j=0;
    int position = 0;
    int puissance = 0;
    while (i.hasNext()) {
        i.next();  // Move to the next item
        qDebug() << "Group:" << i.key() << "Count:" << i.value();
        series->append(i.key(),i.value()/100);
        QtCharts::QPieSlice *slice = series->slices().at(j);
        slice->setLabelVisible();
        if ( i.value() > puissance ){
            puissance = i.value();
            position = j;
        }
        j++;
    }
    QtCharts::QPieSlice *slice = series->slices().at(position);
    slice->setExploded();
    QPen qPen(Qt::darkGreen, 2);
    slice->setPen(qPen);
    slice->setBrush(Qt::green);
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("what the hell bro");
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QLayout *oldLayout = ui->ChartFrame->layout();
    delete oldLayout;
    QVBoxLayout *layout = new QVBoxLayout(ui->ChartFrame);
    layout->addWidget(chartView);
    // ui->ChartFrame->clearMask();
    ui->ChartFrame->setLayout(layout);
}


void MainWindow::on_pushButton_4_clicked()
{
    // Ask the user for the file path to save the PDF
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save as PDF", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) {
        return; // User canceled the dialog
    }

    // Create a QPdfWriter object to write the PDF
    QPdfWriter writer(filePath);
    writer.setPageSize(QPagedPaintDevice::A4);
    writer.setPageOrientation(QPageLayout::Portrait);

    // Create a QPainter object to draw on the PDF
    QPainter painter(&writer);
    if (!painter.isActive()) {
        qWarning() << "Failed to create painter for PDF";
        return;
    }

    // Set some general settings for the painter
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10));

    // Get the model from the TableView
    QAbstractItemModel *model = ui->tableView->model();
    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

    // Define column widths
    QVector<int> columnWidths;
    for (int col = 0; col < columnCount; ++col) {
        columnWidths.append(ui->tableView->columnWidth(col));
    }

    // Starting Y position for drawing
    int yPos = 40;  // Space for title and header
    const int startX = 20;  // Left margin
    const int cellHeight = 20; // Height of each row

    // Draw table header
    for (int col = 0; col < columnCount; ++col) {
        QRect rect(startX + columnWidths[col] * col, yPos, columnWidths[col], cellHeight);
        painter.drawText(rect, Qt::AlignCenter, model->headerData(col, Qt::Horizontal).toString());
    }
    yPos += cellHeight;

    // Draw the table rows
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QModelIndex index = model->index(row, col);
            QString cellText = model->data(index).toString();
            QRect rect(startX + columnWidths[col] * col, yPos, columnWidths[col], cellHeight);

            // Draw the text inside the cell
            painter.drawText(rect, Qt::AlignCenter, cellText);
        }
        yPos += cellHeight;

        // Check if we need to add a new page
        if (yPos > writer.height() - 40) {
            painter.end();  // Finish the current page
            writer.newPage();  // Start a new page
            painter.begin(&writer);  // Reinitialize painter for the new page
            yPos = 40;  // Reset the y-position for the new page
        }
    }

    // End the painter and finalize the PDF
    painter.end();
    qDebug() << "Exported to PDF successfully!";

}

