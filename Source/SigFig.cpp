#include <iostream>
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

SigFig::SigFig(char input[MAX_INPUT_SIZE]) {
	writeFromString(input);
}

SigFig::SigFig(double real, int numSFsToSet) {
	roundRealToSigFig(real, numSFsToSet);
}

SigFig SigFig::add(SigFig aSigFig) const {
	SigFig numToReturn;
	int numSFsToSet, place1, place2, expToSet;
	double realValue1 = this->doubleValue();
	double realValue2 = aSigFig.doubleValue();
	double compoundRealValue = realValue1 + realValue2;

	if (compoundRealValue != 0) {
		place1 = this->getExponent() - this->getNumSigFigs() + 1;
		place2 = aSigFig.getExponent() - aSigFig.getNumSigFigs() + 1;

		expToSet = 0;

		while (abs(compoundRealValue) >= 10) {
			compoundRealValue /= 10;
			expToSet++;
		}

		while (abs(compoundRealValue) < 1) {
			compoundRealValue *= 10;
			expToSet--;
		}

		compoundRealValue *= pow(10, expToSet);

		if (place1 > place2) {
			numSFsToSet = expToSet - place1 + 1;
		} else {
			numSFsToSet = expToSet - place2 + 1;
		}

		if (abs(compoundRealValue) < 1) {
			numSFsToSet++;
		}

		numToReturn.roundRealToSigFig(compoundRealValue, numSFsToSet);
	} else {
		numToReturn.roundRealToSigFig(0, 1);
	}

	return numToReturn;
}

SigFig SigFig::subtract(SigFig aSigFig) const {
	SigFig numToReturn;
	int numSFsToSet, place1, place2, expToSet;
	double realValue1 = this->doubleValue();
	double realValue2 = aSigFig.doubleValue();
	double compoundRealValue = realValue1 - realValue2;

	if (compoundRealValue != 0) {
		place1 = this->getExponent() - this->getNumSigFigs() + 1;
		place2 = aSigFig.getExponent() - aSigFig.getNumSigFigs() + 1;

		expToSet = 0;

		while (abs(compoundRealValue) >= 10) {
			compoundRealValue /= 10;
			expToSet++;
		}

		while (abs(compoundRealValue) < 1) {
			compoundRealValue *= 10;
			expToSet--;
		}

		compoundRealValue *= pow(10, expToSet);

		if (place1 > place2) {
			numSFsToSet = expToSet - place1 + 1;
		} else {
			numSFsToSet = expToSet - place2 + 1;
		}

		if (abs(compoundRealValue) < 1) {
			numSFsToSet++;
		}

		numToReturn.roundRealToSigFig(compoundRealValue, numSFsToSet);
	} else {
		numToReturn.roundRealToSigFig(0, 1);
	}

	return numToReturn;
}

SigFig SigFig::multiply(SigFig aSigFig) const {
	SigFig numToReturn;
	int numSFsToSet;
	double compoundRealValue = this->doubleValue() * aSigFig.doubleValue();

	if (this->getNumSigFigs() < aSigFig.getNumSigFigs()) {
		numSFsToSet = this->getNumSigFigs();
	} else {
		numSFsToSet = aSigFig.getNumSigFigs();
	}

	numToReturn.roundRealToSigFig(compoundRealValue, numSFsToSet);
	return numToReturn;
}

SigFig SigFig::divide(SigFig aSigFig) const {
	SigFig numToReturn;
	int numSFsToSet;
	double compoundRealValue = this->doubleValue() / aSigFig.doubleValue();

	if (this->getNumSigFigs() < aSigFig.getNumSigFigs()) {
		numSFsToSet = this->getNumSigFigs();
	} else {
		numSFsToSet = aSigFig.getNumSigFigs();
	}

	numToReturn.roundRealToSigFig(compoundRealValue, numSFsToSet);
	return numToReturn;
}

