#include <istream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <cmath>

#include "SigFig.h"

using namespace std;

SigFig::SigFig() {
	setSignificand(0);
	setExponent(0);
	setNumSigFigs(1);
}

SigFig::SigFig(char a[MAX_INPUT_SIZE]) {
	writeFromString(a);
}

SigFig SigFig::add(SigFig aSigFig) {
	SigFig numToReturn;
	int numSFsToSet, place1, place2, expToSet;
	double realValue1 = getSignificand() * pow(10, getExponent());
	double realValue2 = aSigFig.getSignificand()
		* pow(10, aSigFig.getExponent());
	double compoundRealValue = realValue1 + realValue2;

	if (compoundRealValue != 0) {
		place1 = getExponent() - getNumSigFigs() + 1;
		place2 = getExponent() - getNumSigFigs() + 1;

		expToSet = 0;

		while (compoundRealValue >= 10) {
			compoundRealValue /= 10;
			expToSet++;
		}

		while (compoundRealValue < 1) {
			compoundRealValue *= 10;
			expToSet--;
		}

		compoundRealValue *= pow(10, expToSet);

		if (place1 > place2) {
			numSFsToSet = expToSet - place1;
		} else {
			numSFsToSet = expToSet - place2;
		}
		
		numToReturn.roundRealToSigFig(compoundRealValue, numSFsToSet);
	} else {
		numToReturn.roundRealToSigFig(0, 1);
	}

	return numToReturn;
}

SigFig SigFig::subtract(SigFig aSigFig) {
	SigFig numToReturn;
	int numSFsToSet, place1, place2, expToSet;
	double realValue1 = getSignificand() * pow(10, getExponent());
	double realValue2 = aSigFig.getSignificand()
		* pow(10, aSigFig.getExponent());
	double compoundRealValue = realValue1 - realValue2;

	if (compoundRealValue != 0) {
		place1 = getExponent() - getNumSigFigs() + 1;
		place2 = getExponent() - getNumSigFigs() + 1;

		expToSet = 0;

		while (compoundRealValue >= 10) {
			compoundRealValue /= 10;
			expToSet++;
		}

		while (compoundRealValue < 1) {
			compoundRealValue *= 10;
			expToSet--;
		}

		compoundRealValue *= pow(10, expToSet);

		if (place1 > place2) {
			numSFsToSet = expToSet - place1;
		} else {
			numSFsToSet = expToSet - place2;
		}
		
		numToReturn.roundRealToSigFig(compoundRealValue, numSFsToSet);
	} else {
		numToReturn.roundRealToSigFig(0, 1);
	}

	return numToReturn;
}

SigFig SigFig::multiply(SigFig aSigFig) {
	SigFig numToReturn;
	int numSFsToSet;
	double compoundRealValue = getSignificand() * pow(10, getExponent())
		* aSigFig.getSignificand() * pow(10, aSigFig.getExponent());

	if (getNumSigFigs() < aSigFig.getNumSigFigs()) {
		numSFsToSet = getNumSigFigs();
	} else {
		numSFsToSet = aSigFig.getNumSigFigs();
	}

	numToReturn.roundRealToSigFig(compoundRealValue, numSFsToSet);
	return numToReturn;
}

SigFig SigFig::divide(SigFig aSigFig) {
	SigFig numToReturn;
	int numSFsToSet;
	double compoundRealValue = getSignificand() * pow(10, getExponent())
		/ aSigFig.getSignificand() * pow(10, aSigFig.getExponent());

	if (getNumSigFigs() < aSigFig.getNumSigFigs()) {
		numSFsToSet = getNumSigFigs();
	} else {
		numSFsToSet = aSigFig.getNumSigFigs();
	}

	numToReturn.roundRealToSigFig(compoundRealValue, numSFsToSet);
	return numToReturn;
}

void SigFig::setSignificand(double newSignificand) {
	significand_ = newSignificand;
}

double SigFig::getSignificand() {
	return significand_;
}

void SigFig::setExponent(int newExponent) {
	exponent_ = newExponent;
}

int SigFig::getExponent() {
	return exponent_;
}

void SigFig::setNumSigFigs(int newNumSigFigs) {
	if (newNumSigFigs > 0) {
		numSigFigs_ = newNumSigFigs;
	} else {
		cerr << "ERROR: Tried to set number of significant figures as " <<
			newNumSigFigs <<
			". Number of significant figures must be greater than zero."
			<< endl;
	}
}

int SigFig::getNumSigFigs() {
	return numSigFigs_;
}

void SigFig::writeFromString(char input[MAX_INPUT_SIZE]) {
	char bufferChar;
	char str[MAX_INPUT_SIZE];
	int decimalIndex, numSFsToSet, expToSet;
	double significandToSet;
	int strIndex = 0;
	int i = 0;
	bool hasDecimal = false;

	bufferChar = input[i];

	while ((isdigit(bufferChar)) || (bufferChar == '.')) {
		if (isdigit(bufferChar)) {
			str[strIndex] = bufferChar;
			strIndex++;
		} else {
			if (bufferChar == '.') {
				hasDecimal = true;
				decimalIndex = i;
			}
		}

		i++;
		bufferChar = input[i];
	}

	numSFsToSet = 0;

	if (hasDecimal) {
		numSFsToSet = strIndex;

		if (decimalIndex == strIndex) {
			expToSet = numSFsToSet - 1;
		} else {
			expToSet = decimalIndex - 1;
		}
	} else {
		for (int j = 0; j <= strIndex; j++) {
			if (str[j] != '0') {
				numSFsToSet = j;
			}
		}

		expToSet = strIndex;
	}

	significandToSet = atof(input);

	while (significandToSet > 10) {
		significandToSet /= 10;
	}

	setSignificand(significandToSet);
	setExponent(expToSet);
	setNumSigFigs(numSFsToSet);
}

void SigFig::read(istream& inputStream) {
	char a[MAX_INPUT_SIZE];

	char c;
	while (inputStream.get(c)) {
		if (c != '0') {
			inputStream.putback(c);
			break;
		}
	}

	inputStream >> a;

	writeFromString(a);
}

void SigFig::write(ostream& outputStream) {
	if (getNumSigFigs() == 1) {
		outputStream << getSignificand() << 'e' << getExponent();
	} else if (getSignificand() == 0) {
		outputStream << "0e0";
	} else {
		double temp = getSignificand();
		int i = 1;

		while (temp != round(temp)) {
			temp *= 10;
			i++;
		}

		if (getSignificand() != round(getSignificand())) {
			if (i < getNumSigFigs()) {
				outputStream << getSignificand();
				for (int j = 0; j < getNumSigFigs() - i; j++) {
					outputStream << '0';
				}
				outputStream << 'e' << getExponent();
			} else {
				outputStream << getSignificand() << 'e' << getExponent();
			}
		} else {
			outputStream << getSignificand() << '.';
			for (int j = 0; j < getNumSigFigs() - 1; j++) {
				outputStream << '0';
			}
			outputStream << 'e' << getExponent();
		}
	}
}

void SigFig::roundRealToSigFig(double d, int nSF) {
	if (d == 0) {
		setExponent(0);
		setSignificand(0);
		setNumSigFigs(1);
	} else {
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

		setExponent(i);
		setSignificand(d);
		setNumSigFigs(nSF);
	}
}

istream& operator >> (istream& inputStream, SigFig& aSigFig) {
	aSigFig.read(inputStream);
	return inputStream;
}

ostream& operator << (ostream& outputStream, SigFig aSigFig) {
	aSigFig.write(outputStream);
	return outputStream;
}
