#ifndef QUANTITY_H
#define QUANTITY_H

class Quantity {
public:
    Quantity(double grams);

    double getGrams() const;

private:
    double grams;
};

#endif // QUANTITY_H
