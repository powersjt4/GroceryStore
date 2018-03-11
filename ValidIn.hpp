 /********************************************
 **************************
 ** Author:Jake Powers
 ** Date:6/28/17
 ** Description: This class will perform user input validation. 
 ** on decimal,
 ** if valid returns -1 if not returns 0.
 ********************************************
 *************************/

#ifndef VALIDIN_HPP
#define VALIDIN_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <sstream>

class ValidIn{
private:
	int ValidInteger;
	int status;
public:
   int val_dec(int);
   bool val_Int(std::string);
   int convertStr_Int(std::string);
   int checkValid(bool, int, int);
   bool yes_no();
   bool charChoice(char, char);
   char charArray(char *, int);

};
#endif
