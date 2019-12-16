#include "Node.h"

Node::Node(void) {}

Node::Node(int speed, bool GPU){
    hasGPU = GPU;
    isAvailable = true;
    nAvailableCores = 16;
    nAvailableGPU = 0;
    for (int i = 0; i < 16; i++){
		Core newCore = Core(speed, false);
		cores.push_back(newCore);
	}
    
    if (GPU){
        std::vector<Core> createGPUs;
        Node::nAvailableGPU = 2;
        for (int i = 0; i < 2; i++){
            Core newGPU = Core(speed, true);
            createGPUs.push_back(newGPU);
        }
        GPUs = createGPUs;
    }
}

int Node::GetRemainingTime(){
    return cores[0].GetRemainingTime();
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
        while (j < job.GetnGPU() && j < (*GPUs).size()){
            (*GPUs)[j].AssignJob(job);
            nAvailableCores--;
            countGPU++;
            j++;
        }
    }
}

void Node::Run(void){
    nAvailableCores = 0;
	nAvailableGPU = 0;
    for (int i = 0; i < cores.size(); i++){
        if (!(cores[i].IsAvailable())) {
            cores[i].Run();
        }
        else {
            nAvailableCores++;
        }
    }

    if (GPUs){
        for (int i = 0; i < (*GPUs).size(); i++){
            if (!((*GPUs)[i].IsAvailable())) {
                (*GPUs)[i].Run();
            }
            else {
                nAvailableGPU++;
            }
        }
    }
    if (nAvailableCores == cores.size()){
        if (hasGPU){
            if (nAvailableGPU == (*GPUs).size()){
                isAvailable = true;
            }
            else {
                isAvailable = false;
            }
        } 
        else {
            isAvailable = true;
        }
    } else {
        isAvailable = false;
    }
}

void Node::Print(void){
    for (auto c = cores.begin(); c != cores.end(); ++c){
        std::cout << isAvailable << " ";
    }
    std::cout << "\n";
}