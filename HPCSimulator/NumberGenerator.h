#pragma once

#include <random>

class NumberGenerator
{
private:
	std::default_random_engine generator;
	std::normal_distribution<double> distribution;
	double min;
	double max;
public:
	NumberGenerator(double mean, double stddev, double min, double max) :
		generator(std::random_device{}()), distribution(mean, stddev), min(min), max(max)
	{}
	int operator ()();
};

