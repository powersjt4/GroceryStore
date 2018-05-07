#ifndef PRODUCE_HPP
#define PRODUCE_HPP

#include "Spaces.hpp"
#include <iostream>

class Produce : public Spaces {
private:
	void getDept();
	void  stockShelf();
public:
	Produce();
	void setRight(Spaces &);
	void setBottom(Spaces &);

	void getText();
	~Produce();
};
#endif

