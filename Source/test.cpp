#include <iostream>
#include "sigfig.h"

using namespace std;

int main() {
	char a[] = "4.00";
	char b[] = "4.00";

	sigfig sf, sf2;

	sf = sigfig(a);
	sf2 = sigfig(b);

	cout << sf.mult(sf2) << endl;
	cout << sf.quot(sf2) << endl;
}