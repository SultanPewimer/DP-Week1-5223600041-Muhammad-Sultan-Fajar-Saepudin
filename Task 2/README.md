# Task 2 — Develop Your Own Core Loop

## Game Concept: Card-Run Score Game

My game is a simple text-based card-run game. The player completes exactly three rounds. In each round, the program generates an input value, calculates a base score, calculates a reward, updates the player's money, displays a shop offer, and advances to the next round.

The focus of this project is not complex gameplay. The focus is separating the fixed core-loop structure from mechanics that may change later.

---

## Step 1 — Core Loop

The core loop of the game is:

1. Generate a turn input
2. Calculate the base score from the generated input
3. Calculate the reward from the base score
4. Update the player's money
5. Display the shop phase
6. Advance to the next round
7. Repeat until three rounds are completed
8. Display the final money

This sequence is executed by `RunSession::run()`.

---

## Step 2 — Invariant Identification

The following phase order must never change:

1. Input generation
2. Base-score calculation
3. Reward calculation
4. Money update
5. Shop phase
6. Round advancement

The input must be generated before the score can be calculated. The score must exist before the reward can be calculated. The reward must be known before the money value can be updated. The shop must receive the latest money value, so it must occur after the reward phase and money update.

If the order changes, the game state may become invalid. For example, calculating the score before generating input would mean that the scoring system has no value to process. Opening the shop before updating money would display an outdated balance. Updating money before calculating the reward would make the program unable to determine the correct amount to add.

### Required Components

The game must always have:

1. A `RunSession`
2. An `IInputGenerator`
3. A concrete input generator
4. An `IScoringRule`
5. A concrete scoring rule
6. An `IRewardRule`
7. A concrete reward rule
8. A `ShopSystem`
9. Money state
10. A round counter

`RunSession` is responsible for protecting the phase order. The other classes are responsible for the behavior inside each phase.

---

## Step 3 — Mutable Elements

### 1. Input-generation behavior

The input generator can be changed without changing the core loop. The program currently uses `RandomInputGenerator`, but another generator could produce fixed, weighted, or difficulty-based values.

### 2. Score formula

`BasicScoringRule` controls how the base score is calculated from `TurnInput`. The formula may be changed to include multipliers, bonuses, card combinations, or difficulty scaling.

### 3. Reward formula

`BonusRewardRule` currently returns the base score plus two. This formula can be replaced with another reward calculation without changing the phase order.

### 4. Shop offer

The shop item name, price, and effect can change. The shop phase still remains after the money update.

### 5. Numeric parameters

The random-value range, bonus amount, item cost, and total reward values are mutable because changing them affects balance rather than the structure of the loop.

These elements are mutable because they change the result of a phase, but they do not change when that phase occurs.

---

## Step 4 — C++ Core Loop Skeleton

### File Structure

```text
Task2/
├── CMakeLists.txt
├── main.cpp
├── TurnInput.h
├── IInputGenerator.h
├── FixedInputGenerator.h
├── FixedInputGenerator.cpp
├── RandomInputGenerator.h
├── RandomInputGenerator.cpp
├── IScoringRule.h
├── BasicScoringRule.h
├── BasicScoringRule.cpp
├── IRewardRule.h
├── BasicRewardRule.h
├── BasicRewardRule.cpp
├── BonusRewardRule.h
├── BonusRewardRule.cpp
├── ShopSystem.h
├── ShopSystem.cpp
├── RunSession.h
├── RunSession.cpp
└── README.md
```

### Core Loop

The core loop is implemented in `RunSession::run()`:

```cpp
void RunSession::run()
{
    std::cout << "=== CARD RUN START ===\n";

    for (int round = 1; round <= TotalRounds; ++round)
    {
        std::cout << "\nRound " << round << '\n';

        const TurnInput input = inputGenerator.generate();

        const int baseScore =
            scoringRule.computeBaseScore(input);

        const int reward =
            rewardRule.computeReward(baseScore, round);

        money += reward;

        shopSystem.showOffer(money);

        if (round < TotalRounds)
        {
            std::cout << "[ROUND] advancing to next round\n";
        }
        else
        {
            std::cout << "[ROUND] final round completed\n";
        }
    }

    std::cout << "\n=== CARD RUN END ===\n";
    std::cout << "Final money: " << money << '\n';
}
```

The complete program also prints a clear log for each phase.

---

## Explanation of Architectural Discipline

1. `RunSession` controls the core-loop order.
2. `IInputGenerator` separates input creation from the session.
3. `RandomInputGenerator` owns the random-generation behavior.
4. `IScoringRule` separates the score formula from the session.
5. `BasicScoringRule` calculates the base score.
6. `IRewardRule` separates reward behavior from the session.
7. `BonusRewardRule` calculates the modified reward.
8. `ShopSystem` handles the shop phase.
9. `main.cpp` only creates and connects the required objects.
10. Mutable mechanics can change without rearranging the core loop.

For example, changing `BonusRewardRule` does not require changing the score phase, shop phase, or round order.

---

## Final Reflection

The invariant structure of my game is the ordered sequence executed during every round: generate input, calculate the base score, calculate the reward, update money, display the shop, and advance the round. This sequence is controlled by `RunSession::run()` and must remain stable because every phase depends on information produced by an earlier phase. Input generation must occur before scoring because the scoring rule requires a `TurnInput`. Reward calculation must occur after scoring because it uses the base score. The money update must happen after the reward is known, while the shop must receive the latest money value.

The mutable parts of the program are the input-generation method, scoring formula, reward formula, shop content, and numeric parameters. `RandomInputGenerator` could be replaced with a fixed or weighted generator. `BasicScoringRule` could use a multiplier or a more complex card-combination formula. `BonusRewardRule` could provide different bonuses depending on the round. The shop offer and cost could also be changed without affecting the loop structure.

If I wanted to add a new input-generation behavior, I would create another class that implements `IInputGenerator` and select it in `main.cpp`. A new score formula would be implemented through another `IScoringRule` class. A different reward system would use another `IRewardRule` implementation. A new shop offer would mainly change `ShopSystem`. These features should not require rearranging the phases inside `RunSession`.

Changing the loop order could cause incorrect or inconsistent results. Calculating a score before generating input would leave the scoring rule without valid data. Updating money before calculating a reward would make the update impossible. Displaying the shop before updating money would show an outdated balance. Advancing the round before the shop phase could skip part of the game cycle. Separating the responsibilities into different classes protects the invariant structure and makes the system easier to modify, test, and understand.

---

## Build and Run

The project uses CMake and requires a C++17-compatible compiler.

In Visual Studio 2022, select `Task2.exe` as the startup item.

Build with:

```text
Ctrl + Shift + B
```

Run with:

```text
Ctrl + F5
```

The program should execute exactly three rounds and display all phases followed by the final money value.
