/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 8/8/17
 ** Description: This is an abstract class 
 ** for use in a strategy game. The class is a 
 ** base class for space classes in the environment.
 ********************************************
 *************************/

#include "Spaces.hpp"
/************************************************************
Spaces::getShelfSize()
Utility function to return the size of shelf for not friend 
classes
***********************************************************/
int Spaces::getShelfSize(){
   return shelf.size();
}
/************************************************************
Spaces::setDirection()
Sets the pointers for all of the derived classes. Default is 
null which is a wall in the program.
***********************************************************/

    void Spaces::setTop(Spaces &set){
        top = nullptr;
    }
    void Spaces::setBottom(Spaces &set){
        bottom = nullptr;
    }
    void Spaces::setLeft(Spaces &set){
        left = nullptr;
    }
    void Spaces::setRight(Spaces &set){
        right = nullptr;
    }
/************************************************************
Spaces::inspectShelves()
Prints shelf contents of all the deparment derived classes.
***********************************************************/
void Spaces::inspectShelves(){
     std::cout<<"The shelves are sparse but you see: "<<std::endl;
    for(unsigned int i = 0; i < shelf.size(); i++){
      std::cout<<i+1<<": "<<shelf.at(i)<<std::endl;
    }
    std::cout<<"Keep adding items or press 0 to move to the next department"<<std::endl;


}
/************************************************************
Spaces:special()
Virtual special case.
***********************************************************/
std::string Spaces::special(){
	std::cout<<"What a strange store."<<std::endl;
	return "";	
}
/************************************************************
Spaces::specialInt()
Virtual special case returns int value.
***********************************************************/
int Spaces::specialInt(int mod){
	return 0;	
}

Spaces::~Spaces(){
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}
