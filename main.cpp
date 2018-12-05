#include <iostream>
#include "boost/filesystem.hpp"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;
using namespace boost::filesystem;

int main(int argc, char* argv[]) {
    google::InitGoogleLogging(argv[0]);
    google::ParseCommandLineFlags(&argc, &argv, true);
    // glog setting
    // log to std
    FLAGS_logtostderr = true;
    // for log to file
    //FLAGS_alsologtostderr = true;
    //FLAGS_colorlogtostderr = true;
    //FLAGS_log_dir = "./logs";
    //FLAGS_max_log_size = 10;  // 10M

    LOG(INFO) << "This is a CMake project template";
    LOG(INFO) << "Written by Jeffery Cheng";
    LOG(WARNING) << "Warning log";
    LOG(ERROR) << "Error log";

    cout << "hello world" << endl;

    google::ShutDownCommandLineFlags();
    google::ShutdownGoogleLogging();
    return 0;
}