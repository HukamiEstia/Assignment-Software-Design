#include "Scheduler.h"

Scheduler::Scheduler() {
}


std::optional<Request> Scheduler::GetNextShort(){
	if (!(queueShort.empty())){
		return queueShort.front();
	} 
	else {
		return {};
	}
}

std::optional<Request> Scheduler::GetNextMedium(){
	if (!(queueMedium.empty())){
		return queueMedium.front();
	} 
	else {
		return {};
	}
}

std::optional<Request> Scheduler::GetNextLarge(){
	if (!(queueLarge.empty())){
		return queueLarge.front();
	} 
	else {
		return {};
	}
}

std::optional<Request> Scheduler::GetNextHuge(){
	if (!(queueHuge.empty())){
		return queueHuge.front();
	} 
	else {
		return {};
	}
}

std::optional<Request> Scheduler::GetNextGPU(){
	if (!(queueGPU.empty())){
		return queueGPU.front();
	} 
	else {
		return {};
	}
}

std::optional<Request> Scheduler::GetNextMulti() {
	std::vector<Request> candidates;
	if (!(queueShort.empty())){
		candidates.push_back(queueShort.front());
	}
	if (!(queueMedium.empty())){
		candidates.push_back(queueMedium.front());
	}
	if (!(queueLarge.empty())){
		candidates.push_back(queueLarge.front());
	}
		
	std::optional<int> nR;
	if (!(candidates.empty())){
		nR = 0;
		for (int i = 0; i < candidates.size(); i++){
			if (candidates[i].GetTime() > candidates[*nR].GetTime()) {
				nR = i;
			}
		}
	}
	if (nR){
		return candidates[*nR];
	}
	else {
		return {};
	}
}

std::optional<Request> Scheduler::NextRequest(std::string type)
{
	if (type == "short") {
		return GetNextShort();
	}
	else if (type == "medium") {
		return GetNextMedium();
	}
	else if (type == "large") {
		return GetNextLarge();
	}
	else if (type == "Huge") {
		return GetNextHuge();
	}
	else if (type == "gpu") {
		return GetNextGPU();
	}
	else if (type == "multi" || type == ""){
		return GetNextMulti();
	}
	else {
		return {};
	}
}

void Scheduler::pop(std::string type) {
	if (type == "short") {
		if ( !(queueShort.empty())) {
			queueShort.pop();
		}
	}
	else if (type == "medium") {
		if (!(queueMedium.empty())) {
			queueMedium.pop();
		}
	}
	else if (type == "large") {
		if (!(queueLarge.empty())) {
			queueLarge.pop();
		}
	}
	else if (type == "huge") {
		if (!(queueHuge.empty())) {
			queueHuge.pop();
		}
	}
	else if (type == "gpu") {
		if (!(queueGPU.empty())) {
			queueGPU.pop();
		}
	}
	else if (type == "") {
		std::optional<Request> nextRequest = NextRequest(type);
		if (nextRequest){
			if ((*nextRequest).GetType() == "short" && !(queueShort.empty())) {
				queueShort.pop();
			}
			else if ((*nextRequest).GetType() == "medium" && !(queueMedium.empty())) {
				queueMedium.pop();
			}
			else if ((*nextRequest).GetType() == "Large" && !(queueLarge.empty())) {
				queueLarge.pop();
			}
		}
	}
	else if (type == "{}")
	{;}
	else {
		throw std::invalid_argument("unknown job type");
	}
}


void Scheduler::AddRequest(Request req) {
	std::cout << "adding request to scheduler: " << req.GetType() << "\n";
	
	if (req.GetType() == "short") {
		//std::cout << "scheduler adding short request";
		queueShort.push(req);
	}
	else if (req.GetType() == "medium") {
		queueMedium.push(req);
	}
	else if (req.GetType() == "large") {
		queueLarge.push(req);
	}
	else if (req.GetType() == "huge") {
		queueHuge.push(req);
	}
	else if (req.GetType() == "gpu") {
		queueGPU.push(req);
	}
	else {
		//std::cout << req.GetType() << "\n";
		throw std::invalid_argument("unknown job type");
	}
}

Job Scheduler::GetJob(std::string type) {
	Job nextJob;
	nextJob = (*NextRequest(type)).GetJob();
	pop((*NextRequest(type)).GetType());
	return nextJob;
}

std::optional<Job> Scheduler::AskJob(int nAvailableNodes, std::string type){
	if (NextRequest(type)){
		if ( type == "gpu"){
		
			if ((*NextRequest(type)).GetType() == type 
			&& nAvailableNodes*2 >= ((*NextRequest(type)).GetnNodeGPU())) {
				return GetJob(type);
			}
		}
		else if (type == "short"
		|| type == "medium"
		|| type == "multi"){
		
			if ((*NextRequest(type)).GetType() == type
			&& nAvailableNodes*16 >= ((*NextRequest(type)).GetnNode())) {
				std::cout << "nCore: " << (*NextRequest(type)).GetJob().GetnCore() << "\n";
	
				return GetJob(type);
			}
		}
		
	}	
	else {
		return {};
	}
}