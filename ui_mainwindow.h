/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed May 15 12:51:45 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *tbCaminhoArquivo;
    QPushButton *pushButton_3;
    QLabel *lblVideoProcessado;
    QLabel *lblVideoOriginal;
    QProgressBar *progressBar;
    QLineEdit *tbTrainningPath;
    QPushButton *btTrainningPath;
    QPushButton *btClearTrainning;
    QLabel *label;
    QLabel *lblStatusMsg;
    QLabel *label_2;
    QLabel *lblDatabaseSize;
    QPushButton *btSearchDatabase;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1208, 555);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 370, 161, 32));
        tbCaminhoArquivo = new QLineEdit(centralWidget);
        tbCaminhoArquivo->setObjectName(QString::fromUtf8("tbCaminhoArquivo"));
        tbCaminhoArquivo->setGeometry(QRect(490, 10, 161, 22));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(656, 2, 41, 30));
        lblVideoProcessado = new QLabel(centralWidget);
        lblVideoProcessado->setObjectName(QString::fromUtf8("lblVideoProcessado"));
        lblVideoProcessado->setGeometry(QRect(20, 10, 420, 320));
        lblVideoProcessado->setMinimumSize(QSize(420, 320));
        lblVideoProcessado->setMaximumSize(QSize(420, 320));
        lblVideoProcessado->setStyleSheet(QString::fromUtf8("background: rgb(0, 0, 0)"));
        lblVideoOriginal = new QLabel(centralWidget);
        lblVideoOriginal->setObjectName(QString::fromUtf8("lblVideoOriginal"));
        lblVideoOriginal->setGeometry(QRect(490, 40, 210, 160));
        lblVideoOriginal->setMinimumSize(QSize(210, 160));
        lblVideoOriginal->setMaximumSize(QSize(210, 160));
        lblVideoOriginal->setStyleSheet(QString::fromUtf8("background: rgb(0, 0, 0)"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(30, 440, 401, 23));
        progressBar->setAutoFillBackground(false);
        progressBar->setMaximum(0);
        progressBar->setValue(-1);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);
        tbTrainningPath = new QLineEdit(centralWidget);
        tbTrainningPath->setObjectName(QString::fromUtf8("tbTrainningPath"));
        tbTrainningPath->setGeometry(QRect(20, 340, 341, 22));
        btTrainningPath = new QPushButton(centralWidget);
        btTrainningPath->setObjectName(QString::fromUtf8("btTrainningPath"));
        btTrainningPath->setGeometry(QRect(367, 332, 80, 40));
        btClearTrainning = new QPushButton(centralWidget);
        btClearTrainning->setObjectName(QString::fromUtf8("btClearTrainning"));
        btClearTrainning->setGeometry(QRect(180, 370, 161, 32));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 460, 61, 16));
        lblStatusMsg = new QLabel(centralWidget);
        lblStatusMsg->setObjectName(QString::fromUtf8("lblStatusMsg"));
        lblStatusMsg->setGeometry(QRect(80, 460, 361, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 410, 91, 16));
        lblDatabaseSize = new QLabel(centralWidget);
        lblDatabaseSize->setObjectName(QString::fromUtf8("lblDatabaseSize"));
        lblDatabaseSize->setGeometry(QRect(120, 410, 62, 16));
        btSearchDatabase = new QPushButton(centralWidget);
        btSearchDatabase->setObjectName(QString::fromUtf8("btSearchDatabase"));
        btSearchDatabase->setGeometry(QRect(700, 0, 161, 40));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(710, 40, 256, 431));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1208, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Extrair Caracter\303\255sticas", 0, QApplication::UnicodeUTF8));
        tbCaminhoArquivo->setText(QString());
        tbCaminhoArquivo->setPlaceholderText(QApplication::translate("MainWindow", "Caminho arquivo", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        lblVideoProcessado->setText(QApplication::translate("MainWindow", "Video Processado", 0, QApplication::UnicodeUTF8));
        lblVideoOriginal->setText(QApplication::translate("MainWindow", "Original", 0, QApplication::UnicodeUTF8));
        tbTrainningPath->setText(QString());
        tbTrainningPath->setPlaceholderText(QApplication::translate("MainWindow", "Caminho arquivo", 0, QApplication::UnicodeUTF8));
        btTrainningPath->setText(QApplication::translate("MainWindow", "Buscar", 0, QApplication::UnicodeUTF8));
        btClearTrainning->setText(QApplication::translate("MainWindow", "Limpar Base", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Status: ", 0, QApplication::UnicodeUTF8));
        lblStatusMsg->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Tamanho DB:", 0, QApplication::UnicodeUTF8));
        lblDatabaseSize->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        btSearchDatabase->setText(QApplication::translate("MainWindow", "Pesquisar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
