#include "Car.h"
#include "Warztat.h"
#include <iostream>
#include <map>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iterator>
#include <stdio.h>
#include <math.h> 


using namespace std;
int _carNum;

Warsztat::Warsztat(map <string, int> &myMap, Car *cars, int carNum, map<string, int> &carsCame) {
	//for (int i = 0; i < carnum; i++) {
	//	cout << cars[i].description() << "\n";
	//}
	_workersNum = 4;
	 _carNum=carNum;
	 _budget = 0;
	 _repairedCars = 0;
	string m = "";
	int fixRratio;
	int overallDamage = 0;
	int overallRepair = 0;
	int minPartsNeeded = 0;
	map<string, int>::iterator iter;
	map<string, int>::iterator iterRep;
	for (int i = 0; i < carNum; i++) {
		m = cars[i].mark();
		overallDamage += cars[i].damage;
		iter = myMap.find(m);
		minPartsNeeded = floor(cars[i].damage / 15) + 1;
		if (iter->second != 0 && iter->second >= minPartsNeeded) {
			iterRep = carsCame.find(m);
			iterRep->second++;
			_repairedCars++;
			iter->second -= minPartsNeeded;
			fixRratio = 15 + rand() % 76;
			cars[i].damage -= fixRratio;
			if (cars[i].damage < 0) { cars[i].damage = 0; }
		}

	}
	for (int i = 0; i < carNum; i++) {
		overallRepair += cars[i].damage;
	}
	overallRepair = overallDamage - overallRepair;
	_budget += overallRepair * 10;
}

void Warsztat::description(map <string, int> &myMap, Car *cars) {
	cout<<"we got " << _budget << " dollars for it."<<endl;
	cout << "Need to buy parts for: ";
	int partsExpences=0; 
	for (map<string, int>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter) {
		if (iter->second <= 2) {
			cout << iter->first<<" ";
			iter->second += 10;
			partsExpences += 10 * (15 + rand() % (76));
			_budget -= 10 * (15 + rand() % (76));
		}
	}
	int payment = _workersNum * (350 + rand() % (420));
	_budget -= payment;
	cout << "\nExpences for parts: " << partsExpences << " and workers payments: "<<payment<<".\n";
}

void Warsztat::description2(map <string, int> &carsCame) {
	cout << "we have repaired " << _repairedCars << " of them. " << "\n";
	cout << "It was:\n";
	for (map<string, int>::iterator iter = carsCame.begin(); iter != carsCame.end(); ++iter) {
			if (iter->second != 0) {
			cout << iter->second << " "<< iter->first<<endl;
		}
	}
}