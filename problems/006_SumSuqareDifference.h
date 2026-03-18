#pragma once

using namespace std;

void sumSquareDifference(int limit) {
	LL sum = 0;
	LL squares = 0;

	for (int i = 1; i <= limit; i++) {
		squares += i * i;
		sum += i;
		cout << i << "\t" << squares << "\t" << sum * sum << "\t" << sum * sum - squares << endl;
	}
}