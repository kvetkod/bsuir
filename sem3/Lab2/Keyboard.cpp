#include"Keyboard.h"


string Keyboard::Input() {
	if (connect) {
		string input;
		cout << "enter expression:" << endl;
		cin >> input;
		return input;
	}
	else cout << "Connect your keyboard" << endl;
}

void Keyboard::Connection() {
	if (!connect) {
		cout << "Your " << device << " is connected" << endl;
		connect = true;
	}
	else
		cout << "Your keyboard is already connected" << endl;//////////////////////////////
}

void Keyboard::Disconnection() {//////////////////////////////////////
	if (connect) {
		cout << "Your " << device << " is disconnected" << endl;
		connect = false;
	}cout << "Your keyboard is already disconnected" << endl;
}

string Keyboard::GetDevice() {
	return device;
}