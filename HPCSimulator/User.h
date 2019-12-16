#pragma once

#include "Request.h"
#include "Job.h"
#include "Scheduler.h"
#include <iostream>
#include <string>
#include <array>
#include <random>
#include <optional>


class User
{
protected:
	std::string body;
	int budget;
	int lastRequest;
	std::optional<Request> req;

public:
	User(void);
	std::string GetBody(void);
	Job GenerateJob(std::string type ="");
	bool HasRequest(void);
	void SendRequest(Scheduler* scheduler);
};

class ITSupport : public User
{
private:
	int budget;
	int lastRequest;
	std::string types[5]{"short", "medium", "large", "huge", "gpu"};

public:
	ITSupport(void);
	void GenerateRequest(int time);
	void GenerateRequest(int time, std::string type);
};

class Researcher : public User
{
private:
	int budget;
	int lastRequest;
	std::string types[5]{"short", "medium", "large", "huge", "gpu"};

public:
	Researcher(void);
	void GenerateRequest(int time);
};

class Student : public User
{
private:
	int budget;
	int lastRequest;
	std::string types[3]{"short", "medium", "gpu"};

public:
	Student(void);
	void GenerateRequest(int time);
};
