#include "User.h"

User::User(void) {}

ITSupport::ITSupport(void) {
	body = "support";
	budget = 0;
	int lastRequest = 0;
}

Researcher::Researcher(void) {
	body = "researcher";
	budget = 100;
	int lastRequest = 0;
}

Student::Student(void){
	body = "student";
	budget = 50;
	int lastRequest = 0;
}  

Job User::GenerateJob(std::string type) {
	Job newJob = Job(type);
	std::cout << "generated job: " << newJob.GetnCore() << "cores \n";
	return newJob;
}

void User::SendRequest(Scheduler* scheduler) {
	std::cout << "sending request \n";
	Request reqToSend = *req;
	(*scheduler).AddRequest(reqToSend);
	//std::cout << "request sent\n";
	req.reset();
}

bool User::HasRequest(void) {
	if (req) {
		return true;
	}
	else {
		return false;
	}
}

std::string User::GetBody(void){
	return body;
}

void ITSupport::GenerateRequest(int time) {
	ExpDistGenerator timeGenerator = ExpDistGenerator(0.01);
	int minTime = timeGenerator();

	if (time > minTime){
		//std::cout << "support generating request  \n";

		ExpDistGenerator typeGenerator = ExpDistGenerator(0.5);
		int nType = sizeof(types)/sizeof(types[0]);
		int n = nType;
		//std::cout << n << "\n";
		while (n < 0 || n >= nType){
			n = typeGenerator();
		} 
		std::string type = types[n];
		//std::cout << "creating job:" << type << "\n";
		Job newJob = GenerateJob(type);
		//std::cout << "created job : \n";
		//std::cout << "cores :" << newJob.GetnCore() << "\n";
		//std::cout << "GPU :" << newJob.GetnGPU() << "\n";
		//std::cout << "seconds :" << newJob.GetComputeTime() << "\n";
		req = Request(type, newJob, time);
	}	
}

void ITSupport::GenerateRequest(int time, std::string type) {
	
	ExpDistGenerator timeGenerator = ExpDistGenerator(0.01);
	int minTime = timeGenerator();

	if (time > minTime){
		//std::cout << "support generating request \n";
		//std::cout << "creating job:" << type << "\n";
		Job newJob = GenerateJob(type);
		//std::cout << "created job : \n";
		//std::cout << "cores :" << newJob.GetnCore() << "\n";
		//std::cout << "GPU :" << newJob.GetnGPU() << "\n";
		//std::cout << "seconds :" << newJob.GetComputeTime() << "\n";
		req = Request(type, newJob, time);
	}	
}

void Researcher::GenerateRequest(int time) {
	
	ExpDistGenerator timeGenerator = ExpDistGenerator(0.05);
	int minTime = timeGenerator();

	if (time > minTime){
		//std::cout << "researcher generating request \n";

		ExpDistGenerator typeGenerator = ExpDistGenerator(0.3);
		int nType = sizeof(types)/sizeof(types[0]);
		int n = nType;
		//std::cout << n << "\n";

		while (n < 0 || n >= nType){
			n = typeGenerator();
		} 
		std::string type = types[n];
		//std::cout << "creating job:" << type << "\n";
		Job newJob = GenerateJob(type);
		//std::cout << "created job : \n";
		//std::cout << "cores :" << newJob.GetnCore() << "\n";
		//std::cout << "GPU :" << newJob.GetnGPU() << "\n";
		//std::cout << "seconds :" << newJob.GetComputeTime() << "\n";
		req = Request(type, newJob, time);
	}	
}

void Student::GenerateRequest(int time) {
	
	ExpDistGenerator timeGenerator = ExpDistGenerator(0.03);
	int minTime = timeGenerator();

	if (time > minTime){
		//std::cout << "student generating request \n";

		ExpDistGenerator typeGenerator = ExpDistGenerator(0.9);
		int nType = sizeof(types)/sizeof(types[0]);
		int n = nType;
		//std::cout << n << "\n";
		while (n <= 0 || n >= nType){
			n = typeGenerator();
		} 
		std::string type = types[n];
		//std::cout << "creating job:" << type << "\n";
		Job newJob = GenerateJob(type);
		//std::cout << "created job : \n";
		//std::cout << "cores :" << newJob.GetnCore() << "\n";
		//std::cout << "GPU :" << newJob.GetnGPU() << "\n";
		//std::cout << "seconds :" << newJob.GetComputeTime() << "\n";
		req = Request(type, newJob, time);
	}	
}