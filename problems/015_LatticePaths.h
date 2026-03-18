#pragma once
#include <iostream>

#include "common/combinatorics.h"


void latticePaths() {
    for (int i = 2; i < 10; i++) {
        std::cout << "result: " << permutationsWithReptitions(i*2, 2, 2) << std::endl;
    }

}
