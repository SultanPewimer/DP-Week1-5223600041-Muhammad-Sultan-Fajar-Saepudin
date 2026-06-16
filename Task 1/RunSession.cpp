#include "RunSession.h"

#include <iostream>

RunSession::RunSession(
    IInputGenerator& inputGenerator,
    const IScoringRule& scoringRule,
    const IRewardRule& rewardRule,
    const ShopSystem& shopSystem
)
    : inputGenerator(inputGenerator),
    scoringRule(scoringRule),
    rewardRule(rewardRule),
    shopSystem(shopSystem),
    money(0)
{
}

void RunSession::run()
{
    std::cout << "=== RUN START ===\n";

    for (int round = 1; round <= TotalRounds; ++round)
    {
        std::cout << "\nRound " << round << '\n';

        // Phase 1: Generate input
        const TurnInput input = inputGenerator.generate();

        std::cout << "[PLAY] input generated: "
            << input.value << '\n';

        // Phase 2: Compute base score
        const int baseScore =
            scoringRule.computeBaseScore(input);

        std::cout << "[SCORE] base score: "
            << baseScore << '\n';

        // Phase 3: Compute reward
        const int reward =
            rewardRule.computeReward(baseScore, round);

        // Phase 4: Update money
        money += reward;

        std::cout << "[REWARD] gain: "
            << reward
            << " | money: "
            << money
            << '\n';

        // Phase 5: Shop phase
        shopSystem.showOffer(money);

        // Phase 6: Advance round
        // The for-loop increment advances to the next round.
    }

    std::cout << "\n=== RUN END ===\n";
    std::cout << "Final money: " << money << '\n';
}