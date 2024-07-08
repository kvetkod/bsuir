#pragma once
#include<iostream>
using namespace std;

class OperatingSystem {
private:
	string name;
	string version;
public:
	void Install(bool use);
	void ShowInformation();
};