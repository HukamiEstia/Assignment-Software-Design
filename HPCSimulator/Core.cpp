#include "Core.h"

Core::Core(void) {}

Core::Core(int sp, bool hasGPU) {
	speed = sp;
	GPU = hasGPU;
	isAvailable = true;
}

void Core::AssignJob(Job newJob) {
	job = newJob;
	isAvailable = false;
}

bool Core::IsAvailable(void) {
	return isAvailable;
}

bool Core::isGPU(void){
	return GPU;
}
void Core::Run(void) {
	if (job.GetComputeTime() <= 0){
		isAvailable = true;
	}
	else {
		std::cout << "running... \n";
		job.Compute(speed);
	}
}