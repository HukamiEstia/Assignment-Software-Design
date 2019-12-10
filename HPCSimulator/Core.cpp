#include "Core.h"

Core::Core(void) {}

Core::Core(int sp, bool hasGPU) {
	speed = sp;
	GPU = hasGPU;
	isAvailable = true;
	lastJobStart = time(0);
}
/*
void Core::assignJob(Job newJob) {
	job = newJob;
	lastJobStart = time(0);
}

void Core::update(void) {
	if (time(0) - lastJobStart > job.computeTime / speed) {
		isAvailable = true;
	}
	else {
		isAvailable = false;
	}
}

/**/