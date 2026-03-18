#pragma once


#include <iostream>

#include "common/factors.h"

void highlyDivisibleTriangularNumber() {
    unsLL triangular = 0;

    for (unsLL i = 1; i <= 100000; i++) {
        triangular += i;
        vector<unsLL> divs = divisors(triangular);

        if (divs.size() > 500) {
            cout << "result: " << triangular << endl;
            break;
        }
    }
}