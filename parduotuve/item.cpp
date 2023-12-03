#include "item.hpp"


Item::Item() {
    title = "";
    category = "";
    price = 0;
}

Item::Item(string title, string category, float price) {
    this->title = title;
    this->category = category;
    this->price = price;
}

string Item::getTitle() const {
    return title;
}

string Item::getCategory() const {
    return category;
}

float Item::getPrice() const {
    return price;
}

void Item::setTitle(string title) {
    this->title = title;
}

void Item::setCategory(string category) {
    this->category = category;
}

void Item::setPrice(float price) {
    this->price = price;
}
