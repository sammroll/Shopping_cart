
#include <iostream>
#include "ShoppingCart.h"
#include "DateUtility.h"
using namespace std;

ShoppingCart::ShoppingCart(string name) { //creates shopping cart info
	customerName = name;
	currentDate = getDateString();
}

string ShoppingCart::getCustomerName() const { //returns customerName value
	return customerName;
}

string ShoppingCart::getCurrentDate() const {	//returns currentDate value
	return currentDate;
}

int ShoppingCart::getItemCount() const { //returns number of items in cart
	int count = 0;
	int i;

	for (i = 0; i < cart.size(); ++i) {
		count = count + cart.at(i).getItemQuantity();
	}

	return count;
}

int ShoppingCart::findItemInCart(string name) { //return index of item in cart
	int i;

	for (i = 0; i < cart.size(); i++) {
		if (cart.at(i).getItemName() == name) {
			break;
		}
	}

	return i;
}

void ShoppingCart::addItemToCart(Item item) { //adds an item to the cart
	if (findItemInCart(item.getItemName()) == cart.size()) {
		cart.push_back(item);
		cout << "\n     >>> Item " << item.getItemName() << " added to cart <<<\n";
	}
	else {
		cout << "\n     >>> Item " << item.getItemName() << " already in cart << <\n";
	}
}

void ShoppingCart::changeItemQuantity(string name, int quantity) { //changes the item quantity
	if (findItemInCart(name) == cart.size()) {
		cout << "\n     >> > Item " << name << " not in cart << <\n";
	}
	else {
		cart.at(findItemInCart(name)).setItemQuantity(quantity);
		cout << "\n     >>> Item " << name << " quantity changed to " << quantity << " <<<\n";
	}
}

void ShoppingCart::changeItemPrice(string name, double price) { //changes the item's price
	if (findItemInCart(name) == cart.size()) {
		cout << "\n     >>> Item " << name << " not in cart <<<\n";
	}
	else {
		cart.at(findItemInCart(name)).setItemPrice(price);
		cout << "\n     >>> Item " << name << " price changed to $" << price << " <<<\n";
	}
}

void ShoppingCart::removeItemFromCart(string name) { //removes an item from cart
	if (findItemInCart(name) == cart.size()) {
		cout << "\n     >>> Item " << name << " not in cart <<<\n";
	}
	else {
		cart.erase(cart.begin() + findItemInCart(name));
		cout << "\n     >>> Item " << name << " removed from cart <<<\n";
	}
}

void ShoppingCart::outputCartInfo() { //outputs the cart information
	double totalItemCost = 0.0;
	double totalCartCost = 0.0;
	int i;

	cout << "\n-- Output Shopping Cart --\n";
	cout << "     " << customerName << "'s Shopping Cart - " << currentDate << endl;

	cout << "\n     Number of Items: " << getItemCount() << endl;
	cout << "     ---------------------\n";

	if (cart.size() == 0) {
		cout << "\n     >>> Shopping Cart is empty <<<\n";
	}
	else {
		for (i = 0; i < cart.size(); ++i) {
			cart.at(i).outputItemInfo();

			totalItemCost = cart.at(i).getItemQuantity() * cart.at(i).getItemPrice();
			totalCartCost = totalCartCost + totalItemCost;

		}

		cout << "\n     Total: $" << totalCartCost << endl;
	}

	
}


