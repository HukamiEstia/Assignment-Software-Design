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

	std::vector<User> supports;
	std::vector<User> researchers;
	std::vector<User> students;
    
    Scheduler scheduler;
    Simulator HPC;

public:
    Simulation(void);
    Simulation(Config& conf);
    void Start(void);
    void Run(void);
    bool IsRunning(void);
};