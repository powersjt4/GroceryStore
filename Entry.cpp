/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 8/13/17
 ** Description: This is the Entry department for
 ** for a series of derived classes for use in the 
 ** Grocery class. This is all tied together in the
 ** Gameplay class that will create a gorcery store
 ** exploration game.
 ********************************************
 *************************/
#include "Entry.hpp"
#include "Spaces.hpp"

Entry::Entry() : Spaces(){
	stockShelf();
}

/************************************************************
Entry::stockShelf()
Create all the items in the department and puts them in the
shelf vector. 
***********************************************************/
void Entry::stockShelf(){
}

void Entry::inspectShelves(){
    std::cout<<"Nothing to see. Press 0.";
}
/************************************************************
Entry::getDept()
Returns a map of the surrounding departments.
***********************************************************/
	void Entry::getDept(){
        std::cout<<"Your in the entry \nWhich department would you like to go to next?"<<std::endl;
        std::cout<<"\t1: Produce ^\n\n2: < Wall \t4: Meat > \n\n\t0: exit v " <<std::endl;
	}

/************************************************************
Entry::set*direction*()
These classes return a pointer to a department. It will be 
linked differently for each department.
***********************************************************/
    void Entry::setRight(Spaces &set){
        right = &set;
    }

   void Entry::setTop(Spaces &set){
        top = &set;
    }
/************************************************************
Entry::special(int value as a modifier)
This is a special event that happens in the Entry.
Takes an int value as a modifier(set to 0 if not needed)
 and returns an in value.
***********************************************************/
int Entry::specialInt(int mod){
    if(!visited){
        visited = true;
        std::cout<<"Please pick a shopping implement: "<<std::endl;
        std::cout<<"1. Basket (can only hold 10 items faster + 1 to number of moves"<<std::endl;
        std::cout<<"2. Shopping cart (can hold 50 items slower -1 to number of moves"<<std::endl;

        if(validate.checkValid(true,1,2)>1){
            return 50;
        }else{return 10;}
    }else{std::cout<<"This store looks a little disheveled."<<std::endl;
        return 0;   
    }
}

/************************************************************
Entry::getDept()
Prints out a text file with a lower case name of the class
found in a containing text folder.
***********************************************************/
void Entry::getText(){
    std::string in;
    std::ifstream infile ("entry.txt");
    if(infile.is_open()){
        while(getline(infile,in)){
            std::cout<<in<<std::endl;
        }
    infile.close();
    }else{
        std::cout<<"Cant open Entry.txt"<<std::endl;
    } 
} 

Entry::~Entry(){
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}

