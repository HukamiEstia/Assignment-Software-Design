#pragma once

#include "Job.h"
#include <string>

class Request
{
private:
	std::string type;
	int time;
	int nNode;
	int nNodeGPU;
	Job job;

public:
	Request(void);
	Request(const Request &req); 
	Request(std::string noRequest);
	Request(std::string type, Job reqJob, int time);
	std::string GetType(void);
	int GetTime(void);
	int GetnNode(void);
	int GetnNodeGPU(void);
	Job GetJob(void);
};

