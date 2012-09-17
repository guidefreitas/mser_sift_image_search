#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QDebug>
#include <QImage>
#include <QThread>
#include <QMessageBox>
#include <QFileDialog>
#include <QProgressDialog>
#include <QListWidgetItem>
#include <QIcon>

#define VIDEO_W 430
#define VIDEO_H 320

int numInfracoes = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tbCaminhoArquivo->setText("");
    ui->progressBar->setVisible(false);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


    if(ui->tbTrainningPath->text().isEmpty()){
        QMessageBox::about(this, tr("Ops"),
                     tr("Informe o caminho do diretorio de treinamento"));

        return;
    }


    ip = new ImageProcessor;

    connect(ip,SIGNAL(captureFrame(QImage)),this,SLOT(frameCaptured(QImage)));
    connect(ip,SIGNAL(captureOriginalFrame(QImage)),this,SLOT(frameOriginalCaptured(QImage)));
    connect(ip,SIGNAL(trainningStart()),this,SLOT(trainningStart()));
    connect(ip,SIGNAL(trainningComplete()),this,SLOT(trainningComplete()));
    connect(ip,SIGNAL(trainningClear()),this,SLOT(trainningClear()));

    cThread = new QThread;
    ip->DoSetup(*cThread);
    ip->moveToThread(cThread);


    ip->trainningDirPath = new QString(ui->tbTrainningPath->text());
    cThread->start();
}

void MainWindow::searchStart(){
    qDebug() << "Iniciando busca.";
    ui->lblStatusMsg->setText("Iniciando busca.");
    ui->progressBar->setVisible(true);
}

void MainWindow::searchComplete(){
    qDebug() << "Busca concluída.";
    ui->lblStatusMsg->setText("Busca concluída.");
    ui->progressBar->setVisible(false);
}

void MainWindow::trainningClear(){
    ui->lblStatusMsg->setText("Database eliminado.");
    QString sDatabaseSize = QString::number(ip->imgDescDatabase.size());
    ui->lblDatabaseSize->setText(sDatabaseSize);
}

void MainWindow::trainningStart(){
    ui->progressBar->setVisible(true);
    ui->lblStatusMsg->setText("Iniciando treinamento...");
}

void MainWindow::trainningComplete(){
    ui->progressBar->setVisible(false);
    ui->lblStatusMsg->setText("Treinamento concluido!");
    QString sDatabaseSize = QString::number(ip->imgDescDatabase.size());
    ui->lblDatabaseSize->setText(sDatabaseSize);
}

void MainWindow::frameCaptured(QImage img){
    ui->lblVideoProcessado->setPixmap(QPixmap::fromImage(img).scaled(VIDEO_W,VIDEO_H, Qt::KeepAspectRatio));
}

void MainWindow::frameOriginalCaptured(QImage img){
    ui->lblVideoOriginal->setPixmap(QPixmap::fromImage(img).scaled(210,160, Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_3_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open Image"), "/", tr("Image Files (*.jpg *.png *.tiff)"));
    ui->tbCaminhoArquivo->setText(file);

}

void MainWindow::on_btTrainningPath_clicked()
{

    QString file = QFileDialog::getExistingDirectory(this, tr("Open Dir"), "~/Desktop", NULL);
    ui->tbTrainningPath->setText(file);
}

void MainWindow::on_btClearTrainning_clicked()
{
    ip->ClearTranningDatabase();
}

bool zValueGraterThan(int a, int b){
    return a > b;
}

void MainWindow::on_btSearchDatabase_clicked()
{

    if(!ip || !ip->databaseTrainningComplete){
        QMessageBox::about(this, tr("Ops"),
                     tr("Efetue o treinamento da base antes de buscar"));

        return;
    }


    QImage imgSearch(ui->tbCaminhoArquivo->text());
    ui->lblVideoOriginal->setPixmap(QPixmap::fromImage(imgSearch).scaled(210,160, Qt::KeepAspectRatio));
    ui->listWidget->clear();

    ip->searchImgFilePath = &ui->tbCaminhoArquivo->text();
    ip->Search();

    /*
    foreach(int nGoodMatches, ip->searchResult.keys()){
        QString imgPathItem = ip->searchResult[nGoodMatches];
        qDebug() << "Matches: " << nGoodMatches;
        QImage img(imgPathItem);
        QIcon icon(QPixmap::fromImage(img).scaled(200,150, Qt::KeepAspectRatio));
        ui->listWidget->setIconSize(QSize(200, 150));
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(QSize(210, 200));
        item->setIcon(icon);
        ui->listWidget->addItem(item);
    }
    */


    QList<int> keys = ip->searchResult.keys();

    qSort(keys.begin(), keys.end(), zValueGraterThan);

    foreach(int key, keys){

        QString imgPathItem = ip->searchResult[key];
        qDebug() << "Matches: " << key;
        QImage img(imgPathItem);
        QIcon icon(QPixmap::fromImage(img).scaled(200,150, Qt::KeepAspectRatio));
        ui->listWidget->setIconSize(QSize(200, 150));
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(QSize(210, 200));
        item->setIcon(icon);
        QString sKeyMatchs = QString::number(key);
        item->setText(sKeyMatchs);
        ui->listWidget->addItem(item);

    }


}
