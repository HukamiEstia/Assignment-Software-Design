#pragma once

#include "Core.h"
#include <math.h>
#include <assert.h>
#include <vector>
#include <iostream>

class Simulator
{
private:
	int simulationSpeed;
	int nCore;
	int nGPU;
	int nUsed;
	
	std::vector<Core> cores;
	
	std::vector<Core*> smallJobCores;
	std::vector<Core*> mediumJobCores;
	std::vector<Core*> multiJobCores;
	std::vector<Core*> GPUJobCores;
	/**/
public:
	int getNumberOfCore();
	int getNumberOfGPU();
	void update();
	void print();
	Simulator(int numberOfCores, int numberOfGPU, int speed);
};

