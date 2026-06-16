add_executable(Task1
    main.cpp

    RunSession.cpp
    RunSession.h

    TurnInput.h

    IInputGenerator.h
    FixedInputGenerator.cpp
    FixedInputGenerator.h
    RandomInputGenerator.cpp
    RandomInputGenerator.h

    IScoringRule.h
    BasicScoringRule.cpp
    BasicScoringRule.h

    IRewardRule.h
    BasicRewardRule.cpp
    BasicRewardRule.h

    ShopSystem.cpp
    ShopSystem.h
)