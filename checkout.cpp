#include "checkout.h"
#include "PriceList.h"
#include <math.h>

using namespace std;

class Invalid_Item_Exception : public exception{
    public:
        const char * what() const throw()
        {
            return " Input error: Invalid Item code or item out of stock. !!\n";
        }
};

Checkout::Checkout(Rules * pRules) : total_price(0.0), m_pRules(pRules) {}

void Checkout::scan(string itm)
{
    try {
        Item * item;
        PriceList *ptr = new PriceList();
        string name;
        double price;

        if (ptr->isValidItem(itm))
        {
            name = ptr->getItemName(itm);
            price = ptr->getItemPrice(itm);


            if(itm == "001") {
                item = new ChocolateCake(itm, name, price);
            } else if (itm == "002") {
                item = new Whisky(itm, name, price);
            } else if (itm == "003") {
                item = new Tshirt(itm, name, price);
            }
            basket.push_back(item);
        } else {
            Invalid_Item_Exception i;
            throw i;
        }
    }
    catch(exception& e) {
        cout << e.what() << endl;
    }

}

double Checkout::total(void)
{
    for (vector<class Item *>::iterator it = basket.begin(); it != basket.end(); ++it)
    {
        if (m_pRules->isItemOnOffer((*it)->getCode()))
        {
            int threshold = m_pRules->getItemThreshold((*it)->getCode());
            if ((*it)->getCount() >= threshold) {
                total_price += m_pRules->getDiscountedPrice((*it)->getCode());
            } else {
                total_price += (*it)->getPrice();
            }
        } else {
                total_price += (*it)->getPrice();
        }
    }

    if (total_price >= m_pRules->getDiscountThreshold())
            total_price = total_price - (total_price * (m_pRules->getPercentDiscountOnTotal()/100));

    total_price = floor( total_price * 100.00 + 0.5 ) / 100.00;

    return total_price;
}

void Checkout::display_basket(void)
{
    cout << "=======================================================" << endl;
    cout << setw(10) << " Item Code " << setw(20) << "Name" << setw(15) << "Unit Price" << endl;
    for (int i = 0; i < basket.size(); ++i) {
        cout << fixed << setprecision(2);
        cout << setw(10) << basket[i]->getCode() << setw(20) << basket[i]->getName() << setw(15) << basket[i]->getPrice() << endl;
    }
    cout << "=======================================================" << endl;
}

Checkout::~Checkout()
{
    for ( vector<class Item *>::iterator it = basket.begin(); it != basket.end(); ++it)
        delete (*it);
}
