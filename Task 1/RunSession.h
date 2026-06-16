#pragma once

#include "IInputGenerator.h"
#include "IRewardRule.h"
#include "IScoringRule.h"
#include "ShopSystem.h"

class RunSession
{
public:
    RunSession(
        IInputGenerator& inputGenerator,
        const IScoringRule& scoringRule,
        const IRewardRule& rewardRule,
        const ShopSystem& shopSystem
    );

    void run();

private:
    static constexpr int TotalRounds = 3;

    IInputGenerator& inputGenerator;
    const IScoringRule& scoringRule;
    const IRewardRule& rewardRule;
    const ShopSystem& shopSystem;

    int money;
};