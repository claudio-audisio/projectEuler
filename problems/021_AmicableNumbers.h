#pragma once
#include <iostream>
#include <ostream>

#include "common/factors.h"
#include "common/type.h"


void amicableNumbers(unsLL limit) {
    set<unsLL> amicables;

    for (int i = 1; i <= limit; i++) {
        if (amicables.contains(i)) {
            continue;
        }

        auto ds = properDivisors(i);
        unsLL sum = 0;

        for (auto d : ds) {
            sum += d;
        }

        if (sum != i) {
            auto ds2 = properDivisors(sum);
            unsLL sum2 = 0;

            for (auto d : ds2) {
                sum2 += d;
            }

            if (sum2 == i) {
                amicables.insert(i);
                amicables.insert(sum);
            }
        }
    }

    unsLL sum = 0;

    for (auto a : amicables) {
        sum += a;
    }

    cout << "result: " << sum << endl;
}
