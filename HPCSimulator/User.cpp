#include "User.h"

User::User(void) {}

ITSupport::ITSupport(void) {
	const static std::string body = "ITSupport";
	budget = 0;
	int lastRequest = 0;
	const std::string types[] = {"short", "medium", "large", "huge", "gpu"};
}

Researcher::Researcher(void) {
	const static std::string body = "Researcher";
	budget = 100;
	int lastRequest = 0;
	const std::string types[] = {"short", "medium", "large", "huge", "gpu"};
}

Student::Student(void){
	const static std::string body = "Student";
	budget = 50;
	int lastRequest = 0;
	const std::string types[] = {"short", "medium", "gpu"};
}  

Job User::GenerateJob(std::string type) {
	Job newJob = Job(type);
	return newJob;
}

void User::SendRequest(Scheduler& scheduler) {
	scheduler.AddRequest(*req);
}

void ITSupport::GenerateRequest(int time) {
	
	ExpDistGenerator timeGenerator = ExpDistGenerator(0.01);
	int minTime = timeGenerator();

	if (time < minTime){
		ExpDistGenerator typeGenerator = ExpDistGenerator(0.5);
		int n = typeGenerator();
		std::string type = types[n];
		std::cout << "creating job:" << type << "\n";
		Job newJob = GenerateJob(type);
		std::cout << "created job : \n";
		std::cout << "cores :" << newJob.GetnCore() << "\n";
		std::cout << "GPU :" << newJob.GetnGPU() << "\n";
		std::cout << "seconds :" << newJob.GetComputeTime() << "\n";
		req = Request(type, newJob);
	}	
}

void Researcher::GenerateRequest(int time) {
	
	ExpDistGenerator timeGenerator = ExpDistGenerator(0.05);
	int minTime = timeGenerator();

	if (time < minTime){
		ExpDistGenerator typeGenerator = ExpDistGenerator(0.3);
		int n = typeGenerator();
		std::string type = types[n];
		std::cout << "creating job:" << type << "\n";
		Job newJob = GenerateJob(type);
		std::cout << "created job : \n";
		std::cout << "cores :" << newJob.GetnCore() << "\n";
		std::cout << "GPU :" << newJob.GetnGPU() << "\n";
		std::cout << "seconds :" << newJob.GetComputeTime() << "\n";
		req = Request(type, newJob);
	}	
}

void Student::GenerateRequest(int time) {
	
	ExpDistGenerator timeGenerator = ExpDistGenerator(0.03);
	int minTime = timeGenerator();

	if (time < minTime){
		ExpDistGenerator typeGenerator = ExpDistGenerator(0.7);
		int n = typeGenerator();
		std::string type = types[n];
		std::cout << "creating job:" << type << "\n";
		Job newJob = GenerateJob(type);
		std::cout << "created job : \n";
		std::cout << "cores :" << newJob.GetnCore() << "\n";
		std::cout << "GPU :" << newJob.GetnGPU() << "\n";
		std::cout << "seconds :" << newJob.GetComputeTime() << "\n";
		req = Request(type, newJob);
	}	
}