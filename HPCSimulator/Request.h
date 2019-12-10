#pragma once

#include "Job.h"
#include <string>

class Request
{
public:
	std::string type;
	int nCore;
	int Time;
	int nGPU;
	Job job;
	Request(void);
	Request(Job reqJob);
};