SigFig SigFig::remainder(SigFig aSigFig) const {
	SigFig numToReturn;
	int numSFsToSet;
	double realValue1 = this->doubleValue();
	double realValue2 = aSigFig.doubleValue();
	double compoundRealValue = realValue1 - realValue2
	* (int) (realValue1 / realValue2);

	if (this->getNumSigFigs() < aSigFig.getNumSigFigs()) {
		numSFsToSet = this->getNumSigFigs();
	} else {
		numSFsToSet = aSigFig.getNumSigFigs();
	}

	numToReturn.roundRealToSigFig(compoundRealValue, numSFsToSet);
	return numToReturn;
}

int SigFig::intValue() const {
	return (int) this->getSignificand() * pow(10, this->getExponent());
}

double SigFig::doubleValue() const {
	return this->getSignificand() * pow(10, this->getExponent());
}

bool SigFig::isInt() const {
	return this->intValue() == this->doubleValue();
}

bool SigFig::isEqualStrict(SigFig aSigFig) const {
	return this->isEqual(aSigFig)
		&& (this->getNumSigFigs() == aSigFig.getNumSigFigs());
}

bool SigFig::isEqual(SigFig aSigFig) const {
	return this->doubleValue() == aSigFig.doubleValue();
}

bool SigFig::isGreater(SigFig aSigFig) const {
	return this->doubleValue() > aSigFig.doubleValue();
}

bool SigFig::isLess(SigFig aSigFig) const {
	return this->doubleValue() < aSigFig.doubleValue();
}

bool SigFig::isGreaterOrEqualStrict(SigFig aSigFig) const {
	return (this->isGreater(aSigFig)) || (this->isEqualStrict(aSigFig));
}

bool SigFig::isGreaterOrEqual(SigFig aSigFig) const {
	return !this->isLess(aSigFig);
}

bool SigFig::isLessOrEqualStrict(SigFig aSigFig) const {
	return (this->isLess(aSigFig)) || (this->isEqualStrict(aSigFig));
}

bool SigFig::isLessOrEqual(SigFig aSigFig) const {
	return !this->isGreater(aSigFig);
}

void SigFig::setSignificand(double newSignificand) {
	significand_ = newSignificand;
}

double SigFig::getSignificand() const {
	return significand_;
}

void SigFig::setExponent(int newExponent) {
	exponent_ = newExponent;
}

