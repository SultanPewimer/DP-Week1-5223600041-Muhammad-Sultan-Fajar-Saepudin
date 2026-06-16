#include "RandomInputGenerator.h"

#include <random>

RandomInputGenerator::RandomInputGenerator()
    : randomEngine(std::random_device{}()),
    valueDistribution(1, 10)
{
}

TurnInput RandomInputGenerator::generate()
{
    return TurnInput{
        valueDistribution(randomEngine)
    };
}