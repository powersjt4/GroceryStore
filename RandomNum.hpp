#ifndef RANDOMNUM_HPP 
#define  RANDOMNUM_HPP

#include <cstdlib>
#include <ctime>
class RandomNum{
private:
    int randNum; 
    int low;
    int high;

public:
    RandomNum();
    RandomNum(int, int);
    int generateRandomInt();
    int generateRandomInt(int, int);  
    float generateRandFloat(float, float);  
};
#endif
