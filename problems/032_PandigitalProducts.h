#pragma once
#include <iostream>
#include <set>
#include <vector>

#include "common/type.h"
#include "common/utils.h"

bool arePandigital(const vector<int>* a, const vector<int>* b, const vector<int>* c) {
	set<int> digits;
	for (auto d : *a) {
		digits.insert(d);
	}
	for (auto d : *b) {
		digits.insert(d);
	}
	for (auto d : *c) {
		digits.insert(d);
	}
	return digits.size() == 9 && !digits.contains(0);
}

void pandigitalProducts() {
	std::set<unsLL> panD;

	for (int a = 1; a < 10000; a++) {
		for (int b = 1; true; b++) {
			int prod = a * b;

			auto la = length(a);
			auto lb = length(b);
			auto lp = length(prod);

			if (la + lb + lp < 9) {
				continue;
			}

			if (la + lb + lp > 9) {
				break;
			}

			auto da = extractdigits(a);
			auto db = extractdigits(b);
			auto dp = extractdigits(prod);

			if (arePandigital(da, db, dp)) {
				//cout << a << " " << b << " " << prod << endl;
				panD.insert(prod);
			}
		}
	}

	unsLL sum = 0;
	for (auto pan : panD) {
		sum += pan;
	}

	cout << "result: " << sum << endl;
}