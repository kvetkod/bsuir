#include<iostream>
#include"TuringMachine.h"
#include<vector>
using namespace std;

int main() {
	TuringMachine machine;
	machine.add_element('1');
	machine.add_element('#');
	machine.add_element('$');
	machine.add_element('1');
	machine.add_element('0');
	machine.add_element('#');
	machine.show_tape();
	int size = 4;
	char found, required, turn;
	int nextrule;
	cout << "found\trequired\tturn\tnextrule" << endl;
	for (int i = 0; i < size; i++) {
		if (i != size - 1) {
			cin >> found >> required >> turn >> nextrule;
			machine.create_rules(found, required, turn, nextrule);
		}
		else {
			cin >> found >> required >> turn;
			nextrule = 1;
			machine.create_rules(found, required, turn, nextrule);
		}
	}
	cout << "rules:" << endl;
	machine.show_rules(size);
	machine.run_machine(size);
	machine.show_tape();
	machine.clear_tape();
	
}