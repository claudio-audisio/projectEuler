#pragma once
#include <iostream>
#include <vector>

#include "common/primes.h"


void consecutivePrimeSum(const int limit) {
	auto _primes = sievePrimes(limit);
	set<int> primes;

	for (auto prime : _primes) {
		primes.insert(prime);
	}

	unsLL sum = 0;
	int max = 0;
	int result = 0;

	for (int i = 0; i < primes.size(); i++) {
		for (int j = i; j < primes.size(); j++) {
			sum += _primes[j];

			if (sum >= limit) {
				break;
			}

			if (primes.contains(sum) && j - i + 1 > max) {
				max = j - i + 1;
				result = sum;
			}
		}

		sum = 0;
	}

	cout << result << " - " << max << endl;
}
