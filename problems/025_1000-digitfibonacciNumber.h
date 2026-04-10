#pragma once
#include <iostream>
#include <ostream>

using namespace std;

void nDigitFibonacciNumber(int n) {
	double prev = 1;
	double next = 1;
	int digit = 2;
	int index = 2;

	while (n > digit) {
		double fib = prev + next;
		prev = next;
		next = fib;
		index++;

		if (prev / 100.0 > 1.0 && next / 100.0 > 1.0) {
			digit++;
			prev /= 10.0;
			next /= 10.0;
		}
	}

	cout << "result: " << index - 1 << endl;
}
