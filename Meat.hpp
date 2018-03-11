#ifndef MEAT_HPP 
#define MEAT_HPP 

#include "Spaces.hpp"
#include <iostream>

class Meat : public Spaces{
private:
    int count = 0;
	void stockShelf();
    void getDept();
public:
	Meat();
    void setTop(Spaces &);
    void setLeft(Spaces &);
    void setRight(Spaces &);
    void getText();
	std::string special();
	~Meat();    

};
#endif

