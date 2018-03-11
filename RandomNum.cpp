/*******************************************
 **************************
 ** Author:Jake Powers
 ** Date: 7/14/17
 ** Description: This class will return a random 
 ** int in the range of the parameters.
 ********************************************
 *************************/

#include "RandomNum.hpp"
RandomNum::RandomNum(){
    srand(time(NULL));
    randNum=0;
}
/************************************************************
RandomNum::RandomNum(low and high range)
Constructor to be used with following generate randomNumInt()
***********************************************************/  

RandomNum::RandomNum(int l, int h){
    high= h;
    low = l;
    randNum=0;
    srand(time(0));
}
/************************************************************
RandomNum::generateRandomInt()
Will return random int based on range given in constructor.
***********************************************************/  

int RandomNum::generateRandomInt(){
    randNum = (rand()%(high-low+1))+low;    

return randNum;
}
/************************************************************
RandomNum::generateRandomInt(low and high range)
To be used with default constructor and accepts high and low 
range as parameters.
***********************************************************/  
int RandomNum::generateRandomInt(int l, int h){
    randNum = (rand()%(h-l+1))+l;    

return randNum;
}
/************************************************************
RandomNum::genRandFloat(low and high range)
To be used with default constructor and accepts high and low 
range as parameters.
***********************************************************/  
float RandomNum::generateRandFloat(float fMin,float fMax){
    float f = static_cast<float>(rand()) / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
