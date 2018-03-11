#ifndef Grocery_HPP
#define Grocery_HPP

#include "Spaces.hpp"
#include "Produce.hpp"
#include "Meat.hpp" 
#include "Entry.hpp" 
#include "Dairy.hpp"
#include "Bread.hpp"
#include "Checkout.hpp"


class Grocery{
private:
    Produce produce_dept;
    Meat meat_dept;
	Entry entry;
	Dairy dairy_dept;
	Bread bread_dept;
	Checkout checkout;

public:
    Grocery();
    void makeSpace();
    Spaces* getEntry();
    Spaces* getCheckout();
};
#endif
