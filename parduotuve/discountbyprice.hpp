#ifndef DISCOUNTBYPRICE_HPP_INCLUDED
#define DISCOUNTBYPRICE_HPP_INCLUDED

#include "discount.hpp"

class discountByPrice : public Discount {
private:
    float upperBound;
    float lowerBound;
    Discount* discount;

public:
    discountByPrice(float upperBound, float lowerBound);

    void setDiscount(Discount* discount);
    float countDiscount(Basket& basket) const;
};


#endif // DISCOUNTBYPRICE_HPP_INCLUDED
