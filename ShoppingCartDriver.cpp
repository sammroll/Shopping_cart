// CS255
// P01 Shopping Cart
//		Simulates a shopping cart that contains items that will be purchased
// Samantha Roldan
//
#include <iostream>
#include "ShoppingCart.h"
using namespace std;

char getMenuChoice();
void processMenuChoice(char, ShoppingCart&);

int main() {
	string custName;
	char choice;

	cout << "**** Shopping Cart ****\n";
	cout << "\nEnter customer's name: ";
	getline(cin, custName);
	cout << "\nCustomer Name: " << custName;

	//creates a shopping cart with the customers name
	ShoppingCart currCart(custName);

	cout << "  Today's Date: " << currCart.getCurrentDate();
	cout << endl;
	choice = getMenuChoice();

	//checks to see if they didn't choose the option to quit and 
	//	does associated actions for that choice
	while (choice != 'q') {
		processMenuChoice(choice,currCart);
		choice = getMenuChoice();
	}

}

char getMenuChoice() {
	string menuOptions = "adcpstoq";
	char choice = ' ';

	//displays menu
	cout << endl;
	cout << "-- Online Shopping Menu --\n";
	cout << "    a - Add item to cart\n";
	cout << "    d - Remove item from cart\n";
	cout << "    c - Change item quantity\n";
	cout << "    p - Change item price\n";
	cout << "    o - Output shopping cart\n";
	cout << "    q - Quit\n";
	cout << "\n    Choose option: ";
	cin >> choice;

	//checks to see if the menu option chosen is a valid one
	while (menuOptions.find(choice) == string::npos) {
		cout << "Enter a valid option: ";
		cin >> choice;
	}

	return choice;
}

void processMenuChoice(char choice, ShoppingCart& theCart) {
	string name = "";
	double price = 0.0;
	int quantity = 0;
	
	switch (choice) {
	case 'a': //adds the item to the cart
		cout << "\n-- Add Item to Cart --";
		cout << endl;
		cout << "     Enter the item name: ";

		cin >> ws;
		getline(cin, name);
		cout << "     Enter the item price: ";
		cin >> price;
		cout << "     Enter the item quantity: ";
		cin >> quantity;

		theCart.addItemToCart(Item (name, price, quantity));

		break;
	
	case 'd': //deletes item from cart
		cout << "\n-- Remove Item from Cart --\n";
		cout << "     Enter name of item to remove: ";
		cin >> ws;
		getline(cin, name);
		
		theCart.removeItemFromCart(name);

		break;

	case 'c': //changes the item quantity
		cout << "\n-- Change Item Quantity --\n";
		cout << "     Enter the item name: ";
		cin >> ws;
		getline(cin, name);
		cout << "     Enter the new quantity: ";
		cin >> quantity;

		theCart.changeItemQuantity(name, quantity);

		break;

	case 'p': //changes the item price
		cout << "\n-- Change Item Price --\n";
		cout << "     Enter the item name: ";
		cin >> ws;
		getline(cin, name);
		cout << "     Enter the new price: ";
		cin >> price;

		theCart.changeItemPrice(name, price);

		break;

	case 'o': //displays cart info
		theCart.outputCartInfo();

		break;
	}
}
