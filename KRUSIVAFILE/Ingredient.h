#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "Product.h"
#include "Quantity.h"
#include <string>

class Ingredient {
public:
    Ingredient(const Product& product, const Quantity& quantity);

    double cost() const;
    std::string getName() const;

private:
    Product product;
    Quantity quantity;
};

#endif // INGREDIENT_H
