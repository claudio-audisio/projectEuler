#pragma once

#include <set>
#include <math.h>

#include "type.h"

using namespace std;

set<LL> primes;

bool isPrime(LL n, bool usePreviousPrimes = false) {
	if (primes.find(n) != primes.end()) {
		return true;
	}

	if (n == 2 || n == 3) {
		primes.insert(n);
		return true;
	}

	if ((n % 6) != 1 && (n % 6) != 5) {
		return false;
	}

	LL limit = sqrt(double(n));

	if (usePreviousPrimes) {
		set<LL>::const_iterator itP = primes.begin();

		while (itP != primes.end()) {
			if (n % (*itP) == 0) {
				return false;
			}

			if ((*itP) > limit) {
				primes.insert(n);
				return true;
			}

			itP++;
		}
	}

	if (!usePreviousPrimes) {
		if (n % 2 == 0) {
			return false;
		}

		for (int i = 3, k = 0; i < n / 2; i += 2, k++) {
			if (n % i == 0) {
				return false;
			}
		}
	}

	primes.insert(n);
	return true;
}

set<LL> getPrimes(int limit) {
	set<LL> primes;
	for (int i = 2; i <= limit; i++) {
		//cout << "\revaluating " << i;

		if (isPrime(i)) {
			primes.insert(i);
		}
	}
	return primes;
}

void printPrimes(int limit) {
	for (int i = 2; i < limit; i++) {
		if (isPrime(i)) {
			cout << i << " ";
		}
	}
	cout << endl;
}

void countPrimes(const int limit) {
	unsLL count  = 0;
	for (int i = 2; i < limit; i++) {
		if (isPrime(i)) {
			count++;
		}
	}
	cout << count << endl;
}

std::vector<int> sievePrimes(const int n) {
	std::vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= n; i++)
		if (is_prime[i])
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;

	std::vector<int> primes;
	for (int i = 2; i <= n; i++)
		if (is_prime[i])
			primes.push_back(i);

	cout << primes.size() << endl;

	return primes;
}