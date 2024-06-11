#include "Product.h"

Product::Product() : name(""), pricePerKg(0.0) {}

Product::Product(const std::string& name, double pricePerKg)
    : name(name), pricePerKg(pricePerKg) {}

std::string Product::getName() const { return name; }
double Product::getPricePerKg() const { return pricePerKg; }
