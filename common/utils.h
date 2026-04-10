#pragma once

#include <fstream>

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

inline int lengthD(const double number) {
	if (number == 0) return 1;
	return floor(log10(std::abs(number))) + 1;
}

inline int length(const LL number) {
	if (number == 0) return 1;
	return floor(log10(std::abs(number))) + 1;
}

vector<int>* extractdigits(unsLL number) {
	const int len = length(number);
	auto digits = new vector<int>(len);

	for (int i = 0; i < len; i++) {
		(*digits)[i] = number % 10;
		number /= 10;
	}

	return digits;
}

vector<string>* readFile(const string& fileName) {
	ifstream file(fileName);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open the file: " << fileName << std::endl;
		return nullptr;
	}

	vector<string>* lines = new vector<string>();
	std::string line;

	while (std::getline(file, line)) {
		lines->push_back(line);
	}

	file.close();
	return lines;
}



