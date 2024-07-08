#pragma once
#include<iostream>
#include"Device.h"
using namespace std;


class Keyboard : public Device {
private:
	string device;
	bool connect;
public:
	Keyboard(string device_, bool connect_) : Device(device_) {
		device = device_;
		connect = connect_;
	};
	string GetDevice() override;
	void Connection() override;
	void Disconnection() override;
	string Input() override;
	void Output(string expression) override {
		return;
	}
};