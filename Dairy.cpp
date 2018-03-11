/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 8/13/17
 ** Description: This is the Dairy department for
 ** for a series of derived classes for use in the 
 ** Grocery class. This is all tied together in the
 ** Gameplay class that will create a grocery store
 ** exploration game.
 ********************************************
 *************************/
#include "Dairy.hpp"
#include "Spaces.hpp"

Dairy::Dairy() : Spaces(){
	stockShelf();
}
/************************************************************
Dairy::stockShelf()
Create all the items in the department and puts them in the
shelf vector. 
***********************************************************/
void Dairy::stockShelf(){
	shelf.push_back("Sour Cream");
	shelf.push_back("Eggs");
	shelf.push_back("Almond Milk");
	shelf.push_back("Yogurt");
    shelf.push_back("Cheese");

}
/************************************************************
Dairy::getDept()
Returns a map of the surrounding departments.
***********************************************************/
	void Dairy::getDept(){
        std::cout<<"Your in the Dairy department\nWhich department would you like to go to next?"<<std::endl;
		std::cout<<"\t1: Wall ^\n\n2: <Produce \t4: Bread > \n\n\t3: Meat v \n0: exit" <<std::endl;
	}

/************************************************************
Dairy::set*direction*()
These classes return a pointer to a department. It will be 
linked differently for each department.
***********************************************************/
    void Dairy::setRight(Spaces &set){
        right= &set;
    }
	    
    void Dairy::setLeft(Spaces &set){
        left= &set;
    }
	    
    void Dairy::setBottom(Spaces &set){
        bottom= &set;
    }
/************************************************************
Dairy::getDept()
Prints out a text file with a lower case name of the class
found in a containing text folder.
***********************************************************/
void Dairy::getText(){
    std::string in;
    std::ifstream infile ("dairy.txt");
    if(infile.is_open()){
        while(getline(infile,in)){
            std::cout<<in<<std::endl;
        }
    infile.close();
    }else{
        std::cout<<"Cant open dairy.txt"<<std::endl;
    } 
} 
/************************************************************
Dairy::special()
This is a special event that happens in the dairy department.
Simulates the milk of a cow. Returns a full bottle of milk.
Returns a string item.
***********************************************************/
std::string Dairy::special(){
int count = 0;	
	
while(!btlFull){
	std::cout<<"Thats what that smell is turns out there is a cow in the dairy department. How strange.'"<<std::endl;
	std::cout<<"Looks like you have to milk the cow yourself."<<std::endl;
	std::cout<<"\nPress 'm' 10 times to milk the cow and fill the bottle or press 'x' to stop."<<std::endl;
		while(validate.charChoice('m','x') && count < 10){
			for(int i = 0; i<count;i++){
				std::cout<<"#";
			}
			std::cout<<"\n";
			count++;	
		}			
			if(count >= 10){
				btlFull = true;
			}else{return "";}
	std::cout<<"You got milk!"<<std::endl;
	return "Milk";
	}
std::cout<<"\n***The cow eyes you suspiciously.***"<<std::endl;	
return "";
}

Dairy::~Dairy(){
	top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
}

