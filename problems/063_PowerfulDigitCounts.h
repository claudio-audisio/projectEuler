#pragma once
#include <cmath>
#include <iostream>
#include <unordered_set>

#include "common/utils.h"


void powerfulDigitCounts() {
	std::unordered_set<double> numbers;

	for (int n = 0; n < 10; n++) {
		for (int e = 1; e < 30; e++) {
			double number = std::pow(n, e);
			auto len = lengthD(number);

			if (len > e) {
				break;
			}

			if (len == e && number > 0) {
				numbers.insert(number);
			}
		}
	}

	cout << "result: " << numbers.size() << endl;
}
