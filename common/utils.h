#pragma once

#include "type.h"

using namespace std;

static string toString(const double value) {
    return format("{:.4g}", value);
}

inline unsLL getElapsedNanos(const chrono::time_point<chrono::steady_clock> start) {
    return chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - start).count();
}

inline unsLL getElapsedMicros(const chrono::time_point<chrono::steady_clock> start) {
    return chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count();
}

inline unsLL getElapsedMillis(const chrono::time_point<chrono::steady_clock> start) {
    return chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count();
}

inline unsLL getElapsedSeconds(const chrono::time_point<chrono::steady_clock> start) {
    return chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - start).count();
}

LL extractNumber(string number, int start, int length) {
    if (number.length() < start + length) {
        throw runtime_error("extractNumber");
    }

    return stoll(number.substr(start, length));
}

unsLL digitSum(unsLL number) {
    unsLL sum = 0;

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

