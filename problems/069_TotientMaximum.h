#pragma once

#include <set>

#include "common/primes.h"

using namespace std;

int countPrimes(set<LL> primes, LL min, LL max) {
	set<LL>::const_iterator itP = primes.begin();
	int counter = 0;

	while (itP != primes.end()) {
		if (*itP >= max) {
			break;
		}

		if (*itP > min) {
			counter++;
		}

		itP++;
	}

	return counter;
}

void totientMaximum(int limit) {
	set<LL> primes = getPrimes(limit);
	LL currentProd = 1;
	set<LL>::const_iterator itP = primes.begin();

	while (itP != primes.end()) {
		if (currentProd * (*itP) > limit) {
			break;
		}
		const LL prime = *itP;
		currentProd *= prime;
		int totient = countPrimes(primes, prime, currentProd) + 1;
		cout << currentProd << ": " << totient << endl;
		itP++;
	}

	cout << "result: " << currentProd << endl;
}
