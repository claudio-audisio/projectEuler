#pragma once
#include <iostream>
#include <ostream>
#include <vector>
#include "common/type.h"
using namespace std;


const pair<vector<int>, vector<int>> months = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

bool isLeap(const int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

void countingSundays() {
    unsLL day = 1;
    int sundays = 0;

    for (int y = 1900; y < 2001; y++) {
        bool leap = isLeap(y);

        for (int m = 0; m < 12; m++) {
            if (leap) {
                day += months.second[m];
            } else {
                day += months.first[m];
            }

            if (y > 1900 && day % 7 == 0) sundays++;
        }
    }

    cout << "result: " << sundays << endl;
}
