#ifndef DISH_H
#define DISH_H

#include "Ingredient.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>

class Dish {
public:
    Dish();
    Dish(const std::string& name);

    void addIngredient(const Ingredient& ingredient);
    void removeIngredient(const std::string& ingredientName);
    double cost() const;
    void printCostBreakdown() const;
    std::string getName() const;
    void printIngredients() const;

private:
    std::string name;
    std::vector<Ingredient> ingredients;
};

#endif // DISH_H
