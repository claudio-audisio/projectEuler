#pragma once

using namespace std;

void multipleOf3And5() {
	int sum = 0;
	for (int i = 1; i < 1000; i++) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			sum += i;
		}
	}

	cout << "result: " << sum << endl;
}