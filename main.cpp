#include <iostream>
#include <fstream>
#include <map>
#include "checkout.h"

using namespace std;

class Invalid_UserInput_Exception : public exception{
    public:
        const char * what() const throw()
        {
            return " error: Invalid choice, please enter your choice again !!\n";
        }
};

template <typename T>
T TakeUserInput()
{
    T ret;
    cin >> ret;

    if (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n')
            ;
        Invalid_UserInput_Exception d;
        throw d;
    }
    return ret;
}

int main()
{
    int option;
    Rules * pRules = new Rules();

    char ret = 'y';
    while (ret == 'y')
    {
        while (true)
        {
            cout << "=== Main Menu ===" << endl;
            cout << "Choose one of the following options " << endl;
            cout << "\t1. Select 1 to checkout " << endl;
            cout << "\t2. Select 2 to display the present discount rules " << endl;
            cout << "\t3. Select 3 to exit the checkout system" << endl;
            cout << " You choice: ";
            try
            {
                option = TakeUserInput<int>();
            }
            catch (exception& e)
            {
                cout << endl;
                cerr << e.what() << endl;
                continue;
            }
            break;
        }

        if (option == 1)
        {
            Checkout * co = new Checkout(pRules);
            char res = 'y';
            while (res == 'y')
            {
                string item;
                cout << "Please scan the items in your basket one by one. " << endl;
                cout << "Enter the item code " ;
                cin >> item;
                if (item.size() < 3) {
                    cout << " Invalid item code..." << endl;
                    cout << "Item code should be at least 3 characters long. e.g. 001, 002, 003 etc." << endl;
                    item.clear();
                    continue;
                }
                co->scan(item);
                cout << "Scan another item? (y/n) ";
                cin >> res;
            }
            co->display_basket();
            cout << fixed << setprecision(2);
            cout << setw(30) << "Total = " << setw(15) << co->total() << endl;
        } else if (option == 2) {
            pRules->displayRules();
        } else if (option == 3) {
            break;
        }
        while (true)
        {
            cout << "Return to main menu ? (y/n) ";
            try
            {
                ret = TakeUserInput<char>();
            }
            catch (exception& e)
            {
                cout << endl;
                cerr << e.what() << endl;
                continue;
            }
            break;
        }
    }

    delete pRules;

    return 0;
}
