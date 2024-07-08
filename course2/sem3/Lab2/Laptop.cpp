#include"Laptop.h"

void Laptop::OpenLaptop() {
	cover = true;
	cout << "Now you can turn on your laptop" << endl;
}

void Laptop::CloseLaptop(){
	TurnOff();
	cover = false;
	cout << "Now your laptop is turn off" << endl;
}


void Laptop::TurnOn() {
	if (cover == false) {
		cout << "open your laptop" << endl;
	}
	else {
		state = true;
		cout << "You can use your laptop" << endl;
	}
}

void Laptop::TurnOff() {
	if (cover == false) {
		cout << "yout laptop is already turned off" << endl;
	}
	else {
		state = false;
	}
}

bool Laptop::GetCover() {
	return cover;
}

bool Laptop::GetState() {
	return state;
}