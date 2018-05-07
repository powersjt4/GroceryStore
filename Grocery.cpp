#include "Grocery.hpp"

Grocery::Grocery() {
		makeSpace();
}
//Connects all the pointers in the objects
void Grocery::makeSpace() {

//Entry way sets
	entry.setTop(produce_dept);
	entry.setRight(meat_dept);

//Produce department sets
	produce_dept.setBottom(entry);
	produce_dept.setRight(dairy_dept);

//Meat sets
	meat_dept.setTop(dairy_dept);
	meat_dept.setLeft(entry);
	meat_dept.setRight(checkout);

//Dairy department sets
	dairy_dept.setRight(bread_dept);
	dairy_dept.setLeft(produce_dept);
	dairy_dept.setBottom(meat_dept);

//Bread department sets
	bread_dept.setLeft(dairy_dept);
	bread_dept.setBottom(checkout);

//Bread department sets
	checkout.setTop(bread_dept);
	checkout.setLeft(meat_dept);


}
Spaces* Grocery::getEntry() {
	return &entry;
}

Spaces* Grocery::getCheckout() {
	return &checkout;
}

