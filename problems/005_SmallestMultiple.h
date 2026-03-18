#pragma once

#include <map>

#include "common/factors.h"

using namespace std;

void smallestMultiple(int limit) {
	set<LL> primes = getPrimes(limit);
	set<LL>::const_iterator itP = primes.begin();
	LL multiple = 1;
	bool checkPower = true;

	while (itP != primes.end()) {
		const LL prime = *itP;

		if (checkPower && prime < sqrt(double(limit))) {
			multiple *= pow(prime, floor(log(double(limit)) / log(double(prime))));
		}
		else {
			checkPower = false;
			multiple *= prime;
		}
		itP++;
	}
	
	cout << "result: " << multiple << endl;
}

void mySmallestMultiple(int limit) {
	unsLL multiple = 1;
	map<unsLL, int> fs;
	
	for (int i = 2; i <= limit; i++) {
		map<unsLL, int> currentFactors = factors(i);
		map<unsLL, int>::const_iterator itF = currentFactors.begin();

		while (itF != currentFactors.end()) {
			const int currentF = itF->first;
			const int fFreq = itF->second;

			if (fs.find(currentF) == fs.end()) {
				fs.insert(make_pair(currentF, fFreq));
			}
			else if (fFreq > fs[currentF]) {
				fs[currentF] = fFreq;
			}
			itF++;
		}
	}

	printFactors(fs);
		
	map<unsLL, int>::const_iterator itF = fs.begin();

	while (itF != fs.end()) {
		multiple *= pow(double(itF->first), double(itF->second));
		itF++;
	}

	cout << "result: " << multiple << endl;
}