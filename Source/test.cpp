#include <iostream>
#include <cmath>

#include "SigFig.h"

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

	cout << sf << " mod " << sf2 << " = " << sf.remainder(sf2) << endl;
}
