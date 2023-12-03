#ifndef DISCOUNT_HPP_INCLUDED
#define DISCOUNT_HPP_INCLUDED

#include "basket.hpp"

class Discount {
protected:
    float slenkstis;
    Discount* nextDiscount;

public:
    Discount(float slenkstis);
    Discount(float slenkstis, Discount* nextDiscount);
    Discount();

    void setNextDiscount(Discount* discount);
    Discount* getNextDiscount() const;
    virtual float countDiscount(Basket& basket) const = 0;
};


#endif // DISCOUNT_HPP_INCLUDED
