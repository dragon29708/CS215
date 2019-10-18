/*
--------------------------------------------------------------------
                          CS215-401 Project 2
--------------------------------------------------------------------
Author: Andrew Cassidy
Date: 10/13/2019
Description: An app that allows customers to order items
from an inventory of products.
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
    for (int i = 0; i < validOptions.length(); i++) {
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
    cout << "Number of items in inventory: " << numberOfInvItems;
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
    displayList(basket.items);
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
    cin >> orders[numberOfOrders].custName;

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
bool orderItem(item inv[], int numberOfInvItems, order& basket) {
    // add orders to basket as long as basket isn't full
    while (basket.numItems <= MAX_ORDER_ITEMS) {
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

        // print out item being ordered
        cout << inv[userInput].description << " added to your basket. Current total is $" << setw(6) << setprecision(2) << fixed << right << basket.totalPrice << endl;
    }

    // user 
    return false;
    
} // orderItem()


//----------------------------------------------------------------------------
//                                 makeOrder
//----------------------------------------------------------------------------
// Given:
// Modifies:
// Returns:
//----------------------------------------------------------------------------
// makeOrder


//----------------------------------------------------------------------------
//                                 listOrders
//----------------------------------------------------------------------------
// Given:
// Modifies:
// Returns:
//----------------------------------------------------------------------------
// listOrders


//----------------------------------------------------------------------------
//                                 writeOrders
//----------------------------------------------------------------------------
// Given:
// Modifies:
// Returns:
//----------------------------------------------------------------------------
// writeOrders


//----------------------------------------------------------------------------
//                                 main
//----------------------------------------------------------------------------
// Given:
// Modifies:
// Returns: 0
//----------------------------------------------------------------------------
int main() {
    // Variables.
    int numberOfInvItems = -1;
    int numberOfOrders = -1;
    int lastOrderNum  = -1;
    string menuOption;
    string validOptions = "IOLX";

    // Inventory and orders arrays.
    item inv[MAX_INV_ITEMS];
    order orders[MAX_ORDERS];

    // Get inventory from inventory.txt.
    readInventory(inv, numberOfInvItems, lastOrderNum);

    // display the inventory
    displayInventory(inv, numberOfInvItems);

    // write out to file

    return 0;
    system("pause");
}
