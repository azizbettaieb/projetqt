/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTextEdit *textEdit;
    QTableView *tableView;
    QLabel *label_14;
    QPushButton *pushButton_5;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_id_2;
    QLineEdit *lineEdit_nom_2;
    QLineEdit *lineEdit_prix_2;
    QLineEdit *lineEdit_quantite_2;
    QLabel *label_10;
    QLineEdit *lineEdit_payment_2;
    QPushButton *Ajouter_2;
    QPushButton *mettre_a_jour;
    QPushButton *pushButton_4;
    QPushButton *supprimer;
    QGroupBox *groupBox_2;
    QRadioButton *Radio_Nom;
    QRadioButton *Radio_Payment;
    QLineEdit *Search_LineEdit;
    QRadioButton *Radio_Rien;
    QGroupBox *groupBox_3;
    QRadioButton *Radio_NomFiltre;
    QRadioButton *Radio_PaymentFiltre;
    QRadioButton *Radio_QuantiteFiltre;
    QListView *listView;
    QGroupBox *groupBox_4;
    QRadioButton *Radio_Asc;
    QRadioButton *Radio_Desc;
    QRadioButton *Radio_RienFilter;
    QWidget *page_2;
    QFrame *ChartFrame;
    QPushButton *page2a1;
    QGroupBox *groupBox_5;
    QRadioButton *Radio_ChartNom;
    QRadioButton *Radio_ChartPayment;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1318, 790);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1311, 761));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        textEdit = new QTextEdit(page);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(750, 120, 451, 41));
        textEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(228,224,223);\n"
"color: rgb(0, 0, 106);\n"
"color: rgb(0, 0, 79);\n"
"color: rgb(0, 0, 127);\n"
"alternate-background-color: rgb(187, 240, 250);\n"
"color: rgb(0, 0, 0);"));
        tableView = new QTableView(page);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(750, 170, 541, 461));
        label_14 = new QLabel(page);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(470, 10, 401, 61));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); border-radius:20%;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 16pt \"Segoe UI\";"));
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(230, 100, 131, 29));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255, 255); border-radius:10%;\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
""));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(220, 140, 471, 521));
        groupBox->setStyleSheet(QString::fromUtf8("background-color:rgb(252,224,187);\n"
"alternate-background-color: rgb(153, 204, 153);\n"
"font: 18pt \"Segoe UI\";\n"
"border-radius:20%;"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 221, 51));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 150, 141, 51));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 290, 101, 41));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 360, 131, 41));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);"));
        lineEdit_id_2 = new QLineEdit(groupBox);
        lineEdit_id_2->setObjectName(QString::fromUtf8("lineEdit_id_2"));
        lineEdit_id_2->setGeometry(QRect(250, 100, 171, 28));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        lineEdit_id_2->setFont(font);
        lineEdit_id_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
" border-radius:10%;"));
        lineEdit_nom_2 = new QLineEdit(groupBox);
        lineEdit_nom_2->setObjectName(QString::fromUtf8("lineEdit_nom_2"));
        lineEdit_nom_2->setGeometry(QRect(250, 160, 171, 28));
        lineEdit_nom_2->setFont(font);
        lineEdit_nom_2->setStyleSheet(QString::fromUtf8(" border-radius:10%;background-color: rgb(255, 255, 255);"));
        lineEdit_prix_2 = new QLineEdit(groupBox);
        lineEdit_prix_2->setObjectName(QString::fromUtf8("lineEdit_prix_2"));
        lineEdit_prix_2->setGeometry(QRect(250, 290, 171, 28));
        lineEdit_prix_2->setFont(font);
        lineEdit_prix_2->setStyleSheet(QString::fromUtf8(" border-radius:10%;background-color: rgb(255, 255, 255);"));
        lineEdit_prix_2->setInputMask(QString::fromUtf8(""));
        lineEdit_prix_2->setText(QString::fromUtf8(""));
        lineEdit_quantite_2 = new QLineEdit(groupBox);
        lineEdit_quantite_2->setObjectName(QString::fromUtf8("lineEdit_quantite_2"));
        lineEdit_quantite_2->setGeometry(QRect(250, 360, 171, 28));
        lineEdit_quantite_2->setFont(font);
        lineEdit_quantite_2->setStyleSheet(QString::fromUtf8(" border-radius:10%;background-color: rgb(255, 255, 255);"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 220, 141, 51));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);"));
        lineEdit_payment_2 = new QLineEdit(groupBox);
        lineEdit_payment_2->setObjectName(QString::fromUtf8("lineEdit_payment_2"));
        lineEdit_payment_2->setGeometry(QRect(250, 220, 171, 28));
        lineEdit_payment_2->setFont(font);
        lineEdit_payment_2->setStyleSheet(QString::fromUtf8(" border-radius:10%;background-color: rgb(255, 255, 255);"));
        Ajouter_2 = new QPushButton(groupBox);
        Ajouter_2->setObjectName(QString::fromUtf8("Ajouter_2"));
        Ajouter_2->setGeometry(QRect(270, 470, 131, 29));
        Ajouter_2->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 33, 79); border-radius:10%;\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(71, 170, 82);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        mettre_a_jour = new QPushButton(groupBox);
        mettre_a_jour->setObjectName(QString::fromUtf8("mettre_a_jour"));
        mettre_a_jour->setGeometry(QRect(40, 470, 131, 29));
        mettre_a_jour->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 33, 79); border-radius:10%;\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 170, 0);\n"
