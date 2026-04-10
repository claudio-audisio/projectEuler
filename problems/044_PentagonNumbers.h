#pragma once
#include <climits>
#include <iostream>
#include <ostream>
#include <set>

#include "common/type.h"

inline unsLL pentagon(const unsLL n) {
	return n * (3 * n - 1) / 2;
}

void pentagonNumbers() {
	unsLL min = LONG_MAX;
	std::set<unsLL> pentagons;

	for (int i = 1; i < 10000; i++) {
		pentagons.insert(pentagon(i));
	}

	for (int i = 1; i < pentagons.size(); i++) {
		for (int j = i + 1; j < pentagons.size(); j++) {
			auto sum = pentagon(i) + pentagon(j);
			const LL diff = pentagon(j) - pentagon(i);

			if (pentagons.contains(sum) && pentagons.contains(diff)) {
				const unsLL d = abs(diff);

				if (d < min) min = d;
			}
		}
	}

	std::cout << "result: " << min << std::endl;
}
