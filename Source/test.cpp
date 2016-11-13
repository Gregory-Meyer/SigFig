#include <iostream>
#include <cmath>

#include "SigFig.h"

using namespace std;

int main() {
	srand(time(NULL));
	double r1, r2;

	r1 = (double) rand() / (RAND_MAX + 1.0) * 100;
	r1 -= 50;

	r2 = (double) rand() / (RAND_MAX + 1.0) * 100;
	r2 -= 50;

	SigFig sf, sf2;

	sf = SigFig(r1, 5);
	sf2 = SigFig(r2, 5);

	r1 = sf.intValue();
	r2 = sf2.intValue();

	cout << r1 << endl;
	cout << r2 << endl;

	cout << (int) sf << endl;
	cout << (int) sf2 << endl;
}
