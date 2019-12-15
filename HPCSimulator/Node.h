#pragma once

#include "Job.h"
#include "Core.h"
#include <iostream>
#include <vector>
#include <optional>

class Node
{
private:
    std::vector<Core> cores;
    std::optional<std::vector<Core>> GPUs;
	bool hasGPU;
	bool isAvailable;
    int nAvailableCores;

public:
	Node(void);
	Node(int speed, bool hasGPU = false);
	void Run(void);
	void AssignJob(Job job, int& countCore, int& countGPU);
	bool IsAvailable(void);
	bool IsGPU(void);
	void Print(void);
};