#include "discount.hpp"

Discount::Discount(float slenkstis) {
    this->slenkstis = slenkstis;
    nextDiscount = nullptr;
}

Discount::Discount(float slenkstis, Discount* nextDiscount) {
    this->slenkstis = slenkstis;
    this->nextDiscount = nextDiscount;
}

Discount::Discount() {
    slenkstis = 0;
    nextDiscount = nullptr;
}

void Discount::setNextDiscount(Discount* discount) {
    nextDiscount = discount;
}

Discount* Discount::getNextDiscount() const {
    return nextDiscount;
}
