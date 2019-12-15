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
	const static std::string body;
	int budget;
	int lastRequest;
	std::optional<Request> req;
	const static std::string types[];

public:
	User(void);
	Job GenerateJob(std::string type ="");
	void GenerateRequest(int time);
	void SendRequest(Scheduler& scheduler);
};

class ITSupport : public User
{
private:
	int budget;
	int lastRequest;

public:
	ITSupport(void);
	void GenerateRequest(int time);
};

class Researcher : public User
{
private:
	int budget;
	int lastRequest;

public:
	Researcher(void);
	void GenerateRequest(int time);
};

class Student : public User
{
private:
	int budget;
	int lastRequest;

public:
	Student(void);
	void GenerateRequest(int time);
};
