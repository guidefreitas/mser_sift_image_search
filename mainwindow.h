#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "imageprocessor.h"
#include "util.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //Processor *processor;
    ImageProcessor *ip;
    QThread *cThread;

private slots:
    void on_pushButton_clicked();
    void frameCaptured(QImage);
    void frameOriginalCaptured(QImage);
    void on_pushButton_3_clicked();
    void on_btTrainningPath_clicked();
    void trainningComplete();
    void trainningStart();
    void trainningClear();
    void searchStart();
    void searchComplete();
    void on_btClearTrainning_clicked();

    void on_btSearchDatabase_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
