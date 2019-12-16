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
	std::queue<Request> queueShort;
	std::queue<Request> queueMedium;
	std::queue<Request> queueLarge;
	std::queue<Request> queueHuge;
	std::queue<Request> queueGPU;

public:
	void AddRequest(Request req);
	std::optional<Job> AskJob(int nAvailableCores, std::string type="");
	Job GetJob(std::string type="");
	std::optional<Request> NextRequest(std::string type);
	std::optional<Request> GetNextShort(void);
	std::optional<Request> GetNextMedium(void);
	std::optional<Request> GetNextLarge(void);
	std::optional<Request> GetNextHuge(void);
	std::optional<Request> GetNextGPU(void);
	std::optional<Request> GetNextMulti(void);
	void pop(std::string type = "");
	Scheduler();
};

