#include "imageprocessor.h"
#include <QDebug>
#include <QFile>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/legacy/legacy.hpp>
#include <vector>

ImageProcessor::ImageProcessor(QObject *parent) :
    QObject(parent)
{
    databaseTrainningComplete = false;
}

void ImageProcessor::RecurseDirectory(const QString& sDir)
{
    QDir dir(sDir);
    QFileInfoList list = dir.entryInfoList();
    for (int iList=0;iList<list.count();iList++)
    {
        QFileInfo info = list[iList];

        QString sFilePath = info.filePath();

        if (info.isDir())
        {
            // recursive
            if (info.fileName()!=".." && info.fileName()!=".")
            {
                ImageProcessor::RecurseDirectory(sFilePath);
            }
        }
        else
        {
            if(!sFilePath.contains("_msk",Qt::CaseInsensitive)){
                qDebug() << "Extraindo descritores: " << sFilePath;
                cv::Mat descriptor = ExtractDescriptorImage(sFilePath);
                meta_descriptor metaDesc;
                metaDesc.filePath = sFilePath;
                metaDesc.descriptor = descriptor;
                imgDescDatabase.push_back(metaDesc);
            }
        }
    }
}

void ImageProcessor::DoSetup(QThread &cThread){
    connect(&cThread, SIGNAL(started()), this, SLOT(DoWork()));
    Stop = false;
    util = new Util;
}

void ImageProcessor::ClearTranningDatabase(){
    imgDescDatabase.clear();
    databaseTrainningComplete = false;
    emit trainningClear();
}

void ImageProcessor::TrainDatabase(QString sDirPath){

    qDebug() << "Starting database trainning";
    emit trainningStart();
    RecurseDirectory(sDirPath);
    databaseTrainningComplete = true;
    emit trainningComplete();
    qDebug() << "Database trainning complete";
}

cv::Mat ImageProcessor::ExtractDescriptorImage(QString sImagePath){
    Mat image, imageOriginal, imageMask, imageGray, imageProcessed;
    QFile f(sImagePath);
    QFileInfo fileInfo(f.fileName());
    QString mskFilePath = fileInfo.absolutePath() + "/" + fileInfo.baseName() + "_msk." + fileInfo.suffix();
    //qDebug() << "Image Path: " << sImagePath;
    //qDebug() << "Mask Path: " << mskFilePath;

    imageOriginal = imread(sImagePath.toStdString(), CV_LOAD_IMAGE_COLOR);
    imageMask = imread(mskFilePath.toStdString(), CV_LOAD_IMAGE_COLOR);


    if(!imageOriginal.data){
        qDebug() << "Erro ao ler imagem";
        qDebug() << "Path: " << sImagePath;
    }

    if(!imageMask.data){
        qDebug() << "Erro ao ler imagem";
        qDebug() << "Path: " << mskFilePath;
    }

    image = imageOriginal - imageMask;

    // PRE-PROCESSAMENTO

    //medianBlur(image,image,9);

    /*
    threshold(mask,mask,1,255,THRESH_BINARY);
    mask.inv();
    threshold(foreground,foreground,64,255,THRESH_BINARY);
    medianBlur(foreground,foreground,3);
    */

    // END PRE-PROCESSAMENTO

    if(!image.data){
        qDebug() << "Erro ao ler imagem";
        cv::Mat *matNull = new cv::Mat();
        return *matNull;
    }
    imageGray = image.clone();
    imageProcessed = image.clone();

    cvtColor(image, imageGray, CV_BGR2GRAY);

    //cvtColor(image, imageGray, CV_8U);
    //imshow("",imageGray);


    //SIFT
    //cv::FeatureDetector* featureDetector = new cv::SiftFeatureDetector();
    //cv::DescriptorExtractor* descriptorExtractor = new cv::SiftDescriptorExtractor();

    //ORB
    //cv::FeatureDetector* featureDetector = new OrbFeatureDetector();
    //cv::DescriptorExtractor* descriptorExtractor = new OrbDescriptorExtractor();

    //FAST + SIFT
    //FastFeatureDetector featureDetector(15);
    //cv::DescriptorExtractor* descriptorExtractor = new cv::SiftDescriptorExtractor();

    //MSER + SIFT
    cv::FeatureDetector* featureDetector = new cv::MserFeatureDetector();
    cv::DescriptorExtractor* descriptorExtractor = new cv::SiftDescriptorExtractor();


    cv::Mat mask(0, 0, CV_8UC1);

    cv::Mat descriptors;
    std::vector<cv::KeyPoint> keypoints;
    featureDetector->detect(imageGray, keypoints, mask);
    //descriptorExtractor->compute(image, keypoints, descriptors);
    descriptorExtractor->compute(image,keypoints,descriptors);
    //featureDetector.compute(imageGray, keypoints, descriptors);
    /*
    cv::drawKeypoints(imageProcessed,
           keypoints,
           imageProcessed,
            cv::Scalar(255,255,255),
            cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    */

    IplImage iplimg = imageProcessed;

    QImage qImgProcessed = util->IplImage2QImage(&iplimg);
    emit captureFrame(qImgProcessed);

    return descriptors;
}


void ImageProcessor::Search(){
    emit searchStart();
    searchResult.clear();

    BruteForceMatcher< L2<float> > matcher;

    /*
    FlannBasedMatcher matcher;
    vector<cv::Mat> dbDescriptors;
    foreach(QString key, imgDescDatabase.keys()){
        cv::Mat tmpDescriptor = imgDescDatabase[key];
        dbDescriptors.push_back(tmpDescriptor);
    }

    matcher.add(dbDescriptors);
    matcher.train();
    */

    cv::Mat imgSearchDescriptor = this->ExtractDescriptorImage(*searchImgFilePath);

    foreach(meta_descriptor metaDesk, imgDescDatabase){
        vector< DMatch > matches;
        cv::Mat tmpDescriptor = metaDesk.descriptor;
        matcher.match(imgSearchDescriptor,tmpDescriptor, matches);
        double max_dist = 0; double min_dist = 100;

        foreach(DMatch match, matches){
            double dist = match.distance;
            if( dist < min_dist ) min_dist = dist;
            if( dist > max_dist ) max_dist = dist;
        }

        qDebug() << "Max dist : " << max_dist;
        qDebug() << "Min dist : " << min_dist;

        std::vector< DMatch > good_matches;

        foreach(DMatch match, matches){
            //SIFT = 2.2
            //SURF = 6
            if( match.distance < 2.2*min_dist )
            {
                good_matches.push_back(match);
            }

        }

        searchResult.insert(good_matches.size(), metaDesk.filePath);

    }

    emit searchComplete();
}

void ImageProcessor::DoWork(){

    if(!databaseTrainningComplete){
        TrainDatabase(*trainningDirPath);
    }
}
