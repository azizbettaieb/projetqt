#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "commande.h"

#include <QMainWindow>
#include <qbuttongroup.h>
#include <qradiobutton.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_radioButton_toggled(bool checked);
    void on_radioButton_order_toggled(bool checked);
    void removeChart();
    void on_radioButton_chart_order_toggled();
    void updateChart(QMapIterator<QString, double> i);
    void exportListViewToPDF();
private slots:
    void on_Ajouter_2_clicked();
    void loadCommandes();
    void on_supprimer_clicked();
    void ClearLinesView();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_mettre_a_jour_clicked();

    void on_Search_LineEdit_textChanged(const QString &arg1);

    void on_groupBox_3_clicked();

    void on_pushButton_5_clicked();

    void on_page2a1_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Commande C;
    QButtonGroup* buttonGroup = new QButtonGroup(this);
};
#endif // MAINWINDOW_H
