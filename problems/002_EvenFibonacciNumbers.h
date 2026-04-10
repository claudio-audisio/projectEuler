#pragma once

#include <map>

#include "common/fibonacci.h"
#include "common/type.h"

using namespace std;

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
