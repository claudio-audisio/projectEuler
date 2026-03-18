#pragma once
#include <string>

using namespace std;

bool isPalindromic(LL number) {
	string stringNumber = to_string(number);
	int len = stringNumber.length();

	if (len == 1) {
		return true;
	}

	for (int i = 0; i < len / 2; i++) {
		if (stringNumber.at(i) != stringNumber.at(len - i - 1)) {
			return false;
		}
	}

	return true;
}

void largestPalindromeProduct() {
	cout << "\n*** 11 - Largest Palindrome Product ***";
	cout << "\nEnter the number of digits: ";

	int digits;
	cin >> digits;

	LL limitDown = (LL)pow(10, digits - 1) - 1;
	LL limitUp = (LL)pow(10, digits) - 1;
	LL max = 0;
	LL factorA, factorB;
	
	for (LL i = limitUp; i > limitDown ; i--) {
		for (LL j = i; j > limitDown; j--) {
			if (i * j < max) {
				break;
			}

			if (isPalindromic(i * j)) {
				if (i * j > max) {
					max = i * j;
					factorA = i;
					factorB = j;
				}
			}
		}
	}

	cout << "Largest palindromic number of " << digits << " digits is: " << max << " (" << factorA << " x " << factorB << ")" << endl;
}