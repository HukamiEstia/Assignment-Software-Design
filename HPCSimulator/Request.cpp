#include "Request.h"

Request::Request(void) {}

Request::Request(Job reqJob) {
	nCore = reqJob.nCore;
	Time = reqJob.computeTime;
	nGPU = reqJob.nGPU;
	job = reqJob;
}