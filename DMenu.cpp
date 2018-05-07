/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 7/14/17
 ** Description: This class creates a vector of strings
 ** for display as a menu.
 ********************************************
 *************************/
#include <iostream>
#include <string>
#include "DMenu.hpp"
/************************************************************
DMenu::addItem(string of menu item)
Adds menu item to vector
***********************************************************/
void DMenu::addItem(std::string str) {
	menu.push_back(str);

	return;
}
/************************************************************
DMenu::printDMenu(none)
This will print the menu vector with corresponding line number.
***********************************************************/
void DMenu::printDMenu() {
	for (unsigned int i = 0; i < menu.size(); i++) {
		std::cout << i + 1 << ": " << menu[i] << std::endl;
	}

	return;
}



