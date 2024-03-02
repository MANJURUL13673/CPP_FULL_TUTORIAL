
#include <iostream>

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    const int a = 17;   //initialize with constant //okay
    int var = 15;
    const int b = var;  //initialize with variable //okay
    constexpr int c = 18; //initialize with constant //okay
    constexpr int d = a;    //intialize with constant //okay
    //constexpr int e = var;  //initialize with variable //not okay

    const int sum1 = sum(a, b);    //intialize with variable result //okay
    //constexpr sum2 = sum(a, b);  //intialize with variable result //not okay   
}

