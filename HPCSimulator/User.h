#pragma once

#include "Request.h"
#include "Job.h"
#include "Scheduler.h"
#include <ctime>
#include <iostream>
#include <string>
#include <array>
#include <random>


class User
{
private:
	int budget;
	std::string types[5] = {"short", "medium", "large", "huge", "gpu"};
	std::time_t lastRequest;

public:
	void SendRequest(Request req, Scheduler& scheduler);
	Request GenerateRequest(void);
	Job GenerateJob(std::string type ="");
	User(void);
	User(std::string body);
};

