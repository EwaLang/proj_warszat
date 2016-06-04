
#include "Car.h"
#include <fstream>
#include <iterator>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

vector <string> Car::marks;

void Car::init()
{
	ifstream file("cars.txt");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(marks));
	file.close();
}

Car::Car()
{
	static int num_marks = (init(), marks.size());
	_mark = marks[rand() % num_marks];
	damage = 10 + rand() % (80 - 10 + 1);
}


string Car::description()
{
	return _mark + " uskodzenia: " + to_string(damage) + "%";

}

