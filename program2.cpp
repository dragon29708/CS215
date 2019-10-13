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

// describes a single item in the inventory, and a single item on an order
struct item {
        string prodCode;             // product code: length 12, no spaces
        string description;          // product description: max length 28, has spaces
        double price;                // price of the product, max 999.99
};

// describes a customer order or "basket"
const int MAX_ORDER_ITEMS = 5;
struct order {
        long orderNumber;            // unique order number for this order
        string custName;             // customer name
        double totalPrice;           // price of all items purchased
        item items[MAX_ORDER_ITEMS]; // list of items purchased
        int numItems;                // number of items purchased(1-5)};

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
