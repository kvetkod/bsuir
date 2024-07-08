#include"OperatingSystem.h"




void OperatingSystem::Install(bool use) {
	if (use) {
		cout << "You already have op" << endl;
	}
	else
	{
		string name_, version_;
		cout << "Name of the system:" << endl;
		cin >> name_;
		cout << "version:" << endl;
		cin >> version_;
		name = name_;
		version = version_;
	}
}

void OperatingSystem::ShowInformation() {
	cout << name << " " << version << endl;
}