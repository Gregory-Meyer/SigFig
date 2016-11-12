#include <iostream>
#include "SigFig.h"

using namespace std;

int main() {
	char a[] = "8.00";
	char b[] = "4.10";

	SigFig sf, sf2;

	sf = SigFig(a);	
	sf2 = SigFig(b);

	cout << sf << endl;
	cout << sf2 << endl;

	cout << sf.add(sf2) << endl;
	cout << sf.subtract(sf2) << endl;
}
