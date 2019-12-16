#include "Core.h"

Core::Core(void) {}

Core::Core(int sp, bool hasGPU) {
    //constructor
	speed = sp;
	GPU = hasGPU;
	isAvailable = true;
}

void Core::AssignJob(Job newJob) {
	job = newJob;
	isAvailable = false;
}
int Core::GetRemainingTime(){
	return job.GetComputeTime();
}
bool Core::IsAvailable(void) {
	return isAvailable;
}

bool Core::isGPU(void){
	return GPU;
}
void Core::Run(void) {
	job.Compute(speed);
	if (job.GetComputeTime() <= 0){
		isAvailable = true;
	}
	else {
		isAvailable = false;
	}
}