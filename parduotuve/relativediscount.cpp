#include "relativediscount.hpp"
#include "basket.hpp"

relativeDiscount::relativeDiscount(int percent, float slenkstis) : Discount(slenkstis) {
    this->percent = percent;
}

int relativeDiscount::getPercent() const {
    return percent;
}

void relativeDiscount::setPercent(int percent) {
    this->percent = percent;
}

float relativeDiscount::countDiscount(Basket& basket) const {
    float percDiscount = basket.fullPrice() * percent / 100;
    if (basket.fullPrice() > slenkstis) {
        if (nextDiscount != nullptr) {
            return nextDiscount->countDiscount(basket) - percDiscount;
        } else {
            return basket.fullPrice() - percDiscount;
        }
    }
    return basket.fullPrice();
}

