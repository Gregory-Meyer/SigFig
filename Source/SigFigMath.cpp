#include <cmath>

#include "SigFig.h"
#include "SigFigMath.h"

using namespace std;

const long double PI = 4 * atan(1);
const long double E = exp(1);
const SigFig PI_SF = SigFig(PI);
const SigFig E_SF = SigFig(E);

SigFig sfRoundUp(const SigFig aSigFig) {
	double realValue = aSigFig.doubleValue();

	if (realValue < 0) {
		return sfFloor(aSigFig);
	} else {
		return sfCeil(aSigFig);
	}
}

SigFig sfRoundDown(const SigFig aSigFig) {
	SigFig numToReturn;
	double realValue = (double) aSigFig;

	numToReturn.roundRealToSigFig(trunc(realValue), aSigFig.getNumSigFigs());
	return numToReturn;
}

SigFig sfFloor(const SigFig aSigFig) {
	SigFig numToReturn;
	double realValue = (double) aSigFig;

	numToReturn.roundRealToSigFig(floor(realValue), aSigFig.getNumSigFigs());
	return numToReturn;
}

SigFig sfCeil(const SigFig aSigFig) {
	SigFig numToReturn;
	double realValue = (double) aSigFig;

	numToReturn.roundRealToSigFig(ceil(realValue), aSigFig.getNumSigFigs());
	return numToReturn;
}

SigFig sfRound(const SigFig aSigFig)  {
	SigFig numToReturn;
	double realValue = (double) aSigFig;

	numToReturn.roundRealToSigFig(round(realValue), aSigFig.getNumSigFigs());
	return numToReturn;
}

SigFig sfExp(const SigFig exponent) {
	SigFig numToReturn;
	double significandToSet = exp((double) exponent);
	numToReturn.roundRealToSigFig(significandToSet, exponent.getNumSigFigs());
	
	return numToReturn;
}

SigFig sfLn(const SigFig aSigFig) {
	SigFig numToReturn;
	double significandToSet = log(abs((double) aSigFig));

	numToReturn.roundRealToSigFig(significandToSet, aSigFig.getNumSigFigs());
	
	return numToReturn;
}

SigFig sfLog(const SigFig base, const SigFig aSigFig) {
	SigFig numToReturn;
	int numSFsToSet;
	double significandToSet;
	double a = (double) aSigFig;
	double b = (double) base;

	if ((b > 0) && (a < 0)) {
		significandToSet = log(-a) / log(b);
	} else if ((b > 0) && (a > 0)) {
		significandToSet = log(a) / log(b);
	} else if ((b < 0) && (a < 0)) {
		significandToSet = log(-a) * log(-b) / (pow(log(-b), 2) + pow(PI, 2))
			+ pow(PI, 2) / (pow(log(-b), 2) + pow(PI, 2));
	} else if ((b < 0) && (a > 0)) {
		significandToSet = log(a) * log(-b) / (pow(log(-b), 2) + pow(PI, 2));
	} else {
		significandToSet = 0;
		cerr << "ERROR: Cannot take logarithm with a base or value of zero."
			<< endl;
	}

	if (base.getNumSigFigs() < aSigFig.getNumSigFigs()) {
		numSFsToSet = base.getNumSigFigs();
	} else {
		numSFsToSet = aSigFig.getNumSigFigs();
	}

	numToReturn.roundRealToSigFig(significandToSet, numSFsToSet);
	
	return numToReturn;
}

SigFig sfPow(const SigFig base, const SigFig exponent) {
	SigFig numToReturn;
	int numSFsToSet;
	double significandToSet;

	if ((double) base < 0) {
		significandToSet = pow(abs((double) base), (double) exponent)
			* cos((double) exponent * PI);
	} else {
		significandToSet = pow((double) base, (double) exponent);
	}

	if (base.getNumSigFigs() < exponent.getNumSigFigs()) {
		numSFsToSet = base.getNumSigFigs();
	} else {
		numSFsToSet = exponent.getNumSigFigs();
	}

	numToReturn.roundRealToSigFig(significandToSet, numSFsToSet);
	
	return numToReturn;
}

SigFig sfAbs(const SigFig aSigFig) {
	SigFig numToReturn;
	double significandToSet = abs((double) aSigFig);
	numToReturn.roundRealToSigFig(significandToSet, aSigFig.getNumSigFigs());

	return numToReturn;
}