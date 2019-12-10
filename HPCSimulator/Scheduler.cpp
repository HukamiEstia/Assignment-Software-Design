#include "Scheduler.h"

Scheduler::Scheduler() {

}


Request& Scheduler::NextRequest(std::string type)
{
	if (type == "short") {
		return queueShort.front();
	}
	else if (type == "medium") {
		return queueMedium.front();
	}
	else if (type == "large") {
		return queueLarge.front();
	}
	else if (type == "Huge") {
		return queueHuge.front();
	}
	else if (type == "GPU") {
		return queueHuge.front();
	}
	else if (type == "") {
		Request& nextShort = queueShort.front();
		Request& nextMedium = queueMedium.front();
		Request& nextLarge = queueLarge.front();

		if (nextShort.Time < nextMedium.Time && nextShort.Time < nextLarge.Time) {
			return nextShort;
		}
		if (nextMedium.Time < nextShort.Time && nextMedium.Time < nextLarge.Time) {
			return nextMedium;
		}
		if (nextLarge.Time < nextShort.Time && nextLarge.Time < nextMedium.Time) {
			return nextShort;
		}

	}
	else {
		throw std::invalid_argument("unknown job type");
	}
}

void Scheduler::pop(std::string type) {
	if (type == "short") {
		queueShort.pop();
	}
	else if (type == "medium") {
		queueMedium.pop();
	}
	else if (type == "large") {
		queueLarge.pop();
	}
	else if (type == "huge") {
		queueHuge.pop();
	}
	else if (type == "GPU") {
		queueGPU.pop();
	}
	else if (type == "") {
		Request& nextRequest = NextRequest(type);
		if (nextRequest.type == "short") {
			queueShort.pop();
		}
		else if (nextRequest.type == "medium") {
			queueMedium.pop();
		}
		else if (nextRequest.type == "Large") {
			queueLarge.pop();
		}
	}
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
	pop(type);
	return nextJob;
}
