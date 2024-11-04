#include <iostream>
 
#include <glog/logging.h>
 
int main(int argc, char** argv) {
	FLAGS_logtostderr = 1;
	
	google::InitGoogleLogging(argv[0]);
 
	FLAGS_v = 2;
 
	VLOG(0) << " i is 0";
	VLOG(1) << " i is 1";
	VLOG(2) << " i is 2";
	VLOG(3) << " i is 3";
 
	return 0;
}
 