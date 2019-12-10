#include "Simulator.h"


Simulator::Simulator(int numberOfCores, int numberOfGPU, int speed) {
	nCore = numberOfCores;
	simulationSpeed = speed;
	assert(numberOfGPU % 2 == 0);
	nGPU = numberOfGPU;
	nUsed = 0;
	
	for (int i = 0; i < nCore; i++) {
		Core newCore;
		if (i < nGPU/2) {
			newCore = Core(speed, true);
		}
		else {
			newCore = Core(speed);
		}
		cores.push_back(newCore);
	}
	/**/
	
	for (auto c = cores.begin(); c != cores.end(); ++c) {
		std::vector<Core>::iterator cutPointGPU = cores.begin() + nGPU / 2;
		std::vector<Core>::iterator cutPointSmall = cutPointGPU + (int)(0.1 * nCore);
		if ((*c).GPU) {
			GPUJobCores.push_back(&(*c));
		}
		else if (c - cutPointGPU < (int)(0.1 * nCore)) {
			smallJobCores.push_back(&(*c));
		}
		else if (c - cutPointSmall < (int)(0.3 * nCore)) {
			mediumJobCores.push_back(&(*c));
		}
		else {
			multiJobCores.push_back(&(*c));
		}
	}
	/**/
}

int Simulator::getNumberOfCore() {
	return nCore;
}

int Simulator::getNumberOfGPU() {
	return nGPU;
}

void Simulator::print() {
	std::cout << "Total number of cores: " << nCore << "\n";
	std::cout << "Number of GPU equipped cores: " << nGPU << "\n";
	
	for (int i = 0; i < nCore; i++) {
		std::cout << cores[i].GPU << " ";
	}
	std::cout << "\n";

	for (int i = 0; i < GPUJobCores.size(); i++) {
		std::cout << (*(GPUJobCores[i])).GPU << " ";
	}
	std::cout << "\n";
	 
	for (int i = 0; i < smallJobCores.size(); i++) {
		std::cout << (*(smallJobCores[i])).GPU << " ";
	}
	std::cout << "\n";


	std::cout << mediumJobCores.size() << "\n";
	std::cout << multiJobCores.size() << "\n";
	/**/
}

void Simulator::update() {
	for (auto c = cores.begin(); c != cores.end(); ++c) {
		if ((*c).isAvailable) {

		}
	}
}