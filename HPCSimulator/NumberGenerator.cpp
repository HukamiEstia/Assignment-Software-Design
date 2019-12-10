#include "NumberGenerator.h"
#include <iostream>

int NumberGenerator::operator ()() {
	while (true) {
		float number = distribution(generator);
		if (number >= min && number <= max) {
			return (int)number;
		}
	}
} 