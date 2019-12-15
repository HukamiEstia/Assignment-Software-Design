#include "Simulation.h"

Simulation::Simulation(void){}

Simulation::Simulation(Config& conf){
    config = &conf;
    time = 0;
    int Nsupport = (*config).Get_ITSupport_Number();
    int Nresearch = (*config).Get_Researcher_Number();
    int Nstudent = (*config).Get_Student_Number();

    for (int i = 0; i < Nsupport; ++i) {
		User newSupport = User("support");
		supports.push_back(newSupport);
	}
	for (int i = 0; i < Nresearch; ++i) {
		User newResearcher = User("researcher");
		researchers.push_back(newResearcher);

	}for (int i = 0; i < Nstudent; ++i) {
		User newStudent = User("student");
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
    if (time < (*config).Get_Simulation_Time()){
        for (int i = 0; i < supports.size(); ++i) {
            std::optional<Request> request = supports[i].GenerateRequest(time);
            if (request){
                supports[i].SendRequest(*request, scheduler);
            }
	    }
	    for (int i = 0; i < researchers.size(); ++i) {
            std::optional<Request> request = researchers[i].GenerateRequest(time);
            if (request) {
            researchers[i].SendRequest(*request, scheduler);
            }
	    }
        for (int i = 0; i < students.size(); ++i) {
            std::optional<Request> request = students[i].GenerateRequest(time);
            if (request) {
                students[i].SendRequest(*request, scheduler);
            }
    	}
        HPC.Run(scheduler);
        time++;
    }
    else {
        running = false;
    }

}