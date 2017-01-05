#include "Rules.h"

Rules::Rules()
{
    string itm = "001";
    int threshold_dis = 2;
    discount_threshold_list.insert(make_pair(itm, threshold_dis));

    double dis_price = 8.5;
    discounted_prices_list.insert(make_pair(itm, dis_price));

    total_discount_threshold = 60.0;
    percent_discount_on_total = 10.0;
}

double Rules::getDiscountThreshold(void) {return total_discount_threshold;}
double Rules::getPercentDiscountOnTotal(void) {return percent_discount_on_total;}
void Rules::displayRules(void)
 {
    for(map<string, int>::iterator itr = discount_threshold_list.begin(); itr != discount_threshold_list.end(); ++itr)
        cout << " Item code " << itr->first << " has multiple discount benefit over purchase of " << itr->second << endl;

    for (map<string, double>::iterator itr = discounted_prices_list.begin(); itr != discounted_prices_list.end(); ++itr)
        cout << " Item code " << itr->first << " has a discounted price " << itr->second << " in multiple purchase " << endl;
 }
void Rules::addIitem(string item, int threshold)
{
    discount_threshold_list.insert(make_pair(item, threshold));
}

void Rules::deleteItem(string item)
{
    discount_threshold_list.erase(item);
}

bool Rules::isItemOnOffer(string item)
{
    map<string, int>::iterator itr = discount_threshold_list.find(item);
    if (itr != discount_threshold_list.end())
        return true;
    else
        return false;
}

int Rules::getItemThreshold(string item)
{
    map<string, int>::iterator itr = discount_threshold_list.find(item);
    if (itr != discount_threshold_list.end())
        return itr->second;
    else
        return 0;
}

double Rules::getDiscountedPrice(string item)
{
    map<string, double>::iterator itr = discounted_prices_list.find(item);
    if (itr != discounted_prices_list.end())
        return itr->second;
    else
        return 0;
}
