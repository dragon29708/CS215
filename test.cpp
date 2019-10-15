//----------------------------------------------------------------------------
//                               TEST.cpp
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

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
// Modifies: inventory list (sets number Of Items to -1 on READ ERROR)
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


int main() {
    // Variables.
    int numberOfInvItems = READ_ERROR;
    int numberOfOrders = READ_ERROR;
    int lastOrderNum  = READ_ERROR;
    string menuOption;
    string validOptions = "IOLX";

    // Inventory and orders arrays.
    item inv[MAX_INV_ITEMS];
    order orders[MAX_ORDERS];

    // Get inventory from inventory.txt.
    readInventory(inv, numberOfInvItems, lastOrderNum);

    displayInventory(inv, numberOfInvItems);

    // -------------------------------------------------------------------------------
    /*
    cout << "Input i: , expecting I, got: " << getMainOption() << endl;
    cout << "Input o: , expecting O, got: " << getMainOption() << endl;
    cout << "Input l: , expecting L, got: " << getMainOption() << endl;
    cout << "Input x: , expecting X, got: " << getMainOption() << endl;

    cout << "Input: I, expecting I, got: " << getMainOption() << endl;
    cout << "Input: O, expecting O, got: " << getMainOption() << endl;
    cout << "Input: L, expecting L, got: " << getMainOption() << endl;
    cout << "Input: X, expecting X, got: " << getMainOption() << endl;

    cout << "Input: j, expecting invalid, got: " << getMainOption() << endl;
    cout << "Input: asdf, expecting invalid, got: " << getMainOption() << endl;
    cout << "Input: cxvb, expecting invalid, got: " << getMainOption() << endl;
    cout << "Input: $^ dfg, expecting invalid, got: " << getMainOption() << endl;
    */
    // -------------------------------------------------------------------------------
}
