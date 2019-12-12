#include <iostream>
#include "LList.h"

//----------------------------------------------------
//		constructor & destructor
//----------------------------------------------------
LList::LList() {  
	head =  NULL;
	cout << "LList: constructed!\n";
}

LList::~LList() {
	if (head != NULL)
		delete head;  // deletes each node using recursion
	cout << "LList: destructed!\n";
}

//----------------------------------------------------
//		         search
//----------------------------------------------------
// Given: key to search for
// Returns: pointer to a node in the list found to have
//          the given search key, or NULL for not found
//----------------------------------------------------
node * LList::search(int srchKey) {
	node * p = head;                      // p points to the head node
       	while (p != NULL) {
	       	if (p->key == srchKey)        // if p's node has key = searchKey
			return p;             // return pointer to node where its key = searchKey
		else
			p = p->next;          // point to the next thing
	}
	return NULL;                          // searchKey was not found in list or list was empty

} // search()

//----------------------------------------------------
//     		         findNode
//----------------------------------------------------
// Given: a key to search for
// Searches for a node with the given key, and if 
// found, invokes the print() method in the found node.
// Otherwise, prints "not found"
//----------------------------------------------------
void LList::findNode(int srchKey) {
	node * p;
	p = search(srchKey);  // will return a pointer to a node
			      // or NULL if node not found
	if (p != NULL)
		p->print();
	else
		cout << "not found\n";
} // findNode()

//----------------------------------------------------
//	        	 getb4
//----------------------------------------------------
// Given: a pointer to a node in the list
// Returns: returns a pointer to the thing who has a
// 	    pointer r, OR returns NULL when r is
// 	    the head or not found in the list
//----------------------------------------------------
node * LList::getb4(node * r) {
	if (r == head || head == NULL || r == NULL)
		return NULL;                    // if LList is empty, return NULL
						// if r=head, then no node is pointing to inputed node,
						// so return NULL as well. if node is not in list, return NULL as well!
	else {
		node * p = head;
		while (p != NULL) {
			if (p->next == r) 
				return p;       // pointer to the node such that node->next = r
			else
				p = p->next;    // p->next wasnt r. update p and try again.
		}
	}

	return NULL;                            // r not found. returning NULL
} // getb4()

//----------------------------------------------------
//		         insert
//----------------------------------------------------
// Given: key and data for a new node
// Purpose: Allocates/populates a new node
// When a node with the same key already exists:
//     the current/old node is replaced by the new one
//     and the old one is placed on the new one's 
//     duplicate list (it's NEXT should be set to NULL,
//     since it is no longer "in the list")
// Otherwise, the new node is prepended to the head
//     of the list.
//----------------------------------------------------
void LList::insert(int k, string d) {
	node * p = search(k);                      // returns pointer to node with node->key = k
						   // will return NULL if not found or empty list

	if (head == NULL) {
		node * newNode = new node(k, d);   // list was empty. make new node and prepend to list
		head = newNode;
		
	}
	else if (p == NULL) {
		node * newNode = new node(k, d);   // key not found in list and list not empty.
						   // prepend to current list.
		newNode->next = head;
		head = newNode;
	}
	else if (p == head) {
		node * newNode = new node(k,d);    // node with same key is the first node. make
						   // a stack with the curr node and replace with
						   // insert node. insert node will point to prev
						   // node with same key value.
		newNode->next = p->next;
		newNode->dup = p;
		p->next = NULL;
		head = newNode;
	}
	else {
		node * newNode = new node(k,d);    // same key value node inside but not top of list.
						   // make a stack with curr node and replace with
						   // insert node. insert node will point to prev node
						   // with same key value.
		newNode->next = p->next;
		newNode->dup = p;
		p->next = NULL;
		getb4(p)->next = newNode;
	}
} // insert()

//----------------------------------------------------
//	   	         remove
//----------------------------------------------------
// Given: a pointer to a node in the list to be removed
//        BUT NOT DELETED/DESTROYED
// Returns: TRUE - when the node was successfully removed
//          FALSE - when the given node is NULL or the node
//                  is not actually in the list.
// Simply removes the node from the linked list.
// (including setting the NEXT pointer in the node to NULL)
//----------------------------------------------------
bool LList::remove(node * r) {
	if (r == NULL)
		return false;                 // cannot remove a node that aint a node
	else if (r == head) {
		head = r->next;               // remove first node in list
		r->next = NULL;
		return true;
	}
	else if (search(r->key) != NULL) {
		node * before = getb4(r);     // remove node in middle of list
		before->next = r->next;
		r->next = NULL;
		return true;
	}
	else
		return false;                 // didnt end up removing anything
} // remove()

//----------------------------------------------------
//		         drop
//----------------------------------------------------
// Given: key of a node to drop
// Returns: TRUE when a node was found and deleted
//          FALSE when a node with the given key not found,
//                or the remove() fails.
// Searches for a node in the list with the given key:
// When found, removes and deletes the node
//----------------------------------------------------
bool LList::drop(int k) {
	node * dropNode;
	dropNode = search(k);                // will return node to drop or NULL if not in list or empty list
	if (dropNode == NULL)
		return false;                // cannot drop nothing

	bool didRemove = remove(dropNode);   // bool value to see if remove(dropNode) succeeded
	if (didRemove == true) {
		delete dropNode;             // delete dropNode
		return true;                 // successful drop
	}
	else
		return false;                // remove failed

} // drop()

//----------------------------------------------------
//		         max
//----------------------------------------------------
// Returns: a pointer to the node with the highest key
//          or NULL when there list is empty.
node * LList::max() {
	if (head == NULL)
		return NULL;                    // no max of an empty list
	else {
		node * p = head;
		int MAX = -100000;              // sentinal value to see if list has a max
		while (p != NULL) {
			if (p->key > MAX)
				MAX = p->key;   // update MAX
			p = p->next;            // try next node
		}
		if (MAX == -100000)
			return NULL;            // no MAX was found
		else
			return search(MAX);     // MAX was found. return node with key=MAX
	}
} // max()

//----------------------------------------------------
//		         sort
//----------------------------------------------------
// Sorts the list in ascending order by key values
void LList::sort() {
	if (head == NULL)
		return;   // cant sort an empty list
	else {
		node * t = NULL;
		node * m;
		while (head != NULL) {
			// Get max from LList. LList will never be empty when getting m (while() condition takes care of this)
			// Also, m != NULL since non-empty LList always has a max.
			m = max();
			
			if (m == head)
				head = m->next;             // head points to m. move the head to the node after m.
			else
				getb4(m)->next = m->next;   // a node points to m. move that node to point to m->next.
			
			m->next = t;   // t is current head of temporary list. make m point to what t points to.
			t = m;         // then make t point to m so m ends up prepending to our temporary list. 
		}
		head = t;              // t points to sorted list. so make head point to that list.
	}	                       // t is deallocated but list is sorted since we set head=t.
} // sort()

//----------------------------------------------------
//		         print
//----------------------------------------------------
// prints each node in the list, or EMPTY when there
// are no nodes to print
//----------------------------------------------------
void LList::print() {
	if (head == NULL)
		cout << "EMPTY\n\n";
	else {
		node * p = head;
		while (p != NULL) {
			p->print();
			p = p->next;
		}
		cout << endl;
	}
} // print()
