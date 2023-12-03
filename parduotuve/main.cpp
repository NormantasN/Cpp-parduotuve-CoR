#include "discount.hpp"
#include "item.hpp"
#include "basket.hpp"
#include "decorator.hpp"
#include "market.hpp"
#include "discountbyprice.hpp"
#include "fixeddiscount.hpp"
#include "relativediscount.hpp"
#include <vector>
#include <iostream>
using namespace std;


int main() {
    try{

    Market market;
    vector<Item> catalog;
    Basket basket;
    int itemCount = 6;
    float slenkstis = 40;
    float slenkstis1 = 40;
    float discount1 = 10;
    float discount2 = 5;
    int percent1 = 20;
    int percent2 = 10;
    float upperBound = 60;
    float lowerBound = 40;
    catalog.push_back(Item("Vistiena", "Mesa", 40.99));
    catalog.push_back(Item("Kiauliena", "Mesa", 30.50));
    catalog.push_back(Item("Limonadas", "Gerimai", 1.50));
    catalog.push_back(Item("Sultys", "Gerimai", 10.00));
    catalog.push_back(Item("Kukuruzai", "Javai", 20.00));
    catalog.push_back(Item("Ryziai", "Javai", 10.20));
    market.fillCatalog(catalog);

    fixedDiscount fDiscount1(discount1, slenkstis);
    fixedDiscount fDiscount2(discount2, slenkstis1);
    relativeDiscount rDiscount1(percent1, slenkstis);
    relativeDiscount rDiscount2(percent2, slenkstis1);

    basket.addItemsToBasket(catalog, itemCount);

    basket.print();
    // BE NUOLAIDOS
    cout << "Kaina be nuolaidos: " << basket.fullPrice() << endl;

    // SU FIKSUOTA NUOLAIDA
    market.setDiscount(fDiscount1);
    cout << "Kaina su fiksuota nuolaida: " << market.getPriceAfterDiscount(basket) << endl;

    // SU PROCENTINE NUOLAIDA
    market.setDiscount(rDiscount1);
    cout << "Kaina su procentine nuolaida: " << market.getPriceAfterDiscount(basket) << endl;

    // CoR testavimas

    // 1 chain
    fDiscount1.setNextDiscount(&fDiscount2);
    fDiscount2.setNextDiscount(&rDiscount1);
    rDiscount1.setNextDiscount(&rDiscount2);
    rDiscount2.setNextDiscount(nullptr);

    market.setDiscount(fDiscount1);
    cout << "Kaina su nuolaida (chain 1): " << market.getPriceAfterDiscount(basket) << endl;


    fDiscount1.setNextDiscount(nullptr);
    fDiscount2.setNextDiscount(nullptr);
    rDiscount1.setNextDiscount(nullptr);


    // 2 chain
    rDiscount1.setNextDiscount(&fDiscount1);
    fDiscount1.setNextDiscount(&fDiscount2);
    fDiscount2.setNextDiscount(nullptr);

    market.setDiscount(rDiscount1);
    cout << "Kaina su nuolaida (chain 2): " << market.getPriceAfterDiscount(basket) << endl;

    // NUOLAIDA KONKRECIAI KATEGORIJAI
    rDiscount1.setNextDiscount(nullptr);
    fDiscount1.setNextDiscount(nullptr);


    Decorator discountCategory("Mesa");


    // 3 chain
    discountCategory.setDiscount(&fDiscount1);
    fDiscount1.setNextDiscount(&rDiscount1);
    rDiscount1.setNextDiscount(&fDiscount2);


    market.setDiscount(discountCategory);

    cout << "Kaina konkrecios kategorijos prekiu pritaikius joms nuolaida (chain 3): " << market.getPriceAfterDiscount(basket) << endl;


    // NUOLAIDA PREKEI PAGAL PREKES KAINA
    rDiscount1.setNextDiscount(nullptr);
    fDiscount1.setNextDiscount(nullptr);

    discountByPrice priceDiscount(upperBound, lowerBound);

    // 4 chain
    priceDiscount.setDiscount(&fDiscount1);
    fDiscount1.setNextDiscount(&rDiscount1);
    rDiscount1.setNextDiscount(&fDiscount2);


    market.setDiscount(priceDiscount);

    cout << "Kaina su pritaikyta nuolaida pagal prekes kaina (chain 4): " << market.getPriceAfterDiscount(basket) << endl;



}
        catch (const invalid_argument &ex){
            cerr << "Ouch:" << endl;
            cerr << ex.what() << endl;
        }

    return 0;
}
