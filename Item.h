#ifndef __ITEM__
#define __ITEM__

#include <string>
using namespace std;

class Item {

public:
    //constructor for Item object
    Item(string name, double price, int quantity);

    // mutator methods for instance variables
    void setItemName(string name);
    void setItemPrice(double price);
    void setItemQuantity(int quantity);

    // accessor methods for instance variables
    string getItemName() const;
    double getItemPrice() const;
    int getItemQuantity() const;

    void outputItemInfo();

private:
    string itemName;
    double itemPrice;
    int itemQuantity;
};

#endif
