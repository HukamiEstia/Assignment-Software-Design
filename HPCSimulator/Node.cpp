#include "Node.h"

Node::Node(void) {}

Node::Node(int speed, bool hasGPU){
    for (int i = 0; i < 16; i++){
		Core newCore = Core(speed, false);
		cores.push_back(newCore);
	}
    
    if (hasGPU){
        for (int i = 0; i < 2; i++){
            Core newGPU = Core(speed, true);
            (*GPUs).push_back(newGPU);
        }
    }
}

bool Node::IsGPU(void){
    return hasGPU;
}

bool Node::IsAvailable(void){
    return isAvailable;
}

void Node::AssignJob(Job job, int& count, int& countGPU){
    isAvailable = false;
    int i = 0;
    while (count < job.GetnCore() && i < cores.size()){
        cores[i].AssignJob(job);
        nAvailableCores--;
        count++;
        i++;
    }
    if (GPUs){
        int j = 0;
        while (j < job.GetnGPU() && j < cores.size()){
            (*GPUs)[j].AssignJob(job);
            nAvailableCores--;
            countGPU++;
            j++;
        }
    }
}

void Node::Run(void){
    isAvailable = true;
    for (int i = 0; i < cores.size(); i++){
        if (!(cores[i].IsAvailable())) {
            isAvailable = false; 
            cores[i].Run();
        }
    }

    if (GPUs){
        for (int i = 0; i < (*GPUs).size(); i++){
            if (!((*GPUs)[i].IsAvailable())) {
                isAvailable = false; 
                (*GPUs)[i].Run();
            }
        }
    }

}

void Node::Print(void){
    for (auto c = cores.begin(); c != cores.end(); ++c){
        std::cout << isAvailable << " ";
    }
    std::cout << "\n";
}