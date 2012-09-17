#ifndef UTIL_H
#define UTIL_H

#include <QtCore>
#include <QDebug>
#include <QImage>
#include <opencv2/opencv.hpp>

class Util
{
public:
    Util();
    QImage IplImage2QImage(const IplImage *iplImage);
    IplImage* qImage2IplImage(const QImage *qImage);
    QImage* IplImageToQImage(const IplImage * iplImage, uchar **data, double mini, double maxi);

private:
    //QVector<QRgb> colorTable;
};

#endif // UTIL_H
