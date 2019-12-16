#pragma once

#include "Scheduler.h"
#include "Config.h"
#include "Node.h"
#include <math.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <optional>

class Simulator
{
private:
	unsigned int simulationSpeed;
	unsigned int nNode;
	unsigned int nNodeGPU;
	unsigned int nUsed;
	
	std::vector<Node> Nodes;
	
	std::vector<Node*> smallJobNodes;
	std::vector<Node*> mediumJobNodes;
	std::vector<Node*> multiJobNodes;
	std::vector<Node*> GPUJobNodes;
	/**/
public:
	Simulator(void);
	Simulator(Config config);
	int GetNumberOfNode();
	int GetNumberOfNodeGPU();
	void DispatchJob(Job newJob, std::string type);
	void Run(Scheduler& scheduler);
	void Print();
};

