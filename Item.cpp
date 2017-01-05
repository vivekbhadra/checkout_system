#include <iostream>
#include "Item.h"
using namespace std;

Item::Item()
{
    code = "";
    name = "";
    price = 0.0;
}

Item::Item (string c, string n, double p)
{
    code = c;
    name = n;
    price = p;
}
double Item::getPrice(void)
{
    return price;
}

string Item::getName(void)
{
    return name;
}

string Item::getCode()
{
    return code;
}

int Item::getCount(void) { return 0; }
Item::~Item() {}

ChocolateCake::ChocolateCake()
{
    counter++;
}

ChocolateCake::ChocolateCake(string s, string n, double p) : Item(s, n, p)
{
    counter++;
}

double ChocolateCake::getPrice(void)
{
    return price;
}
int ChocolateCake::getCount(void) {return counter; }

int ChocolateCake::counter = 0;

Whisky::Whisky()
{
    counter++;
}
Whisky::Whisky(string s, string n, double p) : Item(s, n, p)
{
    counter++;
}
double Whisky::getPrice(void)
{
    return price;
}
int Whisky::getCount (void)
{
    return counter;
}

int Whisky::counter = 0;

Tshirt::Tshirt()
{
    counter++;
}
Tshirt::Tshirt(string s, string n, double p) : Item(s, n, p)
{
    counter++;
}
double Tshirt::getPrice(void)
{
    return price;
}
int Tshirt::getCount(void)
{
    return counter;
}
int Tshirt::counter = 0;
