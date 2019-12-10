#pragma once

#include "NumberGenerator.h"
#include <stdexcept>
#include <string>
#include <iostream>

class Job
{
public:/*
	int jobId;
	*/
	int computeTime;
	int nCore;
	int nGPU;
	Job(void);
	Job(std::string type);
};

