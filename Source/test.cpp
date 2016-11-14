#include <iostream>
#include <cmath>

#include "SigFig.h"
#include "SigFigMath.h"

using namespace std;

int main() {
	srand(time(NULL));
	double r1, r2;

	r1 = (double) rand() / (RAND_MAX + 1.0) * 100;
	r2 = (double) rand() / (RAND_MAX + 1.0) * 100;
	r1 -= 50;
	r2 -= 50;

	SigFig sf, sf2;

	sf = SigFig(r1, 5);
	sf2 = SigFig(r2, 5);

	r1 = (double) sf;
	r2 = (double) sf2;

	cout << sf << endl;
	cout << sf2 << endl << endl;

	cout << sfExp(sf) << endl;
	cout << sfExp(sf2) << endl;
	cout << sfLn(sf) << endl;
	cout << sfLn(sf2) << endl;
	cout << sfLog(sf, sf2) << endl;
	cout << sfLog(sf2, sf) << endl;
	cout << sfPow(sf, sf2) << endl;
	cout << sfPow(sf2, sf) << endl << endl;

	cout << exp(r1) << endl;
	cout << exp(r2) << endl;
	cout << log(r1) << endl;
	cout << log(r2) << endl;
	cout << log(r2) / log(r1) << endl;
	cout << log(r1) / log(r2) << endl;
	cout << pow(r1, r2) << endl;
	cout << pow(r2, r1) << endl;
}
