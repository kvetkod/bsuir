#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Cell {
public:
	void info_(char element);
	void next_(Cell* cell);
	void prev_(Cell* currrent);
	char info_();
	Cell* prev_();
	Cell* next_();
private:
	char info;
	Cell* next = NULL;
	Cell* prev = NULL;
};

class Rule {
public:
	Rule(char found_, char required_, char turn_, int nextrule_);
	void print();
	char found_();
	char required_();
	char turn_();
	int nextrule_();
private:
	char found;
	char required;
	char turn;
	int nextrule;
	
};

class TuringMachine {

public:
	void add_element(char n);
	void show_tape();
	void clear_tape();
	void create_rules(char found_, char required_, char turn_, int nextrule_);
	void show_rules(int size);
	void run_machine(int size);
private:
	vector<Rule>rules;
	Cell* head = NULL;
	bool find_element(char required, char turn, Cell* &iterator);
	void move(int& i, int size, Cell* &iterator, bool& long_cycle);
};

