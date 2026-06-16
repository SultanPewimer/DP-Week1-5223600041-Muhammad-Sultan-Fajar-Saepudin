#include "BasicScoringRule.h"
#include "BonusRewardRule.h"
#include "RandomInputGenerator.h"
#include "RunSession.h"
#include "ShopSystem.h"

int main()
{
    RandomInputGenerator inputGenerator;
    BasicScoringRule scoringRule;
    BonusRewardRule rewardRule;
    ShopSystem shopSystem;

    RunSession session(
        inputGenerator,
        scoringRule,
        rewardRule,
        shopSystem
    );

    session.run();

    return 0;
}