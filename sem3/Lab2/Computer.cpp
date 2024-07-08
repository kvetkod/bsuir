#include"Computer.h"

Computer::Computer(string model_, string ip_, string modelofprocessor_, int cores_, int speed_, int cachememory_, int memory_,bool keyboard_, bool connect_){//добавить процессор
		model = model_;
		state = false;
		ip = ip_;
		keyboard = new Keyboard("keyboard", keyboard_);
		monitor = new Monitor("monitor", connect_);
		processor = new Processor(modelofprocessor_, cores_, speed_, cachememory_);
		memory = new Memory(memory_);
		havingop = false;
}

bool const Computer::GetState() {
	return state;
}


void const Computer::TurnOn() {
	state = true;
	cout << "Computer " << model << " is on" << endl;
}

void const Computer::TurnOff() {
	state = false;
	cout << "Computer " << model << " is off" << endl;
}



void const Computer::Information() {
	cout << "Model:" << model << endl;
	cout << "IP:" << ip << endl;
	if (havingop)
	{
		cout << "Operating system:" << endl; operatingsystem.ShowInformation();  
	}

	cout << "Processor:" << endl; processor->Information();
	cout << "Memory" << endl; memory->Information(); 
}


Processor* const Computer::GetProcessor() {
	return processor;
}

void const Computer::MemoryRecording(string expression) {
	int count = expression.length();
	memory->MemoryCapture(count);
}

Keyboard* const Computer::GetKeyboard() {
	return keyboard;
}

Monitor* const Computer::GetMonitor() {
	return monitor;
}


void const Computer::Request() {
	if (state) {
		monitor->Output(keyboard->Input());
	}
	else cout << "Your computer is off" << endl;
}


void const Computer::InstallOP(bool use) {
	operatingsystem.Install(use);
	havingop = true;
}


bool const Computer::GetOP() {
	return havingop;
}

Memory* const Computer::GetMemory() {
	return memory;
}