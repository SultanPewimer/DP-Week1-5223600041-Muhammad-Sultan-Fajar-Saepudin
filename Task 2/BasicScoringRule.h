#pragma once

#include "IScoringRule.h"

class BasicScoringRule : public IScoringRule
{
public:
    int computeBaseScore(
        const TurnInput& input
    ) const override;
};