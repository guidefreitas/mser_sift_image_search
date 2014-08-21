#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QObject>
#include <QThread>
#include <QImage>
#include <QList>
#include <opencv2/opencv.hpp>
#include "util.h"
#include "OpenCL/opencl.h"

using namespace cv;

struct meta_descriptor {
    QString filePath;
    cv::Mat descriptor;
    std::vector<cv::KeyPoint> keypoints;
};

class ImageProcessor : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor(QObject *parent = 0);
    QList<QString> getFilesToProcess(QString sDir);
    meta_descriptor ExtractDescriptorImage(QString sImagePath);
    void DoSetup(QThread &cThread);
    void ClearTranningDatabase();
    void Search();
    QList<meta_descriptor> imgDescDatabase;
    QMap<int, QString> searchResult;
    QString searchImgFilePath;
    QString trainningDirPath;
    bool Stop;
    Util *util;
    bool databaseTrainningComplete;

private:
    Mat frameAnt;
    Mat element;
    bool Interseccao(Mat img1, Mat img2);
    void RecurseDirectory(const QString& sDir);
    void TrainDatabase(QString sDirPath);



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
