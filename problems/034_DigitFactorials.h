#pragma once
#include <iostream>
#include <vector>

#include "common/combinatorics.h"
#include "common/type.h"
#include "common/utils.h"


void digitFactorials() {
	unsLL globalSum = 0;
	std::vector<int>* digits;

	for (int i = 3; i <= 1000000; i++) {
		digits = extractdigits(i);
		unsLL sum = 0;

		for (auto dig : *digits) {
			sum += factorial(dig);
		}

		if (sum == i) {
			globalSum += i;
		}

		delete digits;
	}

	std::cout << "result: " << globalSum << std::endl;
}
