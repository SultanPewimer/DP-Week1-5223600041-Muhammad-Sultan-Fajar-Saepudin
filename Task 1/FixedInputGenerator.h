#pragma once

#include "IInputGenerator.h"

class FixedInputGenerator : public IInputGenerator
{
public:
    FixedInputGenerator();

    TurnInput generate() override;

private:
    int nextValue;
};