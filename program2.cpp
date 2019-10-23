/*
--------------------------------------------------------------------
						  CS215-401 Project 2
--------------------------------------------------------------------
Author: Andrew Cassidy
Date: 10/13/2019
Description: An app that allows customers to order items
from an inventory of products.
Assistance: I received help from Spencer Eddins.
--------------------------------------------------------------------
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

const int READ_ERROR = -1;
const int MAX_INV_ITEMS = 10;

// describes a single item in the inventory, and on an order
struct item {
	string prodCode;        // product code: length 12, no spaces
	string description;     // product description: max length 28, has spaces
	double price;           // price of the product, max 999.99
};

const int MAX_ORDERS = 10;

// describes a customer order or "basket"
const int MAX_ORDER_ITEMS = 5;
struct order {
	long   orderNumber;             // unique order number for this order
	string custName;                // customer name
	double totalPrice;              // price of all items purchased
	item items[MAX_ORDER_ITEMS];    // list of items purchased
	int numItems;                   // number of items purchased
};


//----------------------------------------------------------------------------
//                             readInventory
//----------------------------------------------------------------------------
// Given: inventory array, number of inventory items, last order number.
// Modifies: inventory list (sets numberOfItems to -1 on READ ERROR)
//           lastOrderNum
// Returns:  inventory data from a file into an array of inventory items
//           number of inventory items
//           last order number
//----------------------------------------------------------------------------
void readInventory(item inv[], int& numberOfInvItems, int& lastOrderNum) {
	ifstream f;

	// open the inventory file
	f.open("inventory.txt");
	if (f.fail()) {
		cout << "readFile:: error opening inventory.txt\n";
		numberOfInvItems = READ_ERROR;
		return;
	}

	// read number of items from first line
	f >> numberOfInvItems >> lastOrderNum;

	// for each item, read the data for the item
	for (int i = 0; i < numberOfInvItems; i++) {
		f >> inv[i].prodCode >> inv[i].price;
		f.ignore(); // finished reading integer, getline() on string is next
		getline(f, inv[i].description);
	}
	f.close();
} // readInventory()


//----------------------------------------------------------------------------
//                                 isValidOption
//----------------------------------------------------------------------------
// Given: char option and string of valid char options.
// Modifies: nothing.
// Returns: true or false if option is valid or not.
//----------------------------------------------------------------------------
bool isValidOption(char option, string validOptions) {
	// Loop through validOptions string to validate option input.
	for (unsigned int i = 0; i < validOptions.length(); i++) {
		if (validOptions[i] == option)
			return true; // Return true if option is found in validOptions string.
	}

	return false; // option was not found in validOptions string.
} // isValidOption()


//----------------------------------------------------------------------------
//                                 getMainOption
//----------------------------------------------------------------------------
// Given: nothing.
// Modifies: nothing.
// Returns: the main menu option (a char: ’I’, ’O’, ’L’, or ’X’)
//----------------------------------------------------------------------------
char getMainOption() {
	string userInput;
	char option;
	string validOptions = "IOLX";

	// display logo and options.
	cout << "+------------------------------------------------------+\n";
	cout << "|                       AMOZON.COM                     |\n";
	cout << "|                    Andrew Cassidy                    |\n";
	cout << "+------------------------------------------------------+\n";
	cout << "I - List our Inventory\n";
	cout << "O - Make an Order\n";
	cout << "L - List all Orders made\n";
	cout << "X - Exit\n";

	// get option and its first char.
	cout << "Enter an option: ";
	if (cin.peek() == '\n')
		cin.ignore();  // just in case it’s needed
	getline(cin, userInput);
	option = toupper(userInput[0]);

	while (!isValidOption(option, validOptions)) {
		cout << "Invalid option, enter I, O, L, or X!\n";

		// get option again.
		cout << "Enter an option: ";
		if (cin.peek() == '\n')
			cin.ignore();  // just in case it’s needed
		getline(cin, userInput);
		option = toupper(userInput[0]);
	}

	return option;
} // getMainOption()


//----------------------------------------------------------------------------
//                                 displayList
//----------------------------------------------------------------------------
// Given: inventory list and number of items in inventory list.
// Modifies: nothing
// Returns: nothing
//----------------------------------------------------------------------------
void displayList(item inv[], int numberOfInvItems) {
	// print out items in list.
	for (int i = 0; i < numberOfInvItems; i++) {
		cout << setw(3) << right << i << "  ";
		cout << setw(12) << left << inv[i].prodCode << "  $";
		cout << setw(6) << right << setprecision(2) << fixed << inv[i].price << "  ";
		cout << inv[i].description << endl;
	}
} // displayList()


//----------------------------------------------------------------------------
//                                 displayInventory
//----------------------------------------------------------------------------
// Given: inventory and number of items in inventory.
// Modifies: nothing
// Returns: nothing
//----------------------------------------------------------------------------
void displayInventory(item inv[], int numberOfInvItems) {
	// display inventory logo
	cout << "+------------------------------------------------------+\n";
	cout << "|                        Products                      |\n";
	cout << "+------------------------------------------------------+\n";
	cout << " #   PRODUCT CODE   PRICE   PRODUCT DESCRIPTION         \n";
	cout << "---  ------------  -------  ----------------------------\n";
	displayList(inv, numberOfInvItems);
	cout << "Number of items in inventory: " << numberOfInvItems << endl;
} // displayInventory()


//----------------------------------------------------------------------------
//                                 displayOrder
//----------------------------------------------------------------------------
// Given: basket
// Modifies: nothing
// Returns: nothing
//----------------------------------------------------------------------------
void displayOrder(order basket) {
	// display order number and customer name.
	cout << "Order Number: " << basket.orderNumber << "   " << basket.custName << endl;

	// display orders made by individual customer.
	displayList(basket.items, basket.numItems);

	// display total of single basket
	cout << "Total              $" << setw(6) << setprecision(2) << right << basket.totalPrice << endl;

} // displayOrder()


//----------------------------------------------------------------------------
//                                 startOrder
//----------------------------------------------------------------------------
// Given: nothing
// Modifies: partial array of orders and the last order number
// Returns: nothing
//----------------------------------------------------------------------------
void startOrder(order orders[], int& numberOfOrders, int& lastOrderNum) {
	// increment lastOrderNum for new person.
	lastOrderNum++;

	// populate a new order for a new person.
	orders[numberOfOrders].orderNumber = lastOrderNum;
	orders[numberOfOrders].numItems = 0;
	orders[numberOfOrders].totalPrice = 0;

	// print order number, get name.
	cout << "Order Number:        " << orders[numberOfOrders].orderNumber << endl;
	cout << "Enter customer name: ";
	getline(cin, orders[numberOfOrders].custName);

	// increment number of orders.
	numberOfOrders++;
} // startOrder()


//----------------------------------------------------------------------------
//                                 orderItem
//----------------------------------------------------------------------------
// Given: inventory partial array and number of items in array
// Modifies: a single basket
// Returns: true or false
//----------------------------------------------------------------------------
bool orderItem(item inv[], int numberOfInvItems, order & basket) {
	// asking what the user wants to order
	int userInput = 0;
	cout << "Enter an item number (-1 to end): "; cin >> userInput;

	// if -1 then exit and return true
	if (userInput == -1)
		return true;

	// input validation
	while (userInput < -1 || userInput >= numberOfInvItems) {
		cout << "Invald entry. Enter number -1 to " << numberOfInvItems - 1 << endl;
		cout << "Enter an item number (-1 to end): "; cin >> userInput;

		// if -1 then exit and return true
		if (userInput == -1)
			return true;
	}

	if (basket.numItems < MAX_ORDER_ITEMS) {
		// throw item from decision into basket
		basket.items[basket.numItems] = inv[userInput];
		basket.numItems++;
		basket.totalPrice += inv[userInput].price;
	}
	else {
		cout << "Sorry, the max number of items per order is " << MAX_ORDER_ITEMS << endl;
		return true;
	}

	// print out item being ordered
	cout << inv[userInput].description << " added to your basket. Current total is $" << setw(6) << setprecision(2) << fixed << right << basket.totalPrice << endl;
	return false;

} // orderItem()


//----------------------------------------------------------------------------
//                                 makeOrder
//----------------------------------------------------------------------------
// Given: inventory partial array and number of items in inventory.
// Modifies: order partial array and number of orders in it, last order number
// Returns: nothing
//----------------------------------------------------------------------------
void makeOrder(order orders[], int& numberOfOrders, item inv[], int numberOfInvItems, int& lastOrderNum) {
	if (numberOfOrders >= MAX_ORDERS) {
		cout << "Sorry, we can not take more orders today.\n\n";
	}
	else {
		startOrder(orders, numberOfOrders, lastOrderNum);
		displayInventory(inv, numberOfInvItems);

		// iterate over the max items in an order and make sure orderItem() isnt true (asked to leave)
		for (int i = 0; i <= MAX_ORDER_ITEMS && !orderItem(inv, numberOfInvItems, orders[numberOfOrders - 1]); i++) {
			if (i >= MAX_ORDER_ITEMS)
				cout << "Sorry, the max number of items per order is " << MAX_ORDER_ITEMS << endl;
		}
	}

	cout << "Thank you for your order!\n";
	displayOrder(orders[numberOfOrders - 1]);
} // makeOrder()


	//----------------------------------------------------------------------------
	//                                 listOrders
	//----------------------------------------------------------------------------
	// Given: partial array of orders
	// Modifies: nothing
	// Returns: nothing
	//----------------------------------------------------------------------------
void listOrders(order orders[], int numberOfOrders) {
	// display inventory logo
	cout << "+------------------------------------------------------+\n";
	cout << "|                        Orders                        |\n";
	cout << "+------------------------------------------------------+\n";

	// diplay all the orders
	for (int i = 0; i < numberOfOrders; i++) {
		displayOrder(orders[i]);
	}

	// display total number of orders
	cout << "Total Number of Orders = " << numberOfOrders << endl << endl;
} // listOrders()


//----------------------------------------------------------------------------
//                                 writeOrders
//----------------------------------------------------------------------------
// Given: partial array of orders and number of orders
// Modifies: nothing
// Returns: nothing
//----------------------------------------------------------------------------
void writeOrders(order orders[], int numberOfOrders) {
	ofstream f;
	f.open("orders.txt");

	// first line write the number of orders
	f << numberOfOrders << endl;

	// output orders and their indivual baskets
	for (int i = 0; i < numberOfOrders; i++) {
		// for each order
		f << orders[i].orderNumber << " ";
		f << orders[i].numItems << " ";
		f << orders[i].totalPrice << " ";
		f << orders[i].custName << " ";
		f << endl;

		// for each item within an order
		for (int j = 0; j < orders[i].numItems; j++) {
			f << orders[i].items[j].prodCode << " ";
			f << orders[i].items[j].price << " ";
			f << orders[i].items[j].description;
			f << endl;
		}
	}

	// close file
	f.close();
}


//----------------------------------------------------------------------------
//                                 main
//----------------------------------------------------------------------------
// Given: nothing
// Modifies: everything
// Returns: 0
//----------------------------------------------------------------------------
int main() {
	// variables
	int numberOfInvItems = READ_ERROR;
	int numberOfOrders = 0;
	int lastOrderNum = READ_ERROR;
	string menuOption;

	// inventory and orders arrays
	item inv[MAX_INV_ITEMS];
	order orders[MAX_ORDERS];

	// get inventory from inventory.txt
	readInventory(inv, numberOfInvItems, lastOrderNum);

	while (menuOption != "X") {
		// get main option
		menuOption = getMainOption();

		if (menuOption == "I") {
			// display the inventory
			displayInventory(inv, numberOfInvItems);
		}
		else if (menuOption == "O") {
			// make order
			makeOrder(orders, numberOfOrders, inv, numberOfInvItems, lastOrderNum);
			system("pause");
		}
		else if (menuOption == "L") {
			// list orders made
			listOrders(orders, numberOfOrders);
		}
	}

	// write out to file
	writeOrders(orders, numberOfOrders);

	system("pause");
	return 0;
}
