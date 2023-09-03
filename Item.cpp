#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(string name, double price, int quantity) { //creates an item
	itemName = name;
	itemPrice = price;
	itemQuantity = quantity;
}

void Item::setItemName(string name) { //sets the item name
	itemName = name;
}

void Item::setItemPrice(double price) { //sets the item price
	itemPrice = price;
}

void Item::setItemQuantity(int quantity) { //sets the item quantity
	itemQuantity = quantity;
}

string Item::getItemName() const { //returns item name
	return itemName;
}

double Item::getItemPrice() const { //returns item price
	return itemPrice;
}

int Item::getItemQuantity() const { //returns item quantity
	return itemQuantity;
}

void Item::outputItemInfo() { //outputs item information
	cout << "     " <<  itemName << " ";
	cout << itemQuantity << " @ ";
	cout << "$" << itemPrice << " = $";
	cout << itemQuantity * itemPrice << endl;
}

