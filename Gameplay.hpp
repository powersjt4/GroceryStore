#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
#include "Produce.hpp"
#include "Grocery.hpp"
#include "Spaces.hpp"
#include "ValidIn.hpp"
#include <iostream>
#include <string>
#include <list>
#include <vector>


using std::cout;
using std::endl;

class Gameplay {
private:
//Variables & objects
	ValidIn validate;
	std::list<std::string> cart;
	std::vector<std::string> list {"Bacon", "Potato", "Tomato", "Milk", "Whole Chicken", "Bread"};
	//std::vector<std::string> list {"Potato","Tomato"};//For testing only need to go to produce.
	Spaces *last = nullptr;
	Spaces *current;
	int counter = 20;
	Grocery grocery;
	unsigned int cartSize = 0;
	unsigned int count = 0;
//Functions
	bool searchCart(std::string);
	void addItem(std::string);
	void addFromShelf();
	bool checkCart();
	int move(int);
	void printList();
public:
	void magicHpns();
	~Gameplay();
};
#endif

