#ifndef BASKET_HPP_INCLUDED
#define BASKET_HPP_INCLUDED


#include <vector>
#include "item.hpp"


class Basket {
private:
    vector<Item> basket;

public:
    Basket();

    float fullPrice() const;
    void addItemsToBasket(vector<Item> catalog, int count);
    const vector<Item>& getBasket() const;
    void print();
};


#endif // BASKET_HPP_INCLUDED
