/*
 * checkout.h
 *
 * Copyright (C) 2017 Vivek Bhadra
 * Copyright (C) 2017 Embed Logic Limited
 *
 * The source code in this file can be freely used, adapted,
 * and redistributed in source or binary form, so long as an
 * acknowledgment appears in derived source files.  The citation
 * should list that the code comes from the public github of Vivek Bhadra 
 * No warranty is attached. We cannot take responsibility for 
 * errors or fitness for use.
 *
 */
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

