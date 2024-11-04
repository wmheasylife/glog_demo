#include <glog/logging.h>

int main(int argc, char* argv[]) {
    google::InitGoogleLogging(argv[0]); 
    LOG(INFO) << "Found 100 cookies";
    LOG(WARNING) << "Found 100 cookies";
    LOG(ERROR) << "Found 100 cookies";
}

