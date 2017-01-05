#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class PriceList {
private:
    map<string, string> item_names;
    map<string, double> item_prices;
    ifstream inFile;
    static const string dataFileName;
public:
    PriceList();
    string getItemName(string item_code);
    double getItemPrice(string item_code);
    bool isValidItem(string item_code);
};

