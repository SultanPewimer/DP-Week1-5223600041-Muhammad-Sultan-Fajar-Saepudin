#pragma once

#include "IRewardRule.h"

class BasicRewardRule : public IRewardRule
{
public:
    int computeReward(
        int baseScore,
        int round
    ) const override;
};