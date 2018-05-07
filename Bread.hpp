#ifndef BREAD_HPP
#define BREAD_HPP

#include "Spaces.hpp"
#include <iostream>

class Bread : public Spaces {
private:
	void getDept();
	void  stockShelf();
	bool visited = false;

public:
	Bread();
	void setLeft(Spaces &);
	void setBottom(Spaces &);
	void getText();
	int specialInt(int);
	~Bread();
};
#endif

