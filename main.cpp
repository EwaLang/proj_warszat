#include "Car.h"
#include "Warztat.h"
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iterator>
#include <stdio.h>
#include <thread>

using namespace std;

static int carNum;
map<string, int> carsCame;
void fillParts(map <string, int> &map, Car cars);
int main(int argc, char const *argv[]) {
	srand(time(NULL));
	int totalCars = 0;
	map<string, int> parts;
	int budget = 100;
	cout << "our start budget was: " << budget << endl;
	vector<Warsztat> year;
	vector<Warsztat>::iterator itr = year.begin();
	for (int i = 0; i < 12; i++)
	{
		cout << "MONTH " << i + 1<<endl;
		carNum = 12 + rand() % (41 - 12 + 1);
		Car *cars = new Car[carNum];
		cout << carNum << " cars came to our station this month and ";
		if (i == 0) { fillParts(parts, cars[0]); }
		Warsztat w(parts, cars, carNum, carsCame);
		w.description2(carsCame);
		w.description(parts, cars);
		budget += w.budget();
		totalCars += w.repairedCars();
		itr = year.insert(itr, w);
		cout << "\n\n";
		//delete cars;
		this_thread::sleep_for(chrono::milliseconds(10000));
		}
	//----
	cout << "\nWe repaired " << totalCars << " cars this year, ";
	cout << "and our final budget is: " << budget << " so ";
	if (budget < 2000) {
		cout << "we didn't make it, we go out business T_T" << endl;
	}
	else {
		cout << "we've survived, we will work even harder!" << endl;
	}

	//delete cars;

}

void fillParts(map <string, int> &myMap, Car car)
{
	vector<string>::iterator it = car.marks.begin();
	int part;
	for (it = car.marks.begin(); it != car.marks.end(); ++it)
	{
		part = rand() % 36;
		myMap.insert(make_pair(*it, part));
		carsCame.insert(make_pair(*it, 0));
	}

	//printput parts map
	/*for (map<string, int>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
	cout << iter->first << " " << iter->second << "\n";
	}*/
}
