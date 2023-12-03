#ifndef RELATIVEDISCOUNT_HPP_INCLUDED
#define RELATIVEDISCOUNT_HPP_INCLUDED

#include "discount.hpp"

class relativeDiscount : public Discount {
private:
    int percent;

public:
    relativeDiscount(int percent, float slenkstis);

    int getPercent() const;
    void setPercent(int percent);
    float countDiscount(Basket& basket) const;
};



#endif // RELATIVEDISCOUNT_HPP_INCLUDED
