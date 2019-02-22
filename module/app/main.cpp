#include <iostream>
#include <sstream>
#include <string>
#include "boost/filesystem.hpp"
#include "common/common.hpp"
#include "feaext/FeatureExtractor.h"
#include "gflags/gflags.h"
#include "glog/logging.h"

using namespace std;
using namespace boost::filesystem;
using namespace common;
using namespace feaext;

DEFINE_string(imgFolder, "../../data", "image folder");

int main(int argc, char* argv[]) {
    google::InitGoogleLogging(argv[0]);
    google::ParseCommandLineFlags(&argc, &argv, true);

    // log to console
    FLAGS_logtostderr = true;
    FLAGS_minloglevel = 0;

    // log to file
    // FLAGS_colorlogtostderr = true;
    // FLAGS_alsologtostderr = true;
    // FLAGS_log_dir = "../log";
    // FLAGS_max_log_size = 10;  // 10M

    // check img folder is exist
    if (!exists(FLAGS_imgFolder)) {
        LOG(FATAL) << "the image folder doesn't exist";
    }

    // create feature extract
    cout << section("Create ORB Feature Extractor") << endl;
    FeatureExtractor featureExtractor(100);

    // for each file, extract its feature
    cout << section("Extract Feature") << endl;
    for (directory_iterator it(FLAGS_imgFolder); it != directory_iterator(); ++it) {
        if (is_regular_file(it->path())) {
            cout << "image file: " << it->path().string() << endl;
            auto keyPoints = featureExtractor.extract(it->path().string());
            cout << "key point size = " << keyPoints.size() << endl;
        }
    }

    google::ShutDownCommandLineFlags();
    google::ShutdownGoogleLogging();
    return 0;
}