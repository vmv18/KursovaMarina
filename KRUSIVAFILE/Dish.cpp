#include "Dish.h"

Dish::Dish() : name("") {}

Dish::Dish(const std::string& name) : name(name) {}

void Dish::addIngredient(const Ingredient& ingredient) {
    ingredients.push_back(ingredient);
}

void Dish::removeIngredient(const std::string& ingredientName) {
    ingredients.erase(
        std::remove_if(ingredients.begin(), ingredients.end(),
            [&ingredientName](const Ingredient& ingredient) {
                return ingredient.getName() == ingredientName;
            }),
        ingredients.end());
}

double Dish::cost() const {
    double totalCost = 0;
    for (const auto& ingredient : ingredients) {
        totalCost += ingredient.cost();
    }
    return totalCost;
}

void Dish::printCostBreakdown() const {
    std::cout << "Cost breakdown for " << name << ":\n";
    for (const auto& ingredient : ingredients) {
        std::cout << std::setw(20) << ingredient.getName() << ": "
            << ingredient.cost() << " UAH\n";
    }
    std::cout << std::setw(20) << "Total cost" << ": "
        << cost() << " UAH\n";
}

std::string Dish::getName() const { return name; }

void Dish::printIngredients() const {
    std::cout << "Ingredients in " << name << ":\n";
    for (const auto& ingredient : ingredients) {
        std::cout << "- " << ingredient.getName() << '\n';
    }
}
    