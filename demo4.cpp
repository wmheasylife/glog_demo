/*
wmh@VM-4-3-ubuntu:~/workroot/cppFile/glog_demo/build$ ls -l
total 268
-rwxrwxr-x  1 wmh wmh 41696 Oct 21 10:03 demo4
lrwxrwxrwx  1 wmh wmh    33 Oct 21 10:03 demo4.ERROR -> log_error_20241021-100310.2614803
lrwxrwxrwx  1 wmh wmh    32 Oct 21 10:03 demo4.INFO -> log_info_20241021-100310.2614803
lrwxrwxrwx  1 wmh wmh    35 Oct 21 10:03 demo4.WARNING -> log_warning_20241021-100310.2614803



*/



#include <glog/logging.h>

int main(int argc, char* argv[]) {
    // 初始化glog
    // google::InitGoogleLogging(argv[0]);
    google::InitGoogleLogging("demo4");

    // 设置日志文件保存位置
    google::SetLogDestination(google::INFO, "./log_info_");
    google::SetLogDestination(google::WARNING, "./log_warning_");
    google::SetLogDestination(google::ERROR, "./log_error_");
    google::SetLogDestination(google::FATAL, "./log_fatal_");

    // 输出不同级别的日志信息
    LOG(INFO) << "This is an info message.";
    LOG(WARNING) << "This is a warning message.";
    LOG(ERROR) << "This is an error message.";
    // LOG(FATAL) << "This is a fatal message."; // 会导致程序退出

    // 条件日志
    int x = 10;
    LOG_IF(INFO, x > 5) << "x is greater than 5.";

    // 检查宏
    CHECK_EQ(x, 10) << "x should be 10.";

    // 关闭glog
    google::ShutdownGoogleLogging();
    return 0;
}
