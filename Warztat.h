#pragma once
#include "Car.h"
#include <map>
#include <cstdlib>
#include <stdlib.h>
#include <string>

using namespace std;

class Warsztat {
private:
	int _budget;
	int _repairedCars;
	int _workersNum;
	
public:
	Warsztat(map <string, int> &myMap, Car *cars, int carNum, map<string, int> &carsCame);
	int budget() { return _budget;}
	int repairedCars() { return _repairedCars; }
	void description(map <string, int> &myMap, Car *cars);
	void description2(map <string, int> &carsCame );
};