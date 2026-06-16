#include "BonusRewardRule.h"

int BonusRewardRule::computeReward(
    int baseScore,
    int round
) const
{
    static_cast<void>(round);

    return baseScore + 2;
}