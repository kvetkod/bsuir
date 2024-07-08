#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Arr {
public:
	void Add(string e);
	void Print();
	void SummetricDifference(Arr set);
	void SummetricDifferences(vector<Arr>set);
private:
	vector<string> info;
	int contains(string e);
	void Del(string e, int i, int& v);
	bool check(string e);
	Arr Union(vector<Arr>set);
	Arr Cross(vector<Arr>set);
	int Max_C(vector<int>counter);
	int Min_C(vector<int>counter);
};