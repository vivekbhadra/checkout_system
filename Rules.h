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
