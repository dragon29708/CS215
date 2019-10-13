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

const int READ_ERROR    = -1;
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
    long   orderNumber;     // unique order number for this order
    string custName;        // customer name
    double totalPrice;      // price of all items purchased
    item items[MAX_ORDER_ITEMS];    // list of items purchased
    int numItems;           // number of items purchased
};

//----------------------------------------------------------------------------
//                                  readInventory
//----------------------------------------------------------------------------
// Modifies: inventory list (sets numberOfItems to -1 on READ ERROR)
//           lastOrderNum
// Reads inventory data from a file into an array of inventory items
//----------------------------------------------------------------------------
void readInventory(item inv[], int & numberOfInvItems, int & lastOrderNum) {
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

// Max amount of items in inventory.
const int MAX_INV_ITEMS = 10;

// readInventory
// getMainOption
// isValidOption
// displayInventory
// displayList
// makeOrder
// startOrder
// listOrders
// writeOrders
// displayOrder
// orderItem

int main() {
        long lastOrderNumber;
        string menuOption;
        // Inventory
        return 0;
        system("pause");
}
