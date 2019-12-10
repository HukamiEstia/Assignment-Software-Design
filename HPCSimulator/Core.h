#pragma once

//#include "Job.h"
#include <ctime>

class Core
{
public:
	
	int speed;
	bool GPU;
	bool isAvailable;
	//Job job;
	time_t lastJobStart;
	//void assignJob(Job job);
	void update(void);
	/**/

	Core(void);
	Core(int speed, bool hasGPU = false);
};

