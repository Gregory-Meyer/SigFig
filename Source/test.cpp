#include <iostream>
#include <cmath>

#include "SigFig.h"

using namespace std;

int main() {
	srand(time(NULL));
	double r1, r2;

	r1 = (double) rand() / (RAND_MAX + 1.0) * 10;
	r2 = (double) rand() / (RAND_MAX + 1.0) * 10;
	r1 -= 5;
	r2 -= 5;

	SigFig sf, sf2;

	sf = SigFig(r1, 2);	
	sf2 = SigFig(r2, 2);

	cout << sf << endl;
	cout << sf2 << endl;

	cout << sf.add(sf2) << endl;
	cout << sf.subtract(sf2) << endl;
}
