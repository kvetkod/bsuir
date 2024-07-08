#pragma once
#include<iostream>
using namespace std;

class Device {
private:
	string device;
public:
	Device(string device_) : device(device_) {};

	void virtual Connection()=0;
	void virtual Disconnection()=0;
	string virtual GetDevice() = 0;
	string virtual Input()=0;
	void virtual Output(string expression)=0;
};

