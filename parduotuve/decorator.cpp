#include "decorator.hpp"
#include "basket.hpp"

Decorator::Decorator(string category) : Discount() {
    this->category = category;
    discount = nullptr;
}

void Decorator::setDiscount(Discount* discount) {
    this->discount = discount;
}

float Decorator::countDiscount(Basket& basket) const {
    Basket tempBasket;
    for (const auto& item : basket.getBasket()) {
        if (item.getCategory() == category) {
            tempBasket.addItemsToBasket({item}, 1);
        }
    }

    if (discount != nullptr) {
        return discount->countDiscount(tempBasket);
    } else {
        return tempBasket.fullPrice();
    }
}
