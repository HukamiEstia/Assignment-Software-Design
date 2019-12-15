#include "Request.h"

Request::Request(void) {
	nCore = 0;
	nGPU = 0;
	job = Job();
}

Request::Request(std::string noRequest){
	type = noRequest;
	nCore = 0;
	nGPU = 0;
	job = Job();
}

Request::Request(std::string type, Job reqJob) {
	Request::type = type;
	nCore = reqJob.GetnCore();
	nGPU = reqJob.GetnGPU();
	job = reqJob;
}