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
    /*
    Read the parameters of the simulation
    from the configuration file and store them in 
    a Config object
    /**/
	Config config = Config("config");

    /*
    initialize the simulation with the Config object
    as parameter 
    /**/
	Simulation simulation = Simulation(config);

    //start the simulation
	simulation.Start();
    
    //main loop
	while (simulation.IsRunning()){
		//std::cout << "running \n";
		simulation.Run();
	}
}