#include "User.h"
#include "Simulator.h"
#include "Config.h"
#include "Simulation.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
	Config config = Config("config");

	Simulation simulation = Simulation(config);
	simulation.Start();
	while (simulation.IsRunning()){
		//std::cout << "running \n";
		simulation.Run();
	}
}