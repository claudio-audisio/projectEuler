#pragma once

#include "common/primes.h"
#include "common/type.h"

using namespace std;

void largestPrimeFactor(LL number) {
	LL largestFactor = 1;
	LL currentProd = 1;
	
	while (currentProd < number) {
		largestFactor++;
		if ((number % largestFactor == 0) && isPrime(largestFactor)) {
			currentProd *= largestFactor;
		}
	}

	cout << "result: " << largestFactor << endl;
}

void nThPrimes(LL limitIndex) {
	LL index = 3;

	isPrime(2);

	while (primes.size() < limitIndex) {
		isPrime(index);
		index += 2;
	}

	cout << "result: " << *primes.rbegin() << endl;
}
