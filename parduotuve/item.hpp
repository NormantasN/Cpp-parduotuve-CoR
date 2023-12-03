#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED

#include <string>
using namespace std;

class Item {
private:
    string title;
    string category;
    float price;

public:
    Item();
    Item(string title, string category, float price);

    string getTitle() const;
    string getCategory() const;
    float getPrice() const;

    void setTitle(string title);
    void setCategory(string category);
    void setPrice(float price);
};


#endif // ITEM_HPP_INCLUDED
