#ifndef MARKET_HPP_INCLUDED
#define MARKET_HPP_INCLUDED

#include "discount.hpp"
#include "item.hpp"
#include "basket.hpp"
#include <vector>

class Market {
private:
    vector<Item> catalog;
    Discount* discount;

public:
    Market();

    void fillCatalog(vector<Item>& items);
    void setDiscount(Discount& disc);
    void addToCatalog(Item& item);
    float getPriceAfterDiscount(Basket& basket);
};



#endif // MARKET_HPP_INCLUDED
