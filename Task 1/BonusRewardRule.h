#pragma once

#include "IRewardRule.h"

class BonusRewardRule : public IRewardRule
{
public:
    int computeReward(
        int baseScore,
        int round
    ) const override;
};