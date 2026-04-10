#pragma once
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

#include "common/type.h"
#include "common/utils.h"


void maximumPathSumII() {
	std::vector<std::vector<unsLL>*> triangle;
	int level = 0;
	auto lines = readFile("../resource/067_triangle.txt");

	for (auto line : *lines) {
		triangle.push_back(new vector<unsLL>());
		auto values = line | views::split(' ');
		for (auto value : values) {
			triangle.at(level)->push_back(stoull(value.data()));
		}
		level++;
	}

	vector<unsLL> sum;
	vector<unsLL> newSum;

	for (int i = 0; i < triangle[triangle.size() - 1]->size(); i++) {
		sum.push_back(triangle[triangle.size() - 1]->at(i));
	}

	for (int row = triangle.size() - 2; row >= 0; row--) {
		for (int j = 0; j < triangle[row]->size(); j++) {
			newSum.push_back(std::max(sum[j], sum[j + 1]) + triangle[row]->at(j));
		}
		sum.clear();
		sum = newSum;
		newSum.clear();
	}

	std::cout << "result: " << sum[0] << std::endl;
}
