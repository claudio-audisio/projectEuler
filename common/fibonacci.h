#pragma once
#include <unordered_map>
#include "type.h"

using namespace std;

unordered_map<unsLL, unsLL> values;

unsLL fibonacci(const unsLL n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (values.contains(n)) return values[n];
	values[n - 2] = fibonacci(n - 2);
	values[n - 1] = fibonacci(n - 1);
	return values[n - 2] + values[n - 1];
}
