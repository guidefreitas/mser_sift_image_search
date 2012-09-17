#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QImage>
#include <opencv2/opencv.hpp>
#include "util.h"

using namespace cv;

struct meta_descriptor {
    QString filePath;
    cv::Mat descriptor;
};

class ImageProcessor : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor(QObject *parent = 0);
    void DoSetup(QThread &cThread);
    void ClearTranningDatabase();
    void Search();
    QList<meta_descriptor> imgDescDatabase;
    QMap<int, QString> searchResult;
    QString *searchImgFilePath;
    QString *trainningDirPath;
    bool Stop;
    Util *util;
    bool databaseTrainningComplete;

private:
    Mat frameAnt;
    Mat element;
    bool Interseccao(Mat img1, Mat img2);
    void RecurseDirectory(const QString& sDir);
    void TrainDatabase(QString sDirPath);
    cv::Mat ExtractDescriptorImage(QString sImagePath);


signals:
    void captureOriginalFrame(QImage);
    void captureFrame(QImage);
    void trainningComplete();
    void trainningStart();
    void trainningClear();
    void searchStart();
    void searchComplete();



public slots:
    void DoWork();
    
};

#endif // IMAGEPROCESSOR_H
