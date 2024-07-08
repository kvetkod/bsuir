#pragma once
#include<iostream>
#include"Device.h"

class Monitor : public Device {
public:
	Monitor(string device_, bool connect_) : Device(device_) {
		device = device_;
		connect = connect_;
	};
	string GetDevice() override;
	void Connection() override;
	void Disconnection() override;
	void Output(string expression) override;
	string Input() override {
		return "0";
	}
private:
	string device;
	bool connect;
};