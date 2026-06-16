# Design Pattern Weekly Assignments

This repository contains C++ assignments for the Design Pattern course. Both tasks use a simple text-based card-run game to demonstrate the difference between invariant structure and mutable game behavior.

## Repository Structure

```text
.
├── Task 1/
│   ├── source files
│   ├── CMakeLists.txt
│   └── README.md
│
├── Task2/
│   ├── source files
│   ├── CMakeLists.txt
│   └── README.md
│
├── CMakeLists.txt
└── README.md
```

## Task 1 — Building a Balatro-Like Run

Task 1 implements a three-round card-run loop with this fixed phase order:

1. Generate input
2. Compute base score
3. Compute reward
4. Update money
5. Enter the shop phase
6. Advance the round

The program separates mutable behavior into interfaces and concrete implementations:

* `IInputGenerator`
* `IScoringRule`
* `IRewardRule`

The original fixed input generator was replaced with `RandomInputGenerator` without changing `RunSession`. The original reward behavior was also replaced with `BonusRewardRule` without changing the core loop.

This task demonstrates how dependency abstraction protects invariant structure.

## Task 2 — Develop Your Own Core Loop

Task 2 reuses the same card-run game concept and focuses on identifying:

* The core gameplay loop
* Invariant phase order
* Required structural components
* Mutable mechanics
* Consequences of changing the loop order

The Task 2 program keeps the loop inside `RunSession` while delegating input generation, scoring, reward calculation, and shop behavior to separate classes.

The accompanying `README.md` explains the architecture and includes the required reflection.

## Main Classes

* `RunSession` — controls the round loop and phase order
* `TurnInput` — stores generated turn data
* `IInputGenerator` — abstraction for input generation
* `RandomInputGenerator` — generates random input values
* `IScoringRule` — abstraction for base-score calculation
* `BasicScoringRule` — calculates the base score
* `IRewardRule` — abstraction for reward calculation
* `BonusRewardRule` — gives a reward equal to the base score plus two
* `ShopSystem` — displays a simple shop offer

## Build Requirements

* C++17-compatible compiler
* CMake 3.20 or newer
* Visual Studio 2022 or another CMake-compatible environment

## Building in Visual Studio 2022

Open the repository root folder in Visual Studio.

Build with:

```text
Ctrl + Shift + B
```

Select the desired startup target:

```text
Task1.exe
```

or:

```text
Task2.exe
```

Run with:

```text
Ctrl + F5
```

## Author

* Name: Muhammad Sultan Fajar Saepudin
* NRP: 5223600041
