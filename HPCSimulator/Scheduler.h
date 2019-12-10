#pragma once

#include "Request.h"
#include "Job.h"
#include <string>
#include <queue>

class Scheduler
{
private:
	std::queue<Request> queueShort;
	std::queue<Request> queueMedium;
	std::queue<Request> queueLarge;
	std::queue<Request> queueHuge;
	std::queue<Request> queueGPU;

public:
	void AddRequest(Request req);
	Job GetJob(std::string type="");
	Request& NextRequest(std::string type);
	void pop(std::string type = "");
	Scheduler();
};

