/*
 * PriceList.h
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

