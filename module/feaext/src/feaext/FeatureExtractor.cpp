#include "feaext/FeatureExtractor.h"
#include <iostream>
#include "common/common.hpp"
#include "glog/logging.h"
#include "opencv2/imgcodecs.hpp"

using namespace std;
using namespace common;
using namespace feaext;
using namespace cv;

FeatureExtractor::FeatureExtractor(int featureNums) {
    featureDetector_ = ORB::create(featureNums, 1.2f, 8);
}

vector<cv::KeyPoint> FeatureExtractor::extract(const string& file) {
    // read image
    Mat img = imread(file, IMREAD_UNCHANGED);
    if (img.empty()) {
        LOG(FATAL) << "cannot open image from file \"" << file << "\"";
    }

    // detect feature
    vector<KeyPoint> keyPoints;
    featureDetector_->detect(img, keyPoints);
    return keyPoints;
}