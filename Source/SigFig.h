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
	SigFig add(SigFig aSigFig) const;

	// subtracts two SigFig objects and returns the result
	SigFig subtract(SigFig aSigFig) const;

	// multiplies two SigFig objects and returns the result
	SigFig multiply(SigFig aSigFig) const;

	// divides two SigFig objects and returns the result
	SigFig divide(SigFig aSigFig) const;

	// divides two SigFig objects and returns the remainder
	SigFig remainder(SigFig aSigFig) const;

	// returns the value of the SigFig object as an int
	int intValue() const;

	// returns the value of the SigFig object as a double
	double doubleValue() const;

	// returns true if the double value of the SigFig is the same as the int
	// value
	bool isInt() const;

	// returns true if the object and aSigFig have the same double value and
	// the same number of significant figures
	bool isEqualStrict(SigFig aSigFig) const;

	// returns true if the object and aSigFig have the same double value
	bool isEqual(SigFig aSigFig) const;

	// returns true if the object's double value is greater than aSigFig's
	// double value
	bool isGreater(SigFig aSigFig) const;

	// returns true if the object's double value is less than aSigFig's
	// double value
	bool isLess(SigFig aSigFig) const;

	// returns true if isEqualStrict() or isGreater()
	bool isGreaterOrEqualStrict(SigFig aSigFig) const;

	// returns true if isEqual() or isGreater();
	bool isGreaterOrEqual(SigFig aSigFig) const;

	// returns true if isEqualStrict() or isLess()
	bool isLessOrEqualStrict(SigFig aSigFig) const;

	// returns true if isEqual() or isLess()
	bool isLessOrEqual(SigFig aSigFig) const;

	// sets the significand or value as newSignificand
	void setSignificand(double newSignificand);

	// returns the significand
	double getSignificand() const;

	// sets the exponent as newExponent
	void setExponent(int newExponent);

	// gets the exponent
	int getExponent() const;

	// sets the number of significant figures as newNumSigFigs if newNumSigFigs
	// is greater than 0
	void setNumSigFigs(int newNumSigFigs);

	// returns the number of significant figures
	int getNumSigFigs() const;

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

bool operator == (const SigFig& lhs, const SigFig& rhs);
	
bool operator != (const SigFig& lhs, const SigFig& rhs);
	
bool operator < (const SigFig& lhs, const SigFig& rhs);
	
bool operator > (const SigFig& lhs, const SigFig& rhs);
	
bool operator <= (const SigFig& lhs, const SigFig& rhs);
	
bool operator >= (const SigFig& lhs, const SigFig& rhs);

SigFig& operator ++ (SigFig& aSigFig);

SigFig operator ++ (SigFig& aSigFig, int);

SigFig& operator -- (SigFig& aSigFig);

SigFig operator -- (SigFig& aSigFig, int);

#endif
