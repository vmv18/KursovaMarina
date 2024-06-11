#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product();
    Product(const std::string& name, double pricePerKg);

    std::string getName() const;
    double getPricePerKg() const;

private:
    std::string name;
    double pricePerKg;
};

#endif // PRODUCT_H
