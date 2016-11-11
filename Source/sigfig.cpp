#include <istream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <cmath>

#include "sigfig.h"

using namespace std;

sigfig::sigfig() { }

sigfig::sigfig(char a[MAX_SIZE]) {
	readChar(a);
}

sigfig sigfig::plus(sigfig sf) {
	double d1 = getVal() * pow(10, getExp());
	double d2 = sf.getVal() * pow(10, sf.getExp());

	double d = d1 + d2;
	return sf;
}

sigfig sigfig::minus(sigfig sf) {
	double d1 = getVal() * pow(10, getExp());
	double d2 = sf.getVal() * pow(10, sf.getExp());

	double d = d1 - d2;
	return sf;
}

sigfig sigfig::mult(sigfig sf) {
	double d = getVal() * pow(10, getExp()) * sf.getVal() * pow(10, sf.getExp());

	int tnSFs;

	if (getSFs() < sf.getSFs()) {
		tnSFs = getSFs();
	} else {
		tnSFs = sf.getSFs();
	}

	sigfig sfRet;
	sfRet.roundToSFs(d, tnSFs);
	return sfRet;
}

sigfig sigfig::quot(sigfig sf) {
	double d = getVal() * pow(10, getExp()) / (sf.getVal() * pow(10, sf.getExp()));

	int tnSFs;

	if (getSFs() < sf.getSFs()) {
		tnSFs = getSFs();
	} else {
		tnSFs = sf.getSFs();
	}

	sigfig sfRet;
	sfRet.roundToSFs(d, tnSFs);
	return sfRet;
}

void sigfig::setVal(double d) {
	value = d;
}

double sigfig::getVal() {
	return value;
}

void sigfig::setExp(int i) {
	exponent = i;
}

int sigfig::getExp() {
	return exponent;
}

void sigfig::setSFs(int a) {
	nSFs = a;
}

int sigfig::getSFs() {
	return nSFs;
}

void sigfig::readChar(char a[MAX_SIZE]) {
	char temp;
	char str[MAX_SIZE];

	bool hasDec = false;
	int decIndex;
	int strIndex = 0;
	int startIndex = 0;

	int i = 0;
	temp = a[i];

	while ((isdigit(temp)) || (temp == '.')) {
		if (isdigit(temp)) {
			str[strIndex] = temp;
			strIndex++;
		} else {
			if (temp == '.') {
				hasDec = true;
				decIndex = i;
			}
		}

		i++;
		temp = a[i];
	}

	int tnSFs = 0;

	if (hasDec) {
		if (decIndex == 0) {
			tnSFs = strIndex;
		} else {
			tnSFs = strIndex;
		}

		if (decIndex == strIndex) {
			setExp(tnSFs - 1);
		} else {
			setExp(decIndex - 1);
		}
	} else {
		for (int i = 0; i <= strIndex; i++) {
			if (str[i] != '0') {
				tnSFs = i;
			}
		}

		setExp(strIndex);
	}

	setSFs(tnSFs);

	double tempD = atof(a);

	while (tempD > 10) {
		tempD /= 10;
	}

	setVal(tempD);
}

void sigfig::read(istream& ins) {
	char a[MAX_SIZE];

	char c;
	while (ins.get(c)) {
		if (c != '0') {
			ins.putback(c);
			break;
		}
	}

	ins >> a;

	readChar(a);
}

void sigfig::write(ostream& outs) {
	if (getSFs() == 1) {
		outs << getVal() << 'e' << getExp();
	} else {
		double temp = getVal();
		int i = 1;

		while (temp != round(temp)) {
			temp *= 10;
			i++;
		}

		if (getVal() != round(getVal())) {
			if (i < getSFs()) {
				outs << getVal();
				for (int j = 0; j < getSFs() - i; j++) {
					outs << '0';
				}
				outs << 'e' << getExp();
			} else {
				outs << getVal() << 'e' << getExp();
			}
		} else {
			outs << getVal() << '.';
			for (int j = 0; j < getSFs() - 1; j++) {
				outs << '0';
			}
			outs << 'e' << getExp();
		}
	}
}

void sigfig::roundToSFs(double d, int nSF) {
	int i = 0;

	while (d > pow(10, nSF)) {
		d /= 10;
		i++;
	}

	while (d < pow(10, nSF - 1)) {
		d *= 10;
		i--;
	}

	d = round(d);

	while (d >= 10) {
		d /= 10;
		i++;
	}

	setExp(i);
	setVal(d);
	setSFs(nSF);
}

istream& operator >> (istream& ins, sigfig& sf) {
	sf.read(ins);
	return ins;
}

ostream& operator << (ostream& outs, sigfig sf) {
	sf.write(outs);
	return outs;
}