/*
演示内容： 将所有日志都输出到屏幕上
*/
#include <glog/logging.h>
#include <chrono>

int main(int argc, char* argv[]) {
    google::InitGoogleLogging(argv[0]);

    // 配置 glog 的标志
    FLAGS_logtostderr = 1;  // 将所有日志输出到 stderr（屏幕）
    FLAGS_stderrthreshold = google::INFO;  // 将 INFO 及以上级别的日志输出到 stderr
    FLAGS_log_dir = "";  // 禁止输出到文件

    LOG(INFO) << "This is an info log message.";
    LOG(WARNING) << "This is a warning log message.";
    LOG(ERROR) << "This is an error log message.";

    google::ShutdownGoogleLogging();
    return 0;
}
