#include <iostream>
#include <vector>
#include <iomanip>
#include "Item.h"
#include "Rules.h"

using namespace std;

class Checkout {
private:
    vector<class Item *> basket;
    double total_price;
    Rules * m_pRules;
    ~Checkout();
public:
    Checkout(Rules * pRules);
    void scan(string itm);
    double total(void);
    void display_basket(void);
};

