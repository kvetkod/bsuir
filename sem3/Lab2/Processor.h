#pragma once
#include<iostream>
using namespace std;


class Processor {
private:
	string model;
	int cores;
	int speed;
	int cachememory;
public:
	Processor(string model_, int cores_, int speed_, int cahcememory_);
	int GetSpeed();
	void Information();
	void IncreaseSpeed(int n);
	void ReduceSpeed(int n);
};