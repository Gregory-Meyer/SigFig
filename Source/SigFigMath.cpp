#include <cmath>

#include "SigFig.h"
#include "SigFigMath.h"

using namespace std;

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
	double realValue = aSigFig.doubleValue();

	numToReturn.roundRealToSigFig(trunc(realValue), aSigFig.getNumSigFigs());
	return numToReturn;
}

SigFig sfFloor(const SigFig aSigFig) {
	SigFig numToReturn;
	double realValue = aSigFig.doubleValue();

	numToReturn.roundRealToSigFig(floor(realValue), aSigFig.getNumSigFigs());
	return numToReturn;
}

SigFig sfCeil(const SigFig aSigFig) {
	SigFig numToReturn;
	double realValue = aSigFig.doubleValue();

	numToReturn.roundRealToSigFig(ceil(realValue), aSigFig.getNumSigFigs());
	return numToReturn;
}

SigFig sfRound(const SigFig aSigFig)  {
	SigFig numToReturn;
	double realValue = aSigFig.doubleValue();

	numToReturn.roundRealToSigFig(round(realValue), aSigFig.getNumSigFigs());
	return numToReturn;
}

SigFig sfExp(const SigFig exponent) {
	return exponent;
}

SigFig sfLn(const SigFig aSigFig) {
	return aSigFig;
}

SigFig sfLog(const SigFig base, const SigFig aSigFig) {
	return base;
}

SigFig sfPow(const SigFig base, const SigFig exponent) {
	return base;
}