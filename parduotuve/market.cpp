#include "market.hpp"

Market::Market() {
    discount = nullptr;
}

void Market::fillCatalog(vector<Item>& items) {
    catalog = items;
}

void Market::setDiscount(Discount& disc) {
    discount = &disc;
}

void Market::addToCatalog(Item& item) {
    catalog.push_back(item);
}

float Market::getPriceAfterDiscount(Basket& basket) {
    if (discount != nullptr) {
        return discount->countDiscount(basket);
    }
    return basket.fullPrice();
}
