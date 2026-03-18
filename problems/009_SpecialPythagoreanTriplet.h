#pragma once

using namespace std;

void specialPythagoreanTriplet(int limit) {
	int a, b, c;
	
	for (a = 1; a < limit; a++) {
		for (b = a + 1; a + b < limit; b++) {
			for (c = b + 1; a + b + c <= limit; c++) {
				if (a * a + b * b == c * c) {
					cout << "result: " << a << " " << b << " " << c << " - sum: " << a + b + c << endl;
				}
			}
		}
	}
}