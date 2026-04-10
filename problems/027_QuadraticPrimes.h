#pragma once
#include <iostream>
#include <ostream>

#include "common/primes.h"
#include "common/type.h"

LL function(const LL a, const LL b, const LL n) {
	return n * n + a * n + b;
}

void quadraticPrimes() {
	int consecutive = 0;
	int best = 0;
	LL winA, winB;

	for (LL a = -1000; a < 1000; a++) {
		for (LL b = -1000; b < 1000; b++) {
			LL n = 0;

			while (isPrime(function(a, b, n), true)) {
				consecutive++;
				n++;
			}

			if (consecutive > best) {
				best = consecutive;
				winA = a;
				winB = b;
				//cout << winA << " " << winB << " - > " << consecutive << endl;
			}

			consecutive = 0;
		}
	}

	cout << "result: " << winA << " - " << winB << " -> " << winA * winB << endl;
}