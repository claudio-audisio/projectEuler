#pragma once

#include <cmath>
#include "../common/factors.h"
#include "common/combinatorics.h"
#include "common/utils.h"

using namespace std;

void test() {
	unsLL fact = 1;
	unsLL prevSum = 1;

	for (int i = 1; i < 20; i++) {
		fact *= i;
		auto sum = digitSum(fact);

		cout << i << " - " << fact << " - " << sum << " - " << prevSum * i << endl;

		prevSum = sum;
	}
}