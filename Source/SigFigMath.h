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

SigFig sfExp(const SigFig aSigFig);

SigFig sfLn(const SigFig aSigFig);

SigFig sfLog(const int base, const SigFig aSigFig);

SigFig sfPow(const SigFig base, const SigFig exponent);

#endif