#include <cstdio>
#include <iostream>

#include "common/services.h"
#include "problems/013_LargeSum.h"

using namespace std;

int main(int argc, char* argv[])
{
	//test();

	int selection = 0;

	while (selection != -1) {
		selection = menu();
		solveProblem(selection);
		cout << "\n" << endl;
	}

	return 0;
}