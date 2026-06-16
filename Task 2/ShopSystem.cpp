#include "ShopSystem.h"

#include <iostream>

void ShopSystem::showOffer(int money) const
{
    constexpr int offerCost = 2;

    std::cout << "[SHOP] offered: Bonus(+2) cost "
        << offerCost << '\n';

    if (money >= offerCost)
    {
        std::cout << "[SHOP] skipped\n";
    }
    else
    {
        std::cout << "[SHOP] skipped - not enough money\n";
    }
}