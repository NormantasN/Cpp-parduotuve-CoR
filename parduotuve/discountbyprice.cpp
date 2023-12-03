#include "discountbyprice.hpp"
#include "basket.hpp"
#include <stdexcept>

discountByPrice::discountByPrice(float upperBound, float lowerBound) : Discount() {
    if (lowerBound > upperBound)
            throw invalid_argument("Price exceeds bounds");
    this->upperBound = upperBound;
    this->lowerBound = lowerBound;
}

void discountByPrice::setDiscount(Discount* discount) {
    this->discount = discount;
}

float discountByPrice::countDiscount(Basket& basket) const {
    Basket tempBasket;
    for (const auto& item : basket.getBasket()) {

        if (item.getPrice() >= lowerBound && item.getPrice() <= upperBound) {
            tempBasket.addItemsToBasket({item}, 1);
        }

    }

    if (discount != nullptr) {
        return discount->countDiscount(tempBasket);
    } else {
        return tempBasket.fullPrice();
    }
}

