#ifndef DMENU_HPP
#define  DMENU_HPP
/*******************************************
 **************************
 ** Author:Jake Powers
 ** Description: this is a dynamic menu class that will
 ** create a menu based upon user input of strings.
 **
 ********************************************
 *************************/
#include <string>
#include <vector>

class DMenu
{
private:
	std::vector<std::string> menu;

public:
	void addItem(std::string str);
	void printDMenu();
};
#endif
