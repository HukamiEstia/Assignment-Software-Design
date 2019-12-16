#pragma once

#include "User.h"
#include "Scheduler.h"
#include "Simulator.h"
#include "Config.h"
#include <optional>

class Simulation
{
private:
    bool running;
    Config* config;
    int time;

	std::vector<ITSupport> supports;
	std::vector<Researcher> researchers;
	std::vector<Student> students;
    
    Scheduler scheduler;
    Simulator HPC;

public:
    Simulation(void);
    Simulation(Config& conf);
    void Start(void);
    void Run(void);
    bool IsRunning(void);
};