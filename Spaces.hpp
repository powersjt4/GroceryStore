#ifndef Spaces_HPP
#define Spaces_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ValidIn.hpp"
#include "RandomNum.hpp"
class Spaces{

friend class Gameplay;
protected:
	Spaces *top;
    Spaces *bottom;
    Spaces *left;
    Spaces *right;
	ValidIn validate;
	RandomNum random;

public:
    std::vector<std::string> shelf;
    int getShelfSize();
	virtual void inspectShelves();
	virtual std::string special();
	virtual int specialInt(int);
    virtual void setTop(Spaces&);
    virtual void setBottom(Spaces&);
    virtual void setLeft(Spaces&) ;
    virtual void setRight(Spaces&);
    virtual void stockShelf() = 0;
	virtual void getDept() = 0; 
    virtual void getText() = 0; 
    virtual ~Spaces();
};
#endif

