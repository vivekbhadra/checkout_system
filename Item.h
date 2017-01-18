/*
 * Item.h
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
using namespace std;

class Item {
protected:
    string code;
    string name;
    double price;
public:
    Item();
    Item (string c, string n, double p);
    double getPrice(void);
    string getCode(void);
    string getName(void);
    virtual int getCount(void);
    virtual ~Item();
};

class ChocolateCake : public Item {
private:
    static int counter;
public:
    ChocolateCake();
    ChocolateCake(string s, string n, double p);
    double getPrice(void);
    int getCount(void);
};

class Whisky : public Item {
private:
    static int counter;
public:
    Whisky();
    Whisky(string s, string n, double p);
    double getPrice(void);
    int getCount (void);
};

class Tshirt : public Item {
private:
    static int counter;
public:
    Tshirt();
    Tshirt(string s, string n, double p);
    double getPrice(void);
    int getCount(void);
};
