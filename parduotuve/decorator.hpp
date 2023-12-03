#ifndef DECORATOR_HPP_INCLUDED
#define DECORATOR_HPP_INCLUDED

#include "discount.hpp"
#include <string>

class Decorator : public Discount {
private:
    string category;
    Discount* discount;

public:
    Decorator(string category);

    void setDiscount(Discount* discount);
    float countDiscount(Basket& basket) const;
};


#endif // DECORATOR_HPP_INCLUDED