"background-color: rgb(71, 170, 82);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(260, 670, 131, 29));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 33, 79); border-radius:10%;\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(71, 170, 82);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        supprimer = new QPushButton(page);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        supprimer->setGeometry(QRect(490, 670, 131, 29));
        supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 33, 79); border-radius:10%;\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(71, 170, 82);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(760, 640, 241, 91));
        Radio_Nom = new QRadioButton(groupBox_2);
        Radio_Nom->setObjectName(QString::fromUtf8("Radio_Nom"));
        Radio_Nom->setGeometry(QRect(10, 20, 110, 24));
        Radio_Payment = new QRadioButton(groupBox_2);
        Radio_Payment->setObjectName(QString::fromUtf8("Radio_Payment"));
        Radio_Payment->setGeometry(QRect(80, 20, 110, 24));
        Search_LineEdit = new QLineEdit(groupBox_2);
        Search_LineEdit->setObjectName(QString::fromUtf8("Search_LineEdit"));
        Search_LineEdit->setGeometry(QRect(10, 50, 221, 26));
        Radio_Rien = new QRadioButton(groupBox_2);
        Radio_Rien->setObjectName(QString::fromUtf8("Radio_Rien"));
        Radio_Rien->setGeometry(QRect(180, 20, 61, 24));
        groupBox_3 = new QGroupBox(page);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(1000, 640, 301, 51));
        Radio_NomFiltre = new QRadioButton(groupBox_3);
        Radio_NomFiltre->setObjectName(QString::fromUtf8("Radio_NomFiltre"));
        Radio_NomFiltre->setGeometry(QRect(10, 20, 110, 24));
        Radio_PaymentFiltre = new QRadioButton(groupBox_3);
        Radio_PaymentFiltre->setObjectName(QString::fromUtf8("Radio_PaymentFiltre"));
        Radio_PaymentFiltre->setGeometry(QRect(80, 20, 110, 24));
        Radio_QuantiteFiltre = new QRadioButton(groupBox_3);
        Radio_QuantiteFiltre->setObjectName(QString::fromUtf8("Radio_QuantiteFiltre"));
        Radio_QuantiteFiltre->setGeometry(QRect(170, 20, 110, 24));
        listView = new QListView(page);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 150, 191, 491));
        listView->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 33, 79); border-radius:20%;\n"
"background-color: rgb(226, 226, 226);\n"
""));
        listView->setFrameShape(QFrame::Shape::StyledPanel);
        listView->setFrameShadow(QFrame::Shadow::Sunken);
        groupBox_4 = new QGroupBox(page);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(1000, 690, 301, 41));
        Radio_Asc = new QRadioButton(groupBox_4);
        Radio_Asc->setObjectName(QString::fromUtf8("Radio_Asc"));
        Radio_Asc->setGeometry(QRect(10, 10, 110, 21));
        Radio_Desc = new QRadioButton(groupBox_4);
        Radio_Desc->setObjectName(QString::fromUtf8("Radio_Desc"));
        Radio_Desc->setGeometry(QRect(110, 10, 110, 24));
        Radio_RienFilter = new QRadioButton(groupBox_4);
        Radio_RienFilter->setObjectName(QString::fromUtf8("Radio_RienFilter"));
        Radio_RienFilter->setGeometry(QRect(220, 10, 61, 24));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        ChartFrame = new QFrame(page_2);
        ChartFrame->setObjectName(QString::fromUtf8("ChartFrame"));
        ChartFrame->setGeometry(QRect(20, 60, 1281, 681));
        page2a1 = new QPushButton(page_2);
        page2a1->setObjectName(QString::fromUtf8("page2a1"));
        page2a1->setGeometry(QRect(20, 10, 93, 29));
        groupBox_5 = new QGroupBox(page_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(440, 10, 301, 51));
        Radio_ChartNom = new QRadioButton(groupBox_5);
        Radio_ChartNom->setObjectName(QString::fromUtf8("Radio_ChartNom"));
        Radio_ChartNom->setGeometry(QRect(90, 20, 61, 24));
        Radio_ChartPayment = new QRadioButton(groupBox_5);
        Radio_ChartPayment->setObjectName(QString::fromUtf8("Radio_ChartPayment"));
        Radio_ChartPayment->setGeometry(QRect(170, 20, 91, 24));
        stackedWidget->addWidget(page_2);
        page2a1->raise();
        groupBox_5->raise();
        ChartFrame->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1318, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">gestion des commandes</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "        Gestion des Commandes ", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Commande", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">idproduit :</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Nomproduit :</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Prix :</span></p><p><br/></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Quantit\303\250 :</span></p><p><br/></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Payment :</span></p><p><br/></p></body></html>", nullptr));
        Ajouter_2->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        mettre_a_jour->setText(QCoreApplication::translate("MainWindow", "Mettre a jour", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Exporter pdf", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Search :", nullptr));
        Radio_Nom->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        Radio_Payment->setText(QCoreApplication::translate("MainWindow", "Payment", nullptr));
        Radio_Rien->setText(QCoreApplication::translate("MainWindow", "Rien", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Filtre :", nullptr));
        Radio_NomFiltre->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        Radio_PaymentFiltre->setText(QCoreApplication::translate("MainWindow", "Payment", nullptr));
        Radio_QuantiteFiltre->setText(QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        groupBox_4->setTitle(QString());
        Radio_Asc->setText(QCoreApplication::translate("MainWindow", "Ascendant", nullptr));
        Radio_Desc->setText(QCoreApplication::translate("MainWindow", "Descendant", nullptr));
        Radio_RienFilter->setText(QCoreApplication::translate("MainWindow", "Rien", nullptr));
        page2a1->setText(QCoreApplication::translate("MainWindow", "< Avant", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Critere  :", nullptr));
        Radio_ChartNom->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        Radio_ChartPayment->setText(QCoreApplication::translate("MainWindow", "Payment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
