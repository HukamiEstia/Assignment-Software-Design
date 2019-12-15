#include "Simulator.h"

Simulator::Simulator(void) {}

Simulator::Simulator(Config config) {
	nNode = config.Get_Node_Number();
	simulationSpeed = config.Get_Speed();
	nNodeGPU = config.Get_GPU_Number();
	nUsed = 0;
	
	for (int i = 0; i < nNode; i++) {
		Node newNode;
		if (i < nNodeGPU) {
			newNode = Node(simulationSpeed, true);
		}
		else {
			newNode = Node(simulationSpeed);
		}
		Nodes.push_back(newNode);
	}
	/**/
	
	for (auto c = Nodes.begin(); c != Nodes.end(); ++c) {
		std::vector<Node>::iterator cutPointGPU = Nodes.begin() + nNodeGPU;
		std::vector<Node>::iterator cutPointSmall = cutPointGPU + (int)(0.1 * nNode);
		if ((*c).IsGPU()) {
			GPUJobNodes.push_back(&(*c));
		}
		else if (c - cutPointGPU < (int)(0.1 * nNode)) {
			smallJobNodes.push_back(&(*c));
		}
		else if (c - cutPointSmall < (int)(0.3 * nNode)) {
			mediumJobNodes.push_back(&(*c));
		}
		else {
			multiJobNodes.push_back(&(*c));
		}
	}
	/**/
}

int Simulator::GetNumberOfNode(void) {
	return nNode;
}

int Simulator::GetNumberOfNodeGPU(void) {
	return nNodeGPU;
}

void Simulator::Print(void) {
	std::cout << "Total number of Nodes: " << nNode << "\n";
	std::cout << "Number of GPU equipped Nodes: " << nNodeGPU << "\n";
	
	for (int i = 0; i < nNode; i++) {
		Nodes[i].Print();
	}
	std::cout << "\n";

	std::cout << mediumJobNodes.size() << "\n";
	std::cout << multiJobNodes.size() << "\n";
	/**/
}

void Simulator::StartJob(Job newJob, std::string type){
	int count = 0;
	int countGPU = 0;
	if (type == "short"){
		for (int i = 0; i < smallJobNodes.size(); i++) {
			if ((*(smallJobNodes[i])).IsAvailable()
			&& count < newJob.GetnCore()) {
				(*(smallJobNodes[i])).AssignJob(newJob, count, countGPU);
			}
		}
	}
	else if (type == "medium"){
		for (int i = 0; i < mediumJobNodes.size(); i++) {
			if ((*(mediumJobNodes[i])).IsAvailable()
			&& count < newJob.GetnCore()) {
				(*(mediumJobNodes[i])).AssignJob(newJob, count, countGPU);
			}
		}
	}
	else if (type == "multi"){
		for (int i = 0; i < multiJobNodes.size(); i++) {
			if ((*(multiJobNodes[i])).IsAvailable()
			&& count < newJob.GetnCore()) {
				(*(multiJobNodes[i])).AssignJob(newJob, count, countGPU);
			}
		}
	}
	else if (type == "GPU"){
		for (int i = 0; i < GPUJobNodes.size(); i++) {
			if ((*(GPUJobNodes[i])).IsAvailable()
			&& (count < newJob.GetnCore() 
			|| countGPU <newJob.GetnGPU())){
				(*(GPUJobNodes[i])).AssignJob(newJob, count, countGPU);
			}
		}
	}
	else throw std::invalid_argument("unknown job type");
}

void Simulator::Run(Scheduler& scheduler) {
	for (auto c = Nodes.begin(); c != Nodes.end(); ++c) {
		if (!(*c).IsAvailable()) {
			(*c).Run();
		}
	}

	int nAvailableShort = 0;
	int nAvailableMedium = 0;
	int nAvailableMulti = 0;
	int nAvailableGPU = 0;

	for (int i = 0; i < smallJobNodes.size(); i++) {
		if ((*(smallJobNodes[i])).IsAvailable()) {
			nAvailableShort++;
		}
	}

	std::optional<Job> nextShortJob = scheduler.AskJob(nAvailableShort, "short");
	if (nextShortJob){
		StartJob(*nextShortJob, "short");
	}

	for (int i = 0; i < mediumJobNodes.size(); i++) {
		if ((*(mediumJobNodes[i])).IsAvailable()) {
			nAvailableMedium++;
		}
	}
	std::optional<Job> nextMediumJob = scheduler.AskJob(nAvailableMedium, "medium");
	if (nextMediumJob){
		StartJob(*nextMediumJob, "medium");
	}

	for (int i = 0; i < multiJobNodes.size(); i++) {
		if ((*(multiJobNodes[i])).IsAvailable()) {
			nAvailableMulti++;
		}
	}
	std::optional<Job> nextMultiJob = scheduler.AskJob(nAvailableMulti, "multi");
	if (nextMultiJob){
		StartJob(*nextMultiJob, "multi");
	}
	for (int i = 0; i < GPUJobNodes.size(); i++) {
		if ((*(GPUJobNodes[i])).IsAvailable()) {
			nAvailableGPU++;
		}
		std::optional<Job> nextGPUJob = scheduler.AskJob(nAvailableGPU, "GPU");
		if (nextGPUJob){
			StartJob(*nextGPUJob, "GPU");
		}
		
	}
}