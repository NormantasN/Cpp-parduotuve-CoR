#ifndef FIXEDDISCOUNT_HPP_INCLUDED
#define FIXEDDISCOUNT_HPP_INCLUDED

#include "discount.hpp"

class fixedDiscount : public Discount {
private:
    float discount;

public:
    fixedDiscount(float discount, float slenkstis);

    float getDiscount() const;
    void setDiscount(float discount);
    float countDiscount(Basket& basket) const;
};



#endif // FIXEDDISCOUNT_HPP_INCLUDED
