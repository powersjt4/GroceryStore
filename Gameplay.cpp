/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 8/4/17
 ** Description: The Gameplay class brings all the
 ** the grocery departments together and controls
 ** the various functions to create the game.
 ********************************************
 *************************/
#include "Gameplay.hpp"
#include "Spaces.hpp"
#include "Entry.hpp"
#include "Grocery.hpp"

/************************************************************
Gameplay::magicHpns()
This is where the magic happens. This is the primary function for
this class. It calls other functions and moves the game along.
This keeps track of the items and the counter when one of
those variables is within range of winning or losing the
primary while loop will drop out and the final round conditions
play out.
***********************************************************/

void Gameplay::magicHpns() {
	std::string specialStr = "";
	std::cout << "\033[2J\033[1;1H";
	current = grocery.getEntry();
	current->getText();
	cartSize = current->specialInt(0);
	if (cartSize > 11) { //Sets the counter based
		counter--;  // on cart size
	} else {counter++;}
	current->getDept();
	if (move(1) < 1) {return;} //Last minute fix to get rid of exit(1)
	while (counter > 0 && !checkCart()) {
		std::cout << "\033[2J\033[1;1H";
		cout << "Shopping list: ";
		printList();
		checkCart();
		cout << "\nCounter: " << counter << endl << endl;

		current->getText();
		addFromShelf();
		checkCart();
		specialStr = current->special();
		if (specialStr != "") {
			addItem(specialStr);
			specialStr = "";
		}
		counter = counter - current->specialInt(0);
		current->getDept();
		if (move(0) < 1) {return;} //Last minute fix to get rid of exit(1)
	}
	if (checkCart() && counter > 0) { //Final round initiated automatically goes to checkout.
		std::cout << "\033[2J\033[1;1H";
		cout << "You got all the items on the list you can now go to the checkout and leave.\n";
		cout << "Choose wisely each checkout takes more time off the counter." << endl;
		cout << "\nCounter: " << counter << endl << endl;
		current = grocery.getCheckout();
		counter = counter - current->specialInt(1);
		cout << "\nCounter: " << counter << endl << endl;
		if (counter > 0) {
			cout << "\n****####################################################################################***" << endl;
			cout << "****You got all the items on the list. Congrats! You still died of dysentery though.***" << endl;
			cout << "****####################################################################################***" << endl;
			return;
		}
	} else if (counter <= 0) { //Counter ran out player lost.
		cout << "\n****####################################################################################***" << endl;
		cout << "****			 You ran out of time and for some reason you died of dysentery. 		   ***" << endl;
		cout << "****####################################################################################***" << endl;
		return;
	}
}

/************************************************************
Gameplay::move(special move condtion)
Gets the move pointers from the Grocery class also checks
for nullptr (wall)
***********************************************************/
int Gameplay::move(int spec) {
	int sel;
	last = current;
	do {
		current = last;
		sel = validate.checkValid(true, 0, 4);
		switch (sel) {
		case 0: {
			return 0;
		}
		case 1: {
			current = current->top;
			break;
		}
		case 2: {
			current = current->left;
			break;
		}
		case 3: {
			current = current->bottom;
			if (spec == 1) { //Special case if player quits in first round
				cout << "Funny, you just got here. Wasn't there something you needed. No matter. Goodbye." << endl;
				return 0;
			}
			break;
		}
		case 4: {
			current = current->right;
			break;
		}
		}//Switch
		if (current == nullptr) {
			cout << "You ran into a wall. It's OK I don't think anyone noticed.\nTry again." << endl;
			last->getDept();
		}
	} while (current == nullptr);
	counter--;
	return 1;
}//move()

/************************************************************
Gameplay::addFromShelf()
Adds items from Spaces classes shelf list. Calls local function
add item.
***********************************************************/
void Gameplay::addFromShelf() {
	current->inspectShelves();
	int sel = (validate.checkValid(true, 0, current->shelf.size()));
	while (sel > 0) {
		addItem(current->shelf.at(sel - 1));
		sel = (validate.checkValid(true, 0, current->shelf.size()));
	}
}

/************************************************************
Gameplay::addItem(string of item to add)
Adds item from shelf or other area to the cart list. Checks
if item is already in cart before adding. Will also pop items
to maintain cart or basket size.
***********************************************************/
void Gameplay::addItem(std::string in) {
	if (cart.size() > cartSize) {
		cart.pop_back();
		cout << "You removed an item from your cart." << endl;
	}
	if (!searchCart(in)) {
		cout << in << " added to your cart." << endl;
		cart.push_front(in);
	}
	else {cout << "Item is already in your cart" << endl;}
	return;
}

/************************************************************
Gameplay::checkCart()
Itertates the cart list and check if all of the items on the
shopping list have been obtained.
***********************************************************/
bool Gameplay::checkCart() {
	cout << "Your cart contains: ";
	for (std::list<std::string>::iterator it = cart.begin(); it != cart.end(); it++) {
		cout << *it << "   ";
	}
	cout << endl << endl;
	if (cart.size() >= list.size()) {
		for (std::list<std::string>::iterator it = cart.begin(); it != cart.end(); it++) {
			for (unsigned int j = 0; j < list.size(); j++) {
				if (*it == list[j]) {
					count++;
				}//if cart == list
			}//inner for
		} //outer for
	}//if cart.size() == list.size()
	if (count >= list.size()) {
		cout << "You got all the items on your list!" << endl;
		count = 0;
		return true;
	} else {count = 0;}
	return false;
}
/************************************************************
Gameplay::searchCar(String to search for)
Iterates through cart to find strings. Used by other functions.
***********************************************************/
bool Gameplay::searchCart(std::string str) {
	for (std::list<std::string>::iterator it = cart.begin(); it != cart.end(); it++) {
		if (*it == str) {
			return true;
		}
	}
	return false;
}
/************************************************************
Gameplay::printList()
Prints the shopping list.
***********************************************************/
void Gameplay::printList() {
	for (unsigned int i = 0; i <  list.size(); i++) {
		cout << list[i] << "   ";
	}
	cout << endl << endl;
}

Gameplay::~Gameplay() {
	current = nullptr;
	last = nullptr;
}

