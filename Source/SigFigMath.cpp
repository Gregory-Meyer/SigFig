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
	double significandToSet = (double) (sfLn(aSigFig) / sfLn(base));

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
		significandToSet = abs((double) base) * cos((double) exponent);
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