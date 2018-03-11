/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 7/14/17
 ** Description: This class will accept int values as a 
 ** string it will test the string and determine if it 
 ** contains non integer values.
 ** val_dec input validate returns -1 if valid and 0 if not.
 ********************************************
 *************************/
#include "ValidIn.hpp"
int ValidIn::val_dec(int d){
        if(d < 0) 
    status = 0;
        
    return status;
}

/************************************************************
ValidIn::val_int(string to test if it is an integer value)
Scans a string for integer values if it finds none integer 
values it returns false else returns true.
***********************************************************/  
//http://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/
bool ValidIn::val_Int(std::string test){
	for (unsigned int nIndex = 0; nIndex < test.length(); nIndex++){
		if(!isdigit(test[nIndex]))
		{
			return false;
		}
	} 
	return true;
}
/************************************************************
ValidIn::convertStr_Int(string to convert to integer value)
Converts a string to integer value. val_Int() should be run first.
***********************************************************/  
int ValidIn::convertStr_Int(std::string convert){
	std::stringstream strStream;
	strStream << convert;
	strStream >> ValidInteger;
	return ValidInteger;
}

/************************************************************
ValidIn::checkValid(string to convert to integer value)
Allows programmer to check if the user input a valid integer
uses the val_int and convert_str_Int classes. 
***********************************************************/  

int ValidIn::checkValid(bool range, int low, int high){
int result;
std::string input;
bool valid;
    do{
    valid=true; //Reset valid flag
    std::cin>>input;
        if(!val_Int(input)){
        std::cout<<"Input is invalid. Please try again."<<std::endl;
        valid=false;
        }
        result = convertStr_Int(input);

        if(range && valid){
            if(result<low){
            std::cout<<"Input is too low. Please try again."<<std::endl;
            valid=false;
            }
            if(result>high){
            std::cout<<"Input is too high. Please try again."<<std::endl;
            valid=false;
            }
        }    
    }while(!valid);     

return result;
}


/************************************************************
bool ValidIn::yes_no()
Used for binary yes or no questions.
***********************************************************/  
bool ValidIn::yes_no(){
    char input = '\0';
    std::cout<<"\ny = yes, n = no: ";
        do{
        std::cin>>input;
        if(input == 'y' || input == 'Y'){
            return true;
        }
        if(input == 'n'|| input == 'n'){
            return false;
        }else{std::cout<<"Invalid choice. Try again: ";}
        std::cin.ignore(1000, '\n');
    }while(input != 'y' ||input != 'Y'||input != 'n'||input != 'N');

return true;
}
/************************************************************
bool ValidIn::charChoice()
Allows binary choice using different letters.
***********************************************************/  
bool ValidIn::charChoice(char first, char second){
    char input = '\0';
        do{
        std::cin>>input;
        if(input == first || input == first - 32){
            return true;
        }
        if(input == second || input == second - 32){
            return false;
        }else{std::cout<<"Invalid choice. Try again: ";}
        std::cin.ignore(1000, '\n');
    }while(input != first ||input != first-32||input != second||input != second-32);

return true;
}

/************************************************************
bool ValidIn::charArray()
The function charArray takes a pointer to an array and the 
size of the the array it asks for user input and outputs the 
character if it is found in the array else it asks for more input. 
***********************************************************/  
char ValidIn::charArray(char *arr, int size){
    char input = '\0';
    while(true){
        std::cin>>input;
        for(int i=0; i<size; i++){
            if(arr[i]==input){ 
                return input;
            }
        }
        
        std::cin.ignore(1000, '\n');
        std::cout<<"Invalid choice. Try again: ";          
    }

}

