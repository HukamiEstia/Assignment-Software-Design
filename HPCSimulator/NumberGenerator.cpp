#include "NumberGenerator.h"
#include <iostream>

int NormalDistGenerator::operator ()() {
	while (true) {
		float number = distribution(generator);
		if (number >= min && number <= max) {
			return (int)number;
		}
	}
}

int ExpDistGenerator::operator ()() {
	float number = distribution(generator);
	return (int)number;
} 