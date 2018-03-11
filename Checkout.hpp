#ifndef Checkout_HPP 
#define Checkout_HPP

#include "Spaces.hpp"
#include <iostream>

class Checkout : public Spaces{
private:
    void getDept();
    void  stockShelf();
public:
	Checkout();
	void getText();
	void setTop(Spaces &);
    void setLeft(Spaces &);
	int specialInt(int);
	void inspectShelves();
	~Checkout();    
};
#endif

