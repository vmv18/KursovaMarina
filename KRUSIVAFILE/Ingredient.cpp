#include "Ingredient.h"

Ingredient::Ingredient(const Product& product, const Quantity& quantity)
    : product(product), quantity(quantity) {}

double Ingredient::cost() const {
    return (product.getPricePerKg() / 1000) * quantity.getGrams();
}

std::string Ingredient::getName() const { return product.getName(); }
