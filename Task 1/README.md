# Task 1 — Building a Balatro-Like Run

This project implements a simple three-round text-based run in C++. The program focuses on separating the invariant structure of the game loop from behaviors that can be replaced safely.

## Program Structure

The main components are:

* `RunSession`: controls the exact phase order for all three rounds
* `IInputGenerator`: defines how turn input is created
* `FixedInputGenerator`: original predictable input generator
* `RandomInputGenerator`: replacement generator that produces random values
* `IScoringRule`: defines how base score is calculated
* `BasicScoringRule`: calculates base score from `TurnInput`
* `IRewardRule`: defines how reward is calculated
* `BasicRewardRule`: original reward equal to base score
* `BonusRewardRule`: modified reward equal to base score plus two
* `ShopSystem`: prints a simple shop offer

## Invariant and Mutable Behavior Reflection

The invariant structure in this program is the phase order controlled by `RunSession::run()`. Every round must always generate input, compute the base score, compute the reward, update money, enter the shop phase, and then advance to the next round. This order is protected inside `RunSession` and is not changed when game behavior is modified.

The mutable parts are the input-generation, scoring, reward, and shop behaviors. These behaviors are separated into interfaces and concrete classes. For example, `FixedInputGenerator` can be replaced with `RandomInputGenerator`, while `BasicRewardRule` can be replaced with `BonusRewardRule`.

`RunSession` did not need to change when the input generator was replaced because it depends on the `IInputGenerator` interface instead of a specific concrete generator. Both implementations provide the same `generate()` function, so `RunSession` can use either object through the same abstraction.

If scoring logic were placed directly inside `RunSession`, changing the scoring formula would require editing the core loop. This would mix the invariant structure with mutable behavior, increase coupling, and make the program harder to test and extend. Separating the scoring rule keeps `RunSession` focused only on orchestration and preserves the required phase order.

## Build and Run

The project uses CMake and requires a C++17-compatible compiler.

From Visual Studio 2022:

```text
Ctrl + Shift + B
```

Run with:

```text
Ctrl + F5
```

The program runs exactly three rounds and prints the generated input, base score, reward, money update, shop phase, and final money.
