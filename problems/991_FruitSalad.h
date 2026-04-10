#pragma once
#include <iostream>

#include "common/type.h"


inline bool isGood(const double a, const double b, const double c) {
	return ((a / (b + c)) + ((b + c) / (a + c))) == 4.0;
}

void fruitSalad(const unsLL limit) {
	unsLL sum = 0;
	int count = 0;
	bool nextA = false;

	for (unsLL a = 1; a < limit; a++) {
		nextA = false;

		for (unsLL b = 1; b < limit && !nextA; b++) {
			if (a + b > limit) {
				break;
			}

			for (unsLL c = 1; c < limit; c++) {
				if (3 * c > b) {
					break;
				}

				if (a >= 4 * (b + c)) {
					break;
				}

				if (b >= 4 * a + 3 * c) {
					break;
				}

				if (a + b + c > limit) {
					break;
				}

				if (isGood(a, b, c)) {
					count++;
					sum += a + b + c;
					cout << count << " - " << a << " " << b << " " << c << " - " << sum << endl;
					nextA = b > a;
					break;
				}
			}
		}
	}

	std::cout << "result: " << sum << std::endl;
}
