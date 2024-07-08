#pragma once
#include<iostream>
#include"Keyboard.h"
#include"Monitor.h"
#include"OperatingSystem.h"
#include"Processor.h"
#include"Memory.h"
#include<vector>
#include<string>
using namespace std;

class Computer{
public:
	Computer(string model_, string ip_, string modelofprocessor_, int cores_, int speed_, int cachememory_, int memory_ , bool keyboars_, bool connect_);
	void const TurnOn();
	void const TurnOff();
	void const InstallOP(bool use);
	void const Request();
	void const Information();
	void const MemoryRecording(string expresion);
	
	Memory* const GetMemory();
	bool const GetOP();
	bool const GetState();
	Keyboard* const GetKeyboard();
	Monitor* const GetMonitor();
	Processor* const GetProcessor();
private:
	string model;
	bool state;
	string ip;
	Keyboard* keyboard;
	Monitor* monitor;
	OP operatingsystem;
	bool havingop;
	Processor* processor;
	Memory* memory;
};