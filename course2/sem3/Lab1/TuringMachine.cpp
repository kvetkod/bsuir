#include"TuringMachine.h"
#include<iostream>
using namespace std;

Rule::Rule(char found_, char required_, char turn_, int nextrule_) {
	found = found_;
	required = required_;
	turn = turn_;
	nextrule = nextrule_;
}
char Rule::found_() {
	return found;
}
char Rule::required_() {
	return required;
}
char Rule::turn_() {
	return turn;
}
int Rule::nextrule_() {
	return nextrule;
}



void Cell::info_(char element) {
	info = element;
}

char Cell::info_() {
	return info;
}

void Cell::next_(Cell* cell) {
	next = cell;
}

void Cell::prev_(Cell* current) {
	prev = current;
}

Cell* Cell::prev_() {
	return prev;
}

Cell* Cell::next_() {
	
	return next;
}

void Rule::print() {

	cout << found << "\t" << required << "\t" << turn << "\t" << nextrule << endl;

}

void TuringMachine::add_element(char element) {
	if (head == NULL) {
		Cell* cell = new Cell;
		cell->info_(element);
		cell->prev_(NULL);
		head = cell;
		return;
	}
	Cell* current = head; 
	while (current->next_()) {
		current = current->next_();
	}
	Cell* cell = new Cell;
	cell->info_(element);
	cell->prev_(current);
	current->next_(cell);
	current = cell;
}

void TuringMachine::clear_tape() {
	if (head == NULL) return;
	while (head) {
		Cell* next = head->next_();
		delete head;
		head = next;
	}
}

void TuringMachine::show_tape() {
	
	Cell* cell = head;
	while (cell) {
		cout << cell->info_();
		cell = cell->next_();
	}
	cout << endl;
}

void TuringMachine::create_rules(char found_, char required_, char turn_, int nextrule_) {

	Rule r(found_, required_, turn_, nextrule_);
	rules.push_back(r);

}

void TuringMachine::show_rules(int size) {
	for (int i = 0; i < size; i++) {
		rules[i].print();
	}
	cout << endl;
}


void TuringMachine::run_machine(int size) {
	Cell* iterator=head;
	bool long_cycle = false;
	int i=0;
	while (i != -1 && i < size) {
		if (rules[i].found_() == iterator->info_()) {
			long_cycle = false;
			if (find_element(rules[i].required_(), rules[i].turn_(), iterator))
				continue;
			else return;
			i = rules[i].nextrule_() - 1;
		}
		else {
			move(i, size, iterator, long_cycle);
		}
	}
}


bool TuringMachine::find_element(char required, char turn, Cell* &iterator) {
	iterator->info_(required);
	if (turn == 'r' && iterator->next_() != NULL) {
		iterator = iterator->next_();
		return true;
	}
	if (turn == 'l' && iterator->prev_() != NULL) {
		iterator = iterator->prev_();
		return true;
	}
	if (iterator->next_() == NULL || iterator->prev_() == NULL) {
		return false;
	}
}

void TuringMachine::move(int &i, int size, Cell* &iterator, bool &long_cycle) {
	if (i == size - 1) {
		if (!long_cycle) {
			i = 0;
			long_cycle = true;
		}
		else {
			if (iterator->next_() != NULL) {
				iterator = iterator->next_();
			}
			else return;
		}
	}
	else {
		i++;
	}
}

