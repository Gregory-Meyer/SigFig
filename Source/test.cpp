#include <iostream>
#include <cmath>

#include "SigFig.h"

using namespace std;

int main() {
	srand(time(NULL));
	double r1;

	r1 = (double) rand() / (RAND_MAX + 1.0) * 100;
	r1 -= 50;

	SigFig sf;

	sf = SigFig(r1, 5);	

	cout << sf.doubleValue() << endl << endl;

	cout << sf.sfFloor().doubleValue() << endl;
	cout << sf.sfCeil().doubleValue() << endl;
	cout << sf.sfRound().doubleValue() << endl;
	cout << sf.sfRoundUp().doubleValue() << endl;
	cout << sf.sfRoundDown().doubleValue() << endl;
}
