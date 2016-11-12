#include <iostream>
#include "sigfig.h"

using namespace std;

int main() {
	char a[] = "4.";
	char b[] = "4.5";

	sigfig sf, sf2;

	sf = sigfig(a);
	sf2 = sigfig(b);

	cout << sf.plus(sf2) << endl;
	cout << sf.minus(sf2) << endl;
}
