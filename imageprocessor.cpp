#include "imageprocessor.h"
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

QList<QString> ImageProcessor::getFilesToProcess(QString sDir){
    QDir dir(sDir);
    QFileInfoList list = dir.entryInfoList();
    QList<QString> filesDB;

    for (int iList=0;iList<list.count();iList++)
    {
        QFileInfo info = list[iList];
        QString sFilePath = info.filePath();

        if (info.isDir())
        {
            // recursive
            if (info.fileName()!=".." && info.fileName()!=".")
            {
                QList<QString> files = ImageProcessor::getFilesToProcess(sFilePath);
                foreach(QString file, files){
                    filesDB.append(file);
                }
            }
        }
        else
        {
            if(!sFilePath.contains("_msk",Qt::CaseInsensitive)){
                filesDB.append(sFilePath);
            }
        }
    }

    return filesDB;
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
                meta_descriptor metaDesc = ExtractDescriptorImage(sFilePath);
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
    //RecurseDirectory(sDirPath);
    QList<QString> filesDB = this->getFilesToProcess(sDirPath);
    qDebug() << "Files to process: " << filesDB.count();

    for(int i=0;i<filesDB.count();i++){
        QString sFilePath = filesDB.at(i);
        meta_descriptor metaDesc = ExtractDescriptorImage(sFilePath);
        imgDescDatabase.push_back(metaDesc);
    }

    databaseTrainningComplete = true;
    emit trainningComplete();
    qDebug() << "Database trainning complete";
}

meta_descriptor ImageProcessor::ExtractDescriptorImage(QString sImagePath){
    meta_descriptor metaDescResult;
    Mat image, imageOriginal, imageMask, imageGray, imageProcessed;
    QFile f(sImagePath);
    QFileInfo fileInfo(f.fileName());
    QString mskFilePath = fileInfo.absolutePath() + "/" + fileInfo.baseName() + "_msk." + fileInfo.suffix();
    //qDebug() << "Image Path: " << sImagePath;
    //qDebug() << "Mask Path: " << mskFilePath;

    imageOriginal = imread(sImagePath.toStdString(), CV_LOAD_IMAGE_UNCHANGED);
    imageMask = imread(mskFilePath.toStdString(), CV_LOAD_IMAGE_UNCHANGED);

    //cv::resize(imageOriginal,imageOriginal,Size(45,55));

    if(!imageOriginal.data){
        qDebug() << "Erro ao ler imagem";
        qDebug() << "Path: " << sImagePath;
    }

    if(!imageMask.data){
        qDebug() << "Erro ao ler imagem";
        qDebug() << "Path: " << mskFilePath;
        image = imageOriginal;
    }else{
        image = imageOriginal - imageMask;
    }


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
        return metaDescResult;
    }
    //imageGray = image.clone();
    imageProcessed = image.clone();

    //cvtColor(image, imageGray, CV_BGR2GRAY);

    //cvtColor(image, imageGray, CV_8U);
    //imshow("",imageGray);


    //SIFT
    //cv::FeatureDetector* featureDetector = new cv::SiftFeatureDetector();
    //cv::DescriptorExtractor* descriptorExtractor = new cv::SiftDescriptorExtractor();

    //ORB
    //cv::FeatureDetector* featureDetector = new OrbFeatureDetector();
    //cv::DescriptorExtractor* descriptorExtractor = new OrbDescriptorExtractor();

    //FAST + SIFT
    //cv::FeatureDetector* featureDetector = new FastFeatureDetector();
    //cv::DescriptorExtractor* descriptorExtractor = new cv::SiftDescriptorExtractor();

    //MSER + SIFT
    cv::FeatureDetector* featureDetector = new cv::MserFeatureDetector();
    cv::DescriptorExtractor* descriptorExtractor = new cv::SiftDescriptorExtractor();

    //MSER + FREAK
    //cv::FeatureDetector *featureDetector = new cv::MserFeatureDetector();
    //cv::DescriptorExtractor *descriptorExtractor = new cv::FREAK();

    //SUFT
    //cv::FeatureDetector* featureDetector = new cv::SurfFeatureDetector();
    //cv::DescriptorExtractor* descriptorExtractor = new cv::SurfDescriptorExtractor();

    //SURF + FREAK
    //cv::FeatureDetector* featureDetector = new cv::SurfFeatureDetector();
    //cv::DescriptorExtractor *descriptorExtractor = new cv::FREAK();

    //KAZE
    //cv::FeatureDetector* featureDetector = new cv::KazeFeatureDetector();
    //cv::DescriptorExtractor* descriptorExtractor = new cv::KazeDescriptorExtractor();

    cv::Mat mask(0, 0, CV_8UC1);

    cv::Mat descriptors;
    std::vector<cv::KeyPoint> keypoints;
    featureDetector->detect(image, keypoints, mask);
    descriptorExtractor->compute(image,keypoints,descriptors);
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

    metaDescResult.descriptor = descriptors;
    metaDescResult.keypoints = keypoints;
    metaDescResult.filePath = sImagePath;
    return metaDescResult;
}


void ImageProcessor::Search(){
    emit searchStart();
    searchResult.clear();

    BruteForceMatcher< L2<float> > matcher;
    //BFMatcher matcher(NORM_L2);

    //FlannBasedMatcher matcher;
    //std::vector<cv::Mat> vetDescriptors;
    //vector< DMatch > matches;
    //cv::Mat imgPesquisada;
    meta_descriptor metaDescSearch;

    /*
    foreach(meta_descriptor metaDesk, imgDescDatabase){
        vetDescriptors.push_back(metaDesk.descriptor);
    }


    metaDescSearch = this->ExtractDescriptorImage(*searchImgFilePath);
    imgPesquisada = imread(searchImgFilePath->toStdString(), CV_LOAD_IMAGE_COLOR);

    matcher.add(vetDescriptors);
    matcher.train();
    matcher.knnMatch(metaDescSearch.descriptor,matches);

    foreach(DMatch match, matches){
        qDebug() << "Match Image: " << imgDescDatabase.at(match.trainIdx).filePath;
        qDebug() << "Match: " << match.distance;

    }
    */


    foreach(meta_descriptor metaDesk, imgDescDatabase){
        vector< DMatch > matches;
        matcher.match(metaDescSearch.descriptor,metaDesk.descriptor, matches);
        //matcher.match(metaDescSearch.descriptor,trainDescriptors,matches);
        double max_dist = 0; double min_dist = 100;
        foreach(DMatch match, matches){

            double dist = match.distance;
            if( dist < min_dist ) min_dist = dist;
            if( dist > max_dist ) max_dist = dist;
        }

        std::vector< DMatch > good_matches;

        foreach(DMatch match, matches){
            //SIFT = 2.2
            //SURF = 6
            if( match.distance <=2.2*min_dist )
            {
                good_matches.push_back(match);
            }

        }
        qDebug() << "Image: " << metaDesk.filePath;
        qDebug() << "Good Matches: " << good_matches.size();

        searchResult.insert(good_matches.size(), metaDesk.filePath);
    }

    emit searchComplete();
}

void ImageProcessor::DoWork(){

    if(!databaseTrainningComplete){
        TrainDatabase(trainningDirPath);
    }
}
