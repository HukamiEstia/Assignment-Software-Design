#pragma once

#include <random>

class NumberGenerator
{
private:
	std::default_random_engine generator;

public:
	NumberGenerator(void) :
		generator(std::random_device{}()){}
};

class NormalDistGenerator: public NumberGenerator
{
private:
	std::default_random_engine generator;
	std::normal_distribution<double> distribution;
	double min;
	double max;
public:
	NormalDistGenerator(double mean, double stddev, double min, double max) :
		generator(std::random_device{}()), distribution(mean, stddev), min(min), max(max)
	{}
	int operator ()();
};

class ExpDistGenerator: public NumberGenerator
{
private:
	std::default_random_engine generator;
	std::exponential_distribution<double> distribution;

public:
	ExpDistGenerator(double lambda) :
		generator(std::random_device{}()), distribution(lambda)
	{}
	int operator ()();
};
