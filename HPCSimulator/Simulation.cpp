#include "Simulation.h"

Simulation::Simulation(void){}

Simulation::Simulation(Config& conf){
    /*
    Initialize the parameters of the simulation
    from the config file and create the users.
    Then initialize the scheduler and simulator.
    /**/
    config = &conf;
    time = 0;
    int Nsupport = (*config).Get_ITSupport_Number();
    int Nresearch = (*config).Get_Researcher_Number();
    int Nstudent = (*config).Get_Student_Number();

    for (int i = 0; i < Nsupport; i++) {
		ITSupport newSupport = ITSupport();
		supports.push_back(newSupport);
	}
	for (int i = 0; i < Nresearch; i++) {
		Researcher newResearcher = Researcher();
		researchers.push_back(newResearcher);

	}for (int i = 0; i < Nstudent; i++) {
		Student newStudent = Student();
		students.push_back(newStudent);
	}

    scheduler = Scheduler();
    HPC = Simulator(*config);

}
    /*
    Initialise Users
    Initialise Scheduler
    Initialise HPC

    While runing:
        for all users:
            generate/send request
                add request to scheduler
        run HPC
            ask job to scheduler
    */

void Simulation::Start(void){
    running = true;
}
bool Simulation::IsRunning(void){
    return running;
}

void Simulation::Run(){
    /*
    model the evolution of the system after one unit 
    of time (defined by simulation speed)
    /**/
    std::cout << "time: " << time << "\n";
    if (time < (*config).Get_Simulation_Time()){
        for (int i = 0; i < supports.size(); i++) {
            supports[i].GenerateRequest(time);
            if (supports[i].HasRequest()){
                supports[i].SendRequest(&scheduler);
            }
	    }
	    for (int i = 0; i < researchers.size(); i++) {
            researchers[i].GenerateRequest(time);
            if (researchers[i].HasRequest()) {
                researchers[i].SendRequest(&scheduler);
            }
	    }
        for (int i = 0; i < students.size(); i++) {
            students[i].GenerateRequest(time);
            if (students[i].HasRequest()) {
                students[i].SendRequest(&scheduler);
            }
    	}
        HPC.Run(scheduler);
        time++;
    }
    else {
        running = false;
    }

}