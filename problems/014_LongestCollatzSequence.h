#pragma once

#include <map>

using namespace std;

map<LL, LL> sequences;

LL collatzSequenceSizeRecursive(LL n) {
	LL size;
	
	if (n == 1) {
		sequences.insert(make_pair(1, 1));
		return 1;
	}

	map<LL, LL>::const_iterator itS = sequences.find(n);

	if (itS != sequences.end()) {
		return (*itS).second;
	}

	if (n % 2 == 0) {
		size = collatzSequenceSizeRecursive(n / 2) + 1;
	}
	else {
		size = collatzSequenceSizeRecursive((n * 3) + 1) + 1;
	}
	
	sequences.insert(make_pair(n, size));

	return size;
}

void longestCollatzSequence(int limit) {
	int current;
	LL size, maxSize = 0;

	for (int i = 1; i < limit; i++) {
		size = collatzSequenceSizeRecursive(i);
				
		if (size > maxSize) {
			maxSize = size;
			current = i;
		}
	}

	cout << "\rresult: " << current << " --> " << maxSize << endl;
}