#pragma once

#include "Job.h"
#include <string>

class Request
{
public:
	std::string type;
	int nCore;
	int nGPU;
	Job job;
	Request(void);
	Request(std::string noRequest);
	Request(std::string type, Job reqJob);
};

