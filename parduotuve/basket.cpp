#include "basket.hpp"

#include <iostream>


Basket::Basket() {}

float Basket::fullPrice() const {
    float price = 0;
    for (auto it = basket.begin(); it != basket.end(); ++it) {
        price += it->getPrice();
    }
    return price;
}

void Basket::addItemsToBasket(vector<Item> catalog, int count) {
    for (int i = 0; i < count; ++i) {
        basket.push_back(catalog[i]);
    }
}

const vector<Item>& Basket::getBasket() const {
    return basket;
}

void Basket::print() {
    cout << "-----Issirinktos prekes:" << endl;
    cout << "Pavadinimas " << "Kategorija " << "Kaina" << endl;
    for (auto it = basket.begin(); it != basket.end(); ++it) {
        cout << it->getTitle() << " " << it->getCategory() << " " << it->getPrice() << endl;
    }
    cout << endl;
}
