#ifndef SigFig_H
#define SigFig_H

#include <iostream>

using namespace std;

class SigFig {
public:
	// maximum number of characters allowed for a char[] input
	static const int MAX_INPUT_SIZE = 256;

	// default constructor, initializes as 0e0
	SigFig();

	// initalizes a SigFig from a char[] input
	SigFig(char a[MAX_INPUT_SIZE]);

	// initializes a SigFig from a real number and an integer number of
	// significant figures
	SigFig(double real, int numSFsToSet);

	// adds two SigFig objects and returns the result
	SigFig add(SigFig aSigFig);

	// subtracts two SigFig objects and returns the result
	SigFig subtract(SigFig aSigFig);

	// multiplies two SigFig objects and returns the result
	SigFig multiply(SigFig aSigFig);

	// divides two SigFig objects and returns the result
	SigFig divide(SigFig aSigFig);

	// divides two SigFig objects and returns the remainder
	SigFig remainder(SigFig aSigFig);

	// sets the significand or value as newSignificand
	void setSignificand(double newSignificand);

	// returns the significand
	double getSignificand();

	// sets the exponent as newExponent
	void setExponent(int newExponent);

	// gets the exponent
	int getExponent();

	// sets the number of significant figures as newNumSigFigs if newNumSigFigs
	// is greater than 0
	void setNumSigFigs(int newNumSigFigs);

	// returns the number of significant figures
	int getNumSigFigs();

	// sets the values of a significant figure from a char[] input
	void writeFromString(char a[MAX_INPUT_SIZE]);

	// takes a real number 'real' and a number of significant figures 
	// 'numSigFigs' and rounds that number to the correct amount of significant
	// figures, then assigns that value to the SigFig called from
	void roundRealToSigFig(double real, int numSigFigs);

	void read(istream& inputStream);

	void write(ostream& outputStream);

private:
	double significand_;
	int exponent_;
	int numSigFigs_;
};

istream& operator >> (istream& inputStream, SigFig& aSigFig);
ostream& operator << (ostream& outputStream, SigFig aSigFig);

#endif
