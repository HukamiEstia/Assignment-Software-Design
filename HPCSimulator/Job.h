#pragma once

#include "NumberGenerator.h"
#include <stdexcept>
#include <string>
#include <iostream>

class Job
{
private:	
	int Id;
	int computeTime;
	int nCore;
	int nGPU;

public:
	Job(void);
	Job(std::string type);
	int GetComputeTime(void);
	int GetnCore(void);
	int GetnGPU(void);
	int GetId(void);
	void Compute(int speed);
};

