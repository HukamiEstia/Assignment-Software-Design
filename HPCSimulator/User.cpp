#include "User.h"

User::User(void) {}

User::User(std::string body) {
	lastRequest = time(0);
	std::cout << "User is being created" << "\n";
}

void User::SendRequest(Request req, Scheduler& scheduler) {
	scheduler.AddRequest(req);
}

Job User::GenerateJob(std::string type) {
	Job newJob = Job(type);
	return newJob;
}

Request User::GenerateRequest(void) {
	NumberGenerator typeGenerator = NumberGenerator(1, 1, 0, 5);
	int n = typeGenerator();
	std::string type = types[n];
	std::cout << "creating job:" << type << "\n";
	Job newJob = GenerateJob(type);
	std::cout << "created job : \n";
	std::cout << "cores :" << newJob.nCore << "\n";
	std::cout << "GPU :" << newJob.nGPU << "\n";
	std::cout << "seconds :" << newJob.computeTime << "\n";
	return Request(newJob);
}
