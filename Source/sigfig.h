#ifndef SIGFIG_H
#define SIGFIG_H

#include <iostream>

using namespace std;

class sigfig {
public:
	static const int MAX_SIZE = 256;

	sigfig();

	sigfig(char a[MAX_SIZE]);

	sigfig plus(sigfig sf);

	sigfig minus(sigfig sf);

	sigfig mult(sigfig sf);

	sigfig quot(sigfig sf);

	void setVal(double a);

	double getVal();

	void setExp(int a);

	int getExp();

	void setSFs(int a);

	int getSFs();

	void readChar(char a[MAX_SIZE]);

	void read(istream& ins);

	void write(ostream& ins);

private:
	double value;
	int exponent;
	int nSFs;

	void roundToSFs(double d, int nSF);
};

istream& operator >> (istream& ins, sigfig& sf);
ostream& operator << (ostream& outs, sigfig sf);

#endif
