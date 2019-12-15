#include "Scheduler.h"

Scheduler::Scheduler() {
	noRequest = Request("noRequest");
}


Request& Scheduler::NextRequest(std::string type)
{
	if (type == "short") {
		if (!(queueShort.empty())){
			return queueShort.front();
		} 
		else {
			return noRequest;
		}
	}
	else if (type == "medium") {
		if (!(queueShort.empty())){
			return queueMedium.front();
		} 
		else {
			return noRequest;
		}
	}
	else if (type == "large") {
		if (!(queueLarge.empty())){
			return queueLarge.front();
		}
		else {
			return noRequest;
		}
	}
	else if (type == "Huge") {
		if (!(queueHuge.empty())){
			return queueHuge.front();
		}
		else {
			return noRequest;
		}
	}
	else if (type == "GPU") {
		if (!(queueGPU.empty())){
			return queueHuge.front();
		}
		else {
			return noRequest;
		}
	}
	else if (type == "multi" || type == ""){
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
				if (candidates[i].Time > candidates[*nR].Time) {
					nR = i;
				}
			}
		}
		if (nR){
			return candidates[*nR];
		}
		else {
			return noRequest;
		}
	}
	else {
		throw std::invalid_argument("unknown job type");
		return noRequest;
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
	else if (type == "GPU") {
		if (!(queueGPU.empty())) {
			queueGPU.pop();
		}
	}
	else if (type == "") {
		Request& nextRequest = NextRequest(type);
		if (nextRequest.type == "short" && !(queueShort.empty())) {
			queueShort.pop();
		}
		else if (nextRequest.type == "medium" && !(queueMedium.empty())) {
			queueMedium.pop();
		}
		else if (nextRequest.type == "Large" && !(queueLarge.empty())) {
			queueLarge.pop();
		}
	}
	else if (type == "noRequest")
	{;}
	else {
		throw std::invalid_argument("unknown job type");
	}
}


void Scheduler::AddRequest(Request req) {
	if (req.type == "short") {
		queueShort.push(req);
	}
	if (req.type == "medium") {
		queueMedium.push(req);
	}
	if (req.type == "large") {
		queueLarge.push(req);
	}
	if (req.type == "Huge") {
		queueHuge.push(req);
	}
	if (req.type == "GPU") {
		queueGPU.push(req);
	}
}

Job Scheduler::GetJob(std::string type) {
	Job nextJob;
	nextJob = NextRequest(type).job;
	pop(NextRequest(type).type);
	return nextJob;
}

std::optional<Job> Scheduler::AskJob(int nAvailableCores, std::string type){
	if ( type == "GPU"){
		if (nAvailableCores >= ((NextRequest(type)).nGPU)) {
			return GetJob(type);
		}
	}
	else if (type == "short" ||
			 type == "medium"||
			 type == "multi"){
		if (nAvailableCores >= ((NextRequest(type)).nCore)) {
			return GetJob(type);
		}
	}
	else {
		return{};
	}
}