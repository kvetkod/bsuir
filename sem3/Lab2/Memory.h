#pragma once
#include<iostream>
using namespace std;

class Memory {
private:
	int all;
	int free;
public:
	Memory(int all_);
	int GetFree();
	void MemoryCapture(int n);
	void Information();
};