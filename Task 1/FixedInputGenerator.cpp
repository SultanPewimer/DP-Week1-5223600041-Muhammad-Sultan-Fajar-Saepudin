#include "FixedInputGenerator.h"

FixedInputGenerator::FixedInputGenerator()
    : nextValue(1)
{
}

TurnInput FixedInputGenerator::generate()
{
    TurnInput input{ nextValue };

    ++nextValue;

    return input;
}