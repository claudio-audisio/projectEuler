#pragma once

#include <set>
#include <vector>
#include <map>

#include "common/primes.h"

using namespace std;

map<unsLL, int> factors(unsLL n) {
	map<unsLL, int> factors;

	for (unsLL d = 2; d * d <= n; d++) {
		while (n % d == 0) {
			factors[d]++;
			n /= d;
		}
	}

	if (n > 1) factors[n]++;

	return factors;
}

vector<unsLL> divisors(unsLL n) {
	map<unsLL, int> fs = factors(n);
	vector<unsLL> divisors = {1};

	for (auto& [prime, exp] : fs) {
		int sz = divisors.size();
		unsLL pe = 1;

		for (int e = 1; e <= exp; e++) {
			pe *= prime;
			for (int j = 0; j < sz; j++) {
				divisors.push_back(divisors[j] * pe);
			}
		}
	}

	sort(divisors.begin(), divisors.end());
	return divisors;
}

vector<unsLL> properDivisors(unsLL n) {
	auto pd = divisors(n);

	if (pd.size() > 0) {
		pd.erase(pd.end() - 1);
	}

	return pd;
}

void printFactors(map<unsLL, int> factors) {
	map<unsLL, int>::const_iterator itF = factors.begin();

	while (itF != factors.end()) {
		cout << itF->first << "^" << itF->second << endl;
		itF++;
	}
}

void printDivisors(vector<unsLL> divisors) {
	for (unsLL d : divisors) cout << d << " ";
	cout << endl;
}
