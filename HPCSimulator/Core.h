#pragma once

#include "Job.h"
#include <ctime>

class Core
{
private:
	int speed;
	bool GPU;
	bool isAvailable;
	Job job;

public:
	
	void Run(void);
	void AssignJob(Job job);
	/**/
	bool IsAvailable(void);
	bool isGPU(void);
	Core(void);
	Core(int speed, bool hasGPU = false);
};

