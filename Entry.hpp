#ifndef ENTRY_HPP
#define ENTRY_HPP

#include "Spaces.hpp"
#include "ValidIn.hpp"
#include <iostream>

class Entry : public Spaces {
private:
	void getDept();
	void  stockShelf();
	bool visited = false;
public:
	Entry();
	void setTop(Spaces &);
	void setRight(Spaces &);
	void getText();
	void inspectShelves();
	int specialInt(int);
	~Entry();
};
#endif

