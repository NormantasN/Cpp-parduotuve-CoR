#include "fixeddiscount.hpp"
#include "basket.hpp"

fixedDiscount::fixedDiscount(float discount, float slenkstis) : Discount(slenkstis) {
    this->discount = discount;
}

float fixedDiscount::getDiscount() const {
    return discount;
}

void fixedDiscount::setDiscount(float discount) {
    this->discount = discount;
}

float fixedDiscount::countDiscount(Basket& basket) const {
    if (basket.fullPrice() > slenkstis) {
        if (nextDiscount != nullptr) {
            return nextDiscount->countDiscount(basket) - discount;
        } else {
            return basket.fullPrice() - discount;
        }
    }
    return basket.fullPrice();
}
