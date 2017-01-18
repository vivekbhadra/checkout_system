/*
 * Rules.h
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
#include <map>

using namespace std;

class Rules {
private:
    map<string, int> discount_threshold_list;
    map<string, double> discounted_prices_list;
    double total_discount_threshold;
    double percent_discount_on_total;
public:
    Rules();
    void addIitem(string item, int threshold);
    void deleteItem(string item);
    bool isItemOnOffer(string item);
    int getItemThreshold(string item);
    double getDiscountedPrice(string item);
    void displayRules(void);
    double getDiscountThreshold(void);
    double getPercentDiscountOnTotal(void);
};
