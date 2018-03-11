/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 8/13/17
 ** Description: This is the meat department for
 ** for a series of derived classes for use in the 
 ** grocery store. This is all tied together in the
 ** Gameplay class that will create a grocery store
 ** exploration game.
 ********************************************
 *************************/
#include "Meat.hpp"
#include "Produce.hpp"

Meat::Meat() : Spaces(){
    stockShelf();
    //linkDepts(); 
}
/************************************************************
Meat::stockShelf()
Create all the items in the department and puts them in the
shelf vector. 
***********************************************************/
void Meat::stockShelf(){
	shelf.push_back("Whole Chicken");
	shelf.push_back("Pork Chops");
    shelf.push_back("Pot Roast");
	shelf.push_back("Ground Beef");
	shelf.push_back("Mystery Meat");
}

/************************************************************
Produce::getDept()
Returns a map of the surrounding departments.
***********************************************************/
void Meat::getDept(){
        std::cout<<"Your in the meat department\nWhich department would you like to go to next?"<<std::endl;
		std::cout<<"\t1: Dairy ^\n\n2: <Entry \t4: Checkout > \n\n\t3: Wall v \n 0: exit"<<std::endl;
    }
/************************************************************
Meat::set*direction*()
These classes return a pointer to a department. It will be 
linked differently for each department.
***********************************************************/
    void Meat::setTop(Spaces &set){
        top = &set;
    }
    void Meat::setLeft(Spaces &set){
        left = &set;
    }
    void Meat::setRight(Spaces &set){
        right = &set;
    }


/************************************************************
Meat::special()
This is a special event that happens in the meat department.
First time visiting and the butcher gives you a weird look.
The second time he asks you to answer a riddle.
Retruns a string item.
***********************************************************/
std::string Meat::special(){
	count++;
	if(count == 2){ 
	std::cout<<"The butcher says to you 'Hey, come over here. I saw you wondering around.'\nyou walk over and he says 'You need bacon? Answer this riddle and you can have the last of it.'"<<std::endl;
	std::cout<<"What do you call a pig with a sunburn?\n 1: A pork chop\n 2: Chicken\n 3: Bacon\n 4: 'Remark on how strange and unprofessional their conduct is.'"<<std::endl;

	
	while(validate.checkValid(true,1,4)!=3){
		std::cout<<"Nope. Try again."<<std::endl;
	}
	std::cout<<"You got bacon!"<<std::endl;
	return "Bacon";
	}else{std::cout<<"\n***The butcher eyes you suspiciously.***\n"<<std::endl;
	return ""; 	
	} 
 	  	
}
/************************************************************
Meat::getDept()
Prints out a text file with a lower case name of the class
found in a containing text folder.
***********************************************************/
void Meat::getText(){
    std::string in;
    std::ifstream infile ("meat.txt");
    if(infile.is_open()){
        while(getline(infile,in)){
            std::cout<<in<<std::endl;
        }
    infile.close();
    }else{
        std::cout<<"Cant open meat.txt"<<std::endl;
    } 
} 
Meat::~Meat(){
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}
