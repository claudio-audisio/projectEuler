#pragma once

#include <chrono>

#include "../problems/001_MultipleOf3And5.h"
#include "../problems/002_EvenFibonacciNumbers.h"
#include "../problems/003_LargestPrimeFactor.h"
#include "../problems/004_LargestPalindromeProduct.h"
#include "../problems/005_SmallestMultiple.h"
#include "../problems/006_SumSuqareDifference.h"
#include "../problems/008_LargestProductInASeries.h"
#include "../problems/009_SpecialPythagoreanTriplet.h"
#include "../problems/010_SummationOfPrimes.h"
#include "../problems/011_LargestProductInAGrid.h"
#include "../problems/014_LongestCollatzSequence.h"
#include "../problems/069_TotientMaximum.h"
#include "../problems/788_DominatingNumbers.h"
#include "../test/test.h"
#include "utils.h"
#include "problems/012_HighlyDivisibleTriangularNumber.h"
#include "problems/013_LargeSum.h"
#include "problems/015_LatticePaths.h"
#include "problems/018_MaximumPathSumI.h"
#include "problems/019_CountingSundays.h"
#include "problems/021_AmicableNumbers.h"
#include "problems/024_LexicographicPermutations.h"
#include "problems/025_1000-digitfibonacciNumber.h"
#include "problems/027_QuadraticPrimes.h"
#include "problems/031_CoinSums.h"
#include "problems/032_PandigitalProducts.h"
#include "problems/034_DigitFactorials.h"
#include "problems/044_PentagonNumbers.h"
#include "problems/050_ConsecutivePrimeSum.h"
#include "problems/063_PowerfulDigitCounts.h"
#include "problems/067_MaximumPathSumII.h"
#include "problems/991_FruitSalad.h"

using namespace std;

int menu()
{
	cout << "*** Project Euler! ***" << endl << endl;
	cout << "  0.\tPrint primes" << endl;
	cout << "  1.\tMultiples of 3 and 5" << endl;
	cout << "  2.\tEven Fibonacci numbers" << endl;
	cout << "  3.\tLargest prime factor" << endl;
	cout << "  4.\tLargest palindrome product" << endl;
	cout << "  5.\tSmallest multiple" << endl;
	cout << "  6.\tSum square difference" << endl;
	cout << "  7.\t10001st prime" << endl;
	cout << "  8.\tLargest product in a series" << endl;
	cout << "  9.\tSpecial Pythagorean triplet" << endl;
	cout << " 10.\tSummation of primes" << endl;
	cout << " 11.\tLargest product in a grid" << endl;\
	cout << " 12.\tHighly Divisible Triangular Number" << endl;
	cout << " 13.\tLarge Sum" << endl;
	cout << " 14.\tLongest Collatz sequence" << endl;
	cout << " 15.\tLattice Paths" << endl;
	cout << " 18.\tMaximum Path Sum I" << endl;
	cout << " 19.\tCounting Sundays" << endl;
	cout << " 21.\tAmicable Numbers" << endl;
	cout << " 24.\tLexicographic Permutations" << endl;
	cout << " 25.\t1000-digit Fibonacci Number" << endl;
	cout << " 27.\tQuadratic Primes" << endl;
	cout << " 31.\tCoin Sums" << endl;
	cout << " 32.\tPandigital Products" << endl;
	cout << " 34.\tDigit Factorials" << endl;
	cout << " 44.\tPentagon Numbers" << endl;
	cout << " 50.\tConsecutive Prime Sum" << endl;
	cout << " 63.\tPowerful Digit Counts" << endl;
	cout << " 67.\tMaximum Path Sum II" << endl;
	cout << " 69.\tTotient maximum" << endl;
	cout << "788.\tDominating Numbers" << endl;
	cout << "991.\tFruit Salad" << endl;
	cout << " -1.\tExit" << endl;
	
	cout << "\nSelect a problem to solve: ";

	int selection;
	cin >> selection;

	return selection;
}

void solveProblem(const int problem)
{
	const auto time = chrono::steady_clock::now();

	switch (problem) {
	case 0:		sievePrimes(10*1000*1000); break;
	case 1:		multipleOf3And5(); break;
	case 2:		evenFibonacciNumbers(4*1000*1000); break;
	case 3:		largestPrimeFactor(600851475143); break;
	case 4:		largestPalindromeProduct(); break;
	case 5:		smallestMultiple(20); break;
	case 6:		sumSquareDifference(100); break;
	case 7:		nThPrimes(10001); break;
	case 8:		largestProductInASeries(13); break;
	case 9:		specialPythagoreanTriplet(1000); break;
	case 10:	summationOfPrimes(2*1000*1000); break;
	case 11:	largestProductInAGrid(); break;
	case 12:	highlyDivisibleTriangularNumber(); break;
	case 13:	largeSum(); break;
	case 14:	longestCollatzSequence(10*1000*1000); break;
	case 15:	latticePaths(); break;
	case 18:	maximumPathSumI(); break;
	case 19:	countingSundays(); break;
	case 21:	amicableNumbers(10 * 1000); break;
	case 24:	lexicographicPermutations(1000 * 1000); break;
	case 25:	nDigitFibonacciNumber(1000); break;
	case 27:	quadraticPrimes(); break;
	case 31:	coinSums(200); break;
	case 32:	pandigitalProducts(); break;
	case 34:	digitFactorials(); break;
	case 44:	pentagonNumbers(); break;
	case 50:	consecutivePrimeSum(1000000); break;
	case 63:	powerfulDigitCounts(); break;
	case 67:	maximumPathSumII(); break;
	case 69:	totientMaximum(1000000); break;
	case 788:	dominatingNumbers(); break;		// TODO
	case 991:	fruitSalad(1000); break;	// TODO
	case -1:	exit(0);
	default: cout << "Problem " << problem << " not found" << endl; break;
	}

	std::cout << "time: " << getElapsedMillis(time) << " ms " << std::endl;
}
