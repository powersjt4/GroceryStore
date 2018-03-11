/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 8/13/17
 ** Description: This is the Bread department for
 ** for a series of derived classes for use in the 
 ** Grocery class. This is all tied together in the
 ** Gameplay class that will create a grocery store
 ** exploration game.
 ********************************************
 *************************/
#include "Bread.hpp"
#include "Spaces.hpp"

Bread::Bread() : Spaces(){
	stockShelf();
}
/************************************************************
Bread::stockShelf()
Create all the items in the department and puts them in the
shelf vector. 
***********************************************************/
void Bread::stockShelf(){
	shelf.push_back("Bread");
	shelf.push_back("Darker Bread");
	shelf.push_back("Bread With Seeds");
	shelf.push_back("Bagels");
    shelf.push_back("Candles?");

}
/************************************************************
Bread::getDept()
Returns a map of the surrounding departments.
***********************************************************/
	void Bread::getDept(){
        std::cout<<"Your in the Bread department\nWhich department would you like to go to next?"<<std::endl;
		std::cout<<"\t1: Wall ^\n\n2: < Dairy \t4: Wall > \n\n\t3: Checkout v \n0: exit" <<std::endl;
	}
/************************************************************
Bread::set*direction*()
These classes return a pointer to a department. It will be 
linked differently for each department.
***********************************************************/
    void Bread::setLeft(Spaces &set){
		left = &set;
	}
	void Bread::setBottom(Spaces &set){
		bottom = &set;
	}
/************************************************************
Bread::getDept()
Prints out a text file with a lower case name of the class
found in a containing text folder.
***********************************************************/void Bread::getText(){
    std::string in;
    std::ifstream infile ("bread.txt");
    if(infile.is_open()){
        while(getline(infile,in)){
            std::cout<<in<<std::endl;
        }
    infile.close();
    }else{
        std::cout<<"Cant open bread.txt"<<std::endl;
    } 
} 
/************************************************************
Bread::special(int value as a modifier)
This is a special event that happens in the bread department.
Takes an int value as a modifier(set to 0 if not needed)
 and returns an in value.
***********************************************************/
int Bread::specialInt(int mod){
	int count = 0;
	if(!visited){
		visited = true;
		std::cout<<"You turn the corner and in front of you there is a person of advanced age slowly pushing an overloaded cart."<<std::endl;
		std::cout<<"Do you want to try and pass by them. There is a 50/50 chance you lose more time then if you just wait"<<std::endl;
		if(validate.yes_no()){
			do{
				count++;
				std::cout<<"You tried to pass them counter -1"<<std::endl;
			}while(random.generateRandomInt(1,100) > 20);
		return count;			
		}else{std::cout<<"You waited patiently for the elderly person to move. How polite. (counter - 2)"<<std::endl;	
			return 2;
		}	
	}
	return 0;	
}

Bread::~Bread(){
	top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}

