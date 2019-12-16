#include "Job.h"

Job::Job(void) {
	computeTime = 0;
	nCore = 0;
	nGPU = 0;
}

Job::Job(const Job &job) {
	//std::cout << "job copy constructor \n";
	Id = job.Id;
	computeTime = job.computeTime;
	nCore = job.nCore;
	nGPU = job.nGPU;
}

Job::Job(std::string type)
{
	int totalCore = 128*16;
	int totalGPU = 8*2;
	nGPU = 0;
	
	int h = 3600;
	
	if (type == "short") {
		int mean = (int)(0.5*h);
		int stddev = (int)(0.25*h);
		int min = 0;
		int max = h;
		NormalDistGenerator timeGenerator = NormalDistGenerator(mean, stddev, min, max);
		computeTime = timeGenerator();

		int coreMean = 16;
		int coreStddev = 4;
		int coreMin = 1;
		int coreMax = 32;
		NormalDistGenerator nCoreGenerator = NormalDistGenerator(coreMean, coreStddev, coreMin, coreMax);
		nCore = nCoreGenerator();
	}
	else if (type == "medium"){
		int timeMean = 4 * h;
		int timeStddev = 0.5 * h;
		int timeMin = 0;
		int timeMax = 8 * h;

		NormalDistGenerator timeGenerator = NormalDistGenerator(timeMean, timeStddev, timeMin, timeMax);
		computeTime = timeGenerator();

		int coreMin;
		if (computeTime < h) {
			coreMin = 2 * 16;
		}
		else {
			coreMin = 1;
		}
		int coreMean = (int)(0.05 * totalCore);
		int coreStddev = (int)(0.025 * totalCore);
		int coreMax = (int)(0.1 * totalCore);

		NormalDistGenerator nCoreGenerator = NormalDistGenerator(coreMean, coreStddev, coreMin, coreMax);
		nCore = nCoreGenerator();
	}
	else if (type == "large"){
		int timeMean = 8 * h;
		int timeStddev = 4 * h;
		int timeMin = 0;
		int timeMax = 16 * h;
		NormalDistGenerator timeGenerator = NormalDistGenerator(timeMean, timeStddev, timeMin, timeMax);
		computeTime = timeGenerator();

		int coreMin;
		if (computeTime < 8 * h) {
			coreMin = (int)(0.1 * totalCore);
		}
		else {
			coreMin = 1;
		}
		int coreMean = (int)(0.25 * totalCore);
		int coreStddev = (int)(0.125 * totalCore);
		int coreMax = (int)(0.5 * totalCore);
		NormalDistGenerator nCoreGenerator = NormalDistGenerator(coreMean, coreStddev, coreMin, coreMax);

		nCore = nCoreGenerator();
	}
	else if (type == "huge"){
		int timeMean = 32 * h;
		int timeStddev = 8 * h;
		int timeMin = 0;
		int timeMax = 64 * h;
		NormalDistGenerator timeGenerator = NormalDistGenerator(timeMean, timeStddev, timeMin, timeMax);

		computeTime = timeGenerator();

		int coreMin;
		if (computeTime < 16 * h) {
			coreMin = (int)(0.5 * totalCore);
		}
		else {
			coreMin = 1;
		}
		int coreMean = (int)(0.5 * totalCore);
		int coreStddev = (int)(0.25 * totalCore);
		int coreMax = totalCore;
		NormalDistGenerator nCoreGenerator = NormalDistGenerator(coreMean, coreStddev, coreMin, coreMax);

		nCore = nCoreGenerator();
	}
	else if (type == "gpu") {
		int timeMean = 8 * h;
		int timeStddev = 2 * h;
		int timeMin = 0;
		int timeMax = 16 * h;
		NormalDistGenerator timeGenerator = NormalDistGenerator(timeMean, timeStddev, timeMin, timeMax);

		int GPUMean = (int)(0.25 * totalGPU);
		int GPUStddev = (int)(0.125 * totalGPU);
		int GPUMin = 1;
		int GPUMax = (int)(0.5 * totalGPU);
		NormalDistGenerator nGPUGenerator = NormalDistGenerator(GPUMean, GPUStddev, GPUMin, GPUMax);

		int coreMean = (int)(0.05 * 16 * totalGPU);
		int coreStddev = (int)(0.025 * 16 * totalGPU);
		int coreMin = 1;
		int coreMax = (int)(0.1 * 16 * totalGPU);
		NormalDistGenerator nCoreGenerator = NormalDistGenerator(GPUMean, GPUStddev, GPUMin, GPUMax);

		computeTime = timeGenerator();
		nCore = nCoreGenerator();
		nGPU = nCoreGenerator();

	}
	else {
		throw std::invalid_argument("unknown job type");
	}
}

void Job::Compute(int speed) {
	computeTime -= speed;
}

int Job::GetComputeTime(void){
	return computeTime;
}

int Job::GetnCore(void){
	return nCore;
}

int Job::GetnGPU(void){
	return nGPU;
}

int Job::GetId(void){
	return Id;
}