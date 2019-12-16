#include "Request.h"

Request::Request(void) {
	nNode = 0;
	nNodeGPU = 0;
	job = Job();
}

Request::Request(const Request &req) {
	//std::cout << "request copy constructor \n";
	Request::type = req.type;
	Request::time = req.time;
	Request::nNode = req.nNode;
	Request::nNodeGPU = req.nNodeGPU;
	Request::job = req.job;
}

Request::Request(std::string noRequest){
	type = noRequest;
	nNode = 0;
	nNodeGPU = 0;
	job = Job();
}

Request::Request(std::string type, Job reqJob, int time) {
	Request::type = type;
	Request::time = time;
	nNode = reqJob.GetnCore() / 16;
	nNodeGPU = reqJob.GetnGPU() / 2;
	job = reqJob;
}

int Request::GetTime(void){
	return time;
}

std::string Request::GetType(void){
	return type;	
}

int Request::GetnNode(void){
	return nNode;	
}

int Request::GetnNodeGPU(void){
	return nNodeGPU;	
}

Job Request::GetJob(void){
	return job;	
}
