#pragma once

#include "Request.h"
#include "Job.h"
#include <string>
#include <queue>
#include <optional>
#include <vector>

class Scheduler
{
private:
	Request noRequest;
	std::queue<Request> queueShort;
	std::queue<Request> queueMedium;
	std::queue<Request> queueLarge;
	std::queue<Request> queueHuge;
	std::queue<Request> queueGPU;

public:
	void AddRequest(Request req);
	std::optional<Job> AskJob(int nAvailableCores, std::string type="");
	Job GetJob(std::string type="");
	Request& NextRequest(std::string type);
	void pop(std::string type = "");
	Scheduler();
};

