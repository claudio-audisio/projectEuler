#pragma once
#include <iostream>
#include <ostream>
#include <set>
#include <string>

#include "common/combinatorics.h"
#include "common/type.h"


void lexicographicPermutations(unsLL position) {
    std::set<int> result;
    string permutation = "";

    for (int i = 9; i > 0; i--) {
        unsLL permutations = factorial(i);

        for (int j = 0; j < 10; j++) {
            if (result.contains(j)) {
                continue;
            }

            if (position <= permutations) {
                result.insert(j);
                permutation += to_string(j);
                break;
            }

            position -= permutations;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (!result.contains(i)) {
            permutation += to_string(i);
        }
    }

    std::cout << "result: " << permutation << std::endl;
}
