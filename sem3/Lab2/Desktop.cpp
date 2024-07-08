#include"Desktop.h"

void Desktop::ConnectToWiFi() {
	if (state == false) {
		cout << "your desktop is turned off" << endl;
		return;
	}
	if (EthernetPort == true) {
		cout << "You already have connection to wi-fi" << endl;
	}
	else EthernetPort = true;
}
void Desktop::DisconnectToWifi() {
	if (EthernetPort == false) {
		cout << "Your desktop is not connected to wi-fi" << endl;
	}
	else EthernetPort = false;
}

void Desktop::TurnOn() {
	if (cabel == false) {
		cout << "Conncet your desktop to power supply" << endl;
	}
	else {
		state = true;
		cout << "You can use your computer" << endl;
	}
}
void Desktop::TurnOff() {
	if (cabel == false||state==false) {
		cout << "Your desktop is turned off" << endl;
	}
	else {
		state = false;
		cout << "You can not use your computer" << endl;
	}
}
void Desktop::ConnectToPower() {
	if (cabel == true) {
		cout << "Your desktop is alresdy connected to power supply" << endl;
	}
	else cabel = true;
}
void Desktop::DisconnectToPower() {
	if (cabel == false) {
		cout << "Your desktop is alresdy disconnected to power supply" << endl;
		return;
	}
	if (state == true) {
			cout << "First turn off your desktop" << endl;
			return;
	}
	cabel = false;
}

bool Desktop::GetState() {
	return state;
}

bool Desktop::GetEthernetPort() {
	return EthernetPort;
}

bool Desktop::GetCabel() {
	return cabel;
}