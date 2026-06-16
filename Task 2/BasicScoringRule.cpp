#include "BasicScoringRule.h"

int BasicScoringRule::computeBaseScore(
    const TurnInput& input
) const
{
    return input.value;
}