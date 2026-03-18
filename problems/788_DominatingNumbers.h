#pragma once
#include <string>
#include <algorithm>

using namespace std;

bool isDominating(LL number) {
	string stringNumber = to_string(number);
	int len = stringNumber.length();

	if (len == 1) {
		return true;
	}

	char digit = '0';

	for (int i = 0; i < 10; i++, digit++) {
		auto count = std::count(stringNumber.begin(), stringNumber.end(), digit);
		if (count > len / 2) {
			return true;
		}
	}

	return false;
}

void dominatingNumbers() {
	cout << "\n*** 788 - Dominating Numbers ***";
	cout << "\nEnter the exponent: ";

	int exponent;
	cin >> exponent;

	LL limitUp = (LL)pow(10, exponent);
	LL counter = 0;
	

	for (LL i = 1; i < limitUp; i++) {
		if (isDominating(i)) counter++;
	}

	cout << "Dominating numbers < 10^" << exponent << " are: " << counter << endl;
}
