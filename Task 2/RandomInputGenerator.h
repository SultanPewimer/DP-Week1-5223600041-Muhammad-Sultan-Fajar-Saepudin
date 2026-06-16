#pragma once

#include <random>

#include "IInputGenerator.h"

class RandomInputGenerator : public IInputGenerator
{
public:
    RandomInputGenerator();

    TurnInput generate() override;

private:
    std::mt19937 randomEngine;
    std::uniform_int_distribution<int> valueDistribution;
};