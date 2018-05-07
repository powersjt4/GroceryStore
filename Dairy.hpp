#ifndef DAIRY_HPP
#define DAIRY_HPP

#include "Spaces.hpp"
#include <iostream>

class Dairy : public Spaces {
private:
	void getDept();
	void  stockShelf();
	bool btlFull = false;

public:
	Dairy();
	void setRight(Spaces &);
	void setLeft(Spaces &);
	void setBottom(Spaces &);
	void getText();
	std::string special();
	~Dairy();
};
#endif

