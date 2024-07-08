#pragma once
#include<iostream>
#include<string>
#include<map>
using namespace std;

class trie {
public:
	trie(trie* a, char letter);
	void AddWord(string& a);
	trie* FindWord(string& a);
	void DeleteWord(string& a);
	trie* ParentClimb(char& letter);
	~trie();
private:
	bool IsEndOfWord;
	map<char, trie*>t;
	trie* parent;
	char LetterFromParent;
};