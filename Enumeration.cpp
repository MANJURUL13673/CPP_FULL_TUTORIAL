#include <iostream>

int main()
{
	enum class Color{red, green, blue};
	enum Traffic_Light {red, green, blue};

	Color a = Color::red;	//initialize with own class define // okay
	//Color b = Traffic_Light::red;	//initialize with other enumeration //not okay
	//Color c = red;		//intialize with value //not okay

	Traffic_Light d = Traffic_Light::red;	//intialize with enumeration
	//Traffic_Light e = Color::green;		//intialize with class enumeration //not okay
	Traffic_Light f = red;	//initialize with value without proper scoope  //okay
}

