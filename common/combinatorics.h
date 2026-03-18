#pragma once
#include "constants.h"
#include "type.h"


unsLL factorial(unsLL n) {
    if (n < 21) {
        return factorialTable[n];
    }

    return n * factorial(n - 1);
}

unsLL permutationsWithReptitions(unsLL a, unsLL b, unsLL c) {
    return factorial(a) / (factorial(b) * factorial(c));
}
