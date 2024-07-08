#pragma once
#include"Computer.h"


class Laptop : public Computer {
public:
	Laptop(string model_, string ip_, string modelofprocessor_, int cores_, int speed_, int cachememory_, int memory_, bool keyboard_, bool connect_) : Computer(model_, ip_, modelofprocessor_, cores_, speed_, cachememory_, memory_, keyboard_, connect_) {};
	void OpenLaptop();
	void CloseLaptop();
	void TurnOn();
	void TurnOff();
	bool GetState();
	bool GetCover();
private:
	bool cover = false;
	bool state;
};