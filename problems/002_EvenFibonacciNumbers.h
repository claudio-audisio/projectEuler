#pragma once

#include <map>

#include "common/type.h"

using namespace std;

inline map<int, LL> fibonacciValues;

LL fibonacci(int i) {
	if (i == 1)
		return 1;

	if (i == 2)
		return 2;

	LL prev, prevPrev;

	map<int, LL>::const_iterator itPrev = fibonacciValues.find(i - 1);

	if (itPrev != fibonacciValues.end()) {
		prev = (*itPrev).second;
	}
	else {
		prev = fibonacci(i - 1);
	}

	map<int, LL>::const_iterator itPrevPrev = fibonacciValues.find(i - 2);

	if (itPrevPrev != fibonacciValues.end()) {
		prevPrev = (*itPrevPrev).second;
	}
	else {
		prevPrev = fibonacci(i - 2);
	}

	fibonacciValues.insert(make_pair(i, prev + prevPrev));

	return prev + prevPrev;
}

void evenFibonacciNumbers(LL limit) {
	LL sum = 0;
	LL fib = 0;
	int i = 1;

	while (fib < limit) {
		fib = fibonacci(i++);

		if (fib % 2 == 0) {
			sum += fib;
		}
	}

	cout << "result: " << sum << endl;
}
