#pragma once
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Car
{
private:
	string _mark;
	static void init();

public:
	Car();
	static vector <string> marks;
	int damage;
	string mark() { return _mark; }
	string description();
	};