int SigFig::getExponent() const {
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

int SigFig::getNumSigFigs() const {
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
	bool isNegative = false;

	bufferChar = input[i];

	if (bufferChar == '-') {
		isNegative = true;
	}

	while ((isdigit(bufferChar)) || (bufferChar == '.')
		|| (bufferChar == '-')) {
		if (isdigit(bufferChar)) {
			str[strIndex] = bufferChar;
			strIndex++;
		} else if (bufferChar == '.') {
			hasDecimal = true;
			decimalIndex = i;
		}

		i++;
		bufferChar = input[i];
	}

	if (isNegative) {
		decimalIndex--;
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

		expToSet = strIndex - 1;
	}

	significandToSet = atof(input);

	while (significandToSet > 10) {
		significandToSet /= 10;
	}

	this->setSignificand(significandToSet);
	this->setExponent(expToSet);
	this->setNumSigFigs(numSFsToSet);
}

void SigFig::read(istream& inputStream) {
	char output[MAX_INPUT_SIZE];

	// trim all leading zeros from inputStream
	char bufferChar;
	while (inputStream.get(bufferChar)) {
		if (bufferChar != '0') {
			inputStream.putback(bufferChar);
			break;
		}
	}

	inputStream >> output;

	writeFromString(output);
}

void SigFig::write(ostream& outputStream) {
	if (this->getNumSigFigs() == 1) {
		outputStream << this->getSignificand() << 'e' << this->getExponent();
	} else if (this->getSignificand() == 0) {
		outputStream << "0e0";
	} else {
		double temp = this->getSignificand();
		int i = 1;

		while (temp != round(temp)) {
			temp *= 10;
			i++;
		}

		if (this->isInt()) {
			if (i < this->getNumSigFigs()) {
				outputStream << this->getSignificand();
				for (int j = 0; j < this->getNumSigFigs() - i; j++) {
					outputStream << '0';
				}
				outputStream << 'e' << this->getExponent();
			} else {
				outputStream << this->getSignificand() << 'e'
				<< this->getExponent();
			}
		} else {
			outputStream << this->getSignificand() << '.';
			for (int j = 0; j < this->getNumSigFigs() - 1; j++) {
				outputStream << '0';
			}
			outputStream << 'e' << this->getExponent();
		}
	}
}

void SigFig::roundRealToSigFig(double real, int numSFsToSet) {
	if (real == 0) {
		this->setExponent(0);
		this->setSignificand(0);
		this->setNumSigFigs(1);
	} else {
		int i = 0;

		while (abs(real) > pow(10, numSFsToSet)) {
			real /= 10;
			i++;
		}

		while (abs(real) < pow(10, numSFsToSet - 1)) {
			real *= 10;
			i--;
		}

		real = round(real);

		while (abs(real) >= 10) {
			real /= 10;
			i++;
		}

		this->setExponent(i);
		this->setSignificand(real);
		this->setNumSigFigs(numSFsToSet);
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

bool operator == (const SigFig& lhs, const SigFig& rhs) {
	return lhs.isEqual(rhs);
}

bool operator != (const SigFig& lhs, const SigFig& rhs) {
	return !(lhs == rhs);
}

bool operator < (const SigFig& lhs, const SigFig& rhs) {
	return lhs.isLess(rhs);
}

bool operator > (const SigFig& lhs, const SigFig& rhs) {
	return rhs < lhs;
}

bool operator <= (const SigFig& lhs, const SigFig& rhs) {
	return !(lhs > rhs);
}

bool operator >= (const SigFig& lhs, const SigFig& rhs) {
	return !(lhs < rhs);
}

SigFig& operator ++ (SigFig& aSigFig) {
	aSigFig.roundRealToSigFig(aSigFig.doubleValue() + 1,
		aSigFig.getNumSigFigs());
	return aSigFig;
}

SigFig operator ++ (SigFig& aSigFig, int) {
	SigFig temp = aSigFig;
	++aSigFig;
	return temp;
}

SigFig& operator -- (SigFig& aSigFig) {
	aSigFig.roundRealToSigFig(aSigFig.doubleValue() - 1,
		aSigFig.getNumSigFigs());
	return aSigFig;
}

SigFig operator -- (SigFig& aSigFig, int){
	SigFig temp = aSigFig;
	--aSigFig;
	return temp;
}

const SigFig operator + (const SigFig& lhs, const SigFig& rhs) {
	SigFig temp = lhs;
	temp += rhs;
	return temp;
}

const SigFig operator - (const SigFig& lhs, const SigFig& rhs) {
	SigFig temp = lhs;
	temp -= rhs;
	return temp;
}

const SigFig operator * (const SigFig& lhs, const SigFig& rhs) {
	SigFig temp = lhs;
	temp *= rhs;
	return temp;
}

const SigFig operator / (const SigFig& lhs, const SigFig& rhs) {
	SigFig temp = lhs;
	temp /= rhs;
	return temp;
}

const SigFig operator % (const SigFig& lhs, const SigFig& rhs) {
	SigFig temp = lhs;
	temp %= rhs;
	return temp;
}

SigFig& operator += (SigFig& lhs, const SigFig& rhs) {
	lhs = lhs.add(rhs);
	return lhs;
}

SigFig& operator -= (SigFig& lhs, const SigFig& rhs) {
	lhs = lhs.subtract(rhs);
	return lhs;
}

SigFig& operator *= (SigFig& lhs, const SigFig& rhs) {
	lhs = lhs.multiply(rhs);
	return lhs;
}

SigFig& operator /= (SigFig& lhs, const SigFig& rhs) {
	lhs = lhs.divide(rhs);
	return lhs;
}

SigFig& operator %= (SigFig& lhs, const SigFig& rhs) {
	lhs = lhs.remainder(rhs);
	return lhs;
}