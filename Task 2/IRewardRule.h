#pragma once

class IRewardRule
{
public:
    virtual ~IRewardRule() = default;

    virtual int computeReward(
        int baseScore,
        int round
    ) const = 0;
};