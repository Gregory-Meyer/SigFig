#ifndef SIGFIGMATH_H
#define SIGFIGMATH_H

#include "SigFig.h"

// rounds SigFig object away from zero and returns the result
SigFig sfRoundUp(const SigFig aSigFig);

// rounds SigFig object towards zero and returns the result
SigFig sfRoundDown(const SigFig aSigFig);

// rounds SigFig object towards negative infinity and returns the resolt
SigFig sfFloor(const SigFig aSigFig);

// rounds SigFig object towards positive infinity and returns the result
SigFig sfCeil(const SigFig aSigFig);

// rounds SigFig object and returns the result
SigFig sfRound(const SigFig aSigFig);

// returns e^(exponent) with the result having the same number of significant
// figures as expnent
SigFig sfExp(const SigFig exponent);

// returns the real part of a^(aSigFig) with the result having the same number
// of significant figures as aSigFig
SigFig sfLn(const SigFig aSigFig);

// returns the real part of log(base, aSigFig) with the result having the same
// number of significant figures as either base or aSigFig, whichever is lower
SigFig sfLog(const SigFig base, const SigFig aSigFig);

// returns the real part of base^(exponent) with the result having the same
// number of significant figures as either base or aSigFig, whichever is lower
SigFig sfPow(const SigFig base, const SigFig exponent);

// returns the absolute value of aSigFig
SigFig sfAbs(const SigFig aSigFig);

#endif