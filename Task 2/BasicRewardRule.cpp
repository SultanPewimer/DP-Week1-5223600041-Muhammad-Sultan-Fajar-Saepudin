#include "BasicRewardRule.h"

int BasicRewardRule::computeReward(
    int baseScore,
    int round
) const
{
    static_cast<void>(round);

    return baseScore;
}