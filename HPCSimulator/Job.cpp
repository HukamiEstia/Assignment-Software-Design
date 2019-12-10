#include "Job.h"

Job::Job(void) {}

Job::Job(std::string type)
{
	int totalCore = 128;
	int totalGPU = 8;
	nGPU = 0;
	
	int h = 3600;
	
	if (type == "dummy") {
		computeTime = 1;
		nCore = 1;
	}
	else if (type == "short") {
		int mean = (int)(0.5*h);
		int stddev = (int)(0.25*h);
		int min = 0;
		int max = h;
		NumberGenerator timeGenerator = NumberGenerator(mean, stddev, min, max);
		computeTime = timeGenerator();
		std::random_device random_device;
		std::mt19937 random_engine(random_device());
		std::uniform_int_distribution<int> dist(1, 2);
		nCore = dist(random_engine);
	}
	else if (type == "medium"){
		int timeMean = 4 * h;
		int timeStddev = 0.5 * h;
		int timeMin = 0;
		int timeMax = 8 * h;

		NumberGenerator timeGenerator = NumberGenerator(timeMean, timeStddev, timeMin, timeMax);
		computeTime = timeGenerator();

		int coreMin;
		if (computeTime < h) {
			coreMin = 2;
		}
		else {
			coreMin = 0;
		}
		int coreMean = (int)(0.05 * totalCore);
		int coreStddev = (int)(0.025 * totalCore);
		int coreMax = (int)(0.1 * totalCore);

		NumberGenerator nCoreGenerator = NumberGenerator(coreMean, coreStddev, coreMin, coreMax);
		nCore = nCoreGenerator();
	}
	else if ( type == "large"){
		int timeMean = 8 * h;
		int timeStddev = 4 * h;
		int timeMin = 0;
		int timeMax = 16 * h;
		NumberGenerator timeGenerator = NumberGenerator(timeMean, timeStddev, timeMin, timeMax);
		computeTime = timeGenerator();

		int coreMin;
		if (computeTime < 8 * h) {
			coreMin = (int)(0.1 * totalCore);
		}
		else {
			coreMin = 0;
		}
		int coreMean = (int)(0.25 * totalCore);
		int coreStddev = (int)(0.125 * totalCore);
		int coreMax = (int)(0.5 * totalCore);
		NumberGenerator nCoreGenerator = NumberGenerator(coreMean, coreStddev, coreMin, coreMax);

		nCore = nCoreGenerator();
	}
	else if ( type == "huge"){
		int timeMean = 32 * h;
		int timeStddev = 8 * h;
		int timeMin = 0;
		int timeMax = 64 * h;
		NumberGenerator timeGenerator = NumberGenerator(timeMean, timeStddev, timeMin, timeMax);

		computeTime = timeGenerator();

		int coreMin;
		if (computeTime < 16 * h) {
			coreMin = (int)(0.5 * totalCore);
		}
		else {
			coreMin = 0;
		}
		int coreMean = (int)(0.5 * totalCore);
		int coreStddev = (int)(0.25 * totalCore);
		int coreMax = totalCore;
		NumberGenerator nCoreGenerator = NumberGenerator(coreMean, coreStddev, coreMin, coreMax);

		nCore = nCoreGenerator();
	}
	else if (type == "gpu") {
		int timeMean = 8 * h;
		int timeStddev = 2 * h;
		int timeMin = 0;
		int timeMax = 16 * h;
		NumberGenerator timeGenerator = NumberGenerator(timeMean, timeStddev, timeMin, timeMax);

		int GPUMean = (int)(0.25 * totalGPU);
		int GPUStddev = (int)(0.125 * totalGPU);
		int GPUMin = 1;
		int GPUMax = (int)(0.5 * totalGPU);
		NumberGenerator nCoreGenerator = NumberGenerator(GPUMean, GPUStddev, GPUMin, GPUMax);

		computeTime = timeGenerator();
		nGPU = nCoreGenerator();
		nCore = nGPU / 2;

	}
	else {
		throw std::invalid_argument("unknown job type");
	}
}
