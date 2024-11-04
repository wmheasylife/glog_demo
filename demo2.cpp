#include <iostream>
#include <glog/logging.h>
 
int main(int argc, char** argv) {
	FLAGS_alsologtostderr = 1;  // log信息输出了stderr设备，而不将log信息写入到log文件。
	google::InitGoogleLogging(argv[0]);
    google::SetLogDestination(google::INFO, "./"); //指定输出日志文件路径
 
    //分颜色输出
    FLAGS_colorlogtostderr = true;  // 分颜色输出
    //设置记录到stderr的log的级别
    FLAGS_stderrthreshold = google::INFO;    // 将log信息输出到stderr，并且将log信息写入到log文件。minloglevel
                                            // 设置最小的log等级，比如讲该标志位设置为2，那么只会显示和记 录ERROR以及FATAL这两种类型的log信息。
 
    // 日志等级分为INFO, WARNING, ERROR, FATAL,如果是FATAL级别这直接运行报错
	LOG(INFO) << "INFO LOG!";       //正常色
	LOG(WARNING) << "WARNING LOG!"; //黄色
	LOG(ERROR) << "ERROR LOG!";     // 红色警告
	//LOG(FATAL) << "FATAL LOG!";   // 直接报错结束
 
 
    // 条件输出
    int count = 100;
	LOG_IF(INFO, count > 10) << "count is greater than 10";
 
    // 频率输出，本质上是通过google::COUNTER这个计数机实现的
    for (int i = 1; i < 10; i++)
    {
        LOG_EVERY_N(ERROR, 3) << "每隔3次输出一次 " << i;
        LOG_FIRST_N(ERROR, 2) << "前两次输出 " << i;
        LOG_IF_EVERY_N(WARNING, 1 < 2, 2) << "条件输出 + 频率 - " << google::COUNTER;//记录该语句被执行次数，从1开始
    }
 
    //当要结束glog时必须关闭库，否则会内存溢出
    google::ShutdownGoogleLogging();
 
	return 0;
}