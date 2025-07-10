// TEMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>  // for pair
#include <tuple>

int main()
{
    std::pair<std::string, int>p;
    p.first = "Bangladesh";
    p.second = 2024;
    std::cout << p.first << " " << p.second << std::endl;
    p = std::make_pair("Hello", 1971);  // using make_pair

    std::tuple<std::string, double, int>t;
    std::get<0>(t) = "Hello";
    std::get<1>(t) = 1971.0;
    std::get<2>(t) = 2024;
    std::cout << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << std::endl;
    t = std::make_tuple("Bangladesh", 2024.0, 1971);    // using make_tupple
}

