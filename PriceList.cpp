/*
 * PriceList.cpp
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
#include "PriceList.h"

class Invalid_DataFile_Exception : public exception{
    public:
        const char * what() const throw()
        {
            return " Input error: Data File read error or data file not found !!\n";
        }
};

const string PriceList::dataFileName = "product_list.txt";
PriceList::PriceList()
{
    try {
        inFile.open(dataFileName);
        if (!inFile) {
            Invalid_DataFile_Exception d;
            throw d;

        } else {
            string product_code;
            string name;
            double price;

            while (!inFile.eof())
            {
                inFile >> product_code >> name >> price;
                item_names.insert(make_pair(product_code, name));
                item_prices.insert(make_pair(product_code, price));
            }
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

bool PriceList::isValidItem(string item_code)
{
    map<string, string>::iterator itr = item_names.find(item_code);
    if ( itr != item_names.end())
        return true;
    else
        return false;
}

string PriceList::getItemName(string item_code)
{
    map<string, string>::iterator itr = item_names.find(item_code);
    if ( itr != item_names.end())
        return itr->second;
}

double PriceList::getItemPrice(string item_code)
{
    map<string, double>::iterator itr = item_prices.find(item_code);
    if (itr != item_prices.end())
        return itr->second;
}
