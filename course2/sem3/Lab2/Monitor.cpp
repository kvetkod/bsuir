#include"Monitor.h"


void Monitor::Connection() {
	cout << "Your " << device << " is connected" << endl;
	connect = true;
}

void Monitor::Disconnection() {
	cout << "Your " << device << " is disconnected" << endl;
	connect = false;
}

void Monitor::Output(string expression) {
	if (connect) {
		cout << "the expression you entered:\n" << expression << endl;
	}
	else cout << "Connect monitor" << endl;

}

string Monitor::GetDevice() {
	return device;
}