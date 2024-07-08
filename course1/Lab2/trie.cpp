#include"trie.h"

trie::trie(trie* a, char letter) {
	IsEndOfWord = false;
	parent = a;
	LetterFromParent = letter;
}

void trie::AddWord(string& a) {
	if (a.size() == 1 && a[0] == ' ') {
		cout << "error" << endl;
		return;
	}
	for (int i = 0; i < a.length(); i++) {
		char b[2];
		b[1] = a[i];
		if (atoi(b) >= 0 && atoi(b) <= 9) {
			cout << "error";
			return;
		}
	}
	char PrevLetter = a[0];
	if (t.find(a[0]) == t.end())
	{
		t.emplace(a[0], new trie(this, a[0]));
	}
	a.erase(0, 1);
	if (!a.empty())
	{
		t.at(PrevLetter)->AddWord(a);
	}
	else
	{
		IsEndOfWord = true;
		cout << "the word added to trie" << endl;
	}
}

trie* trie::FindWord(string &a) {
	if (a.size() == 1 && a[0] == ' ') {
		cout << "no words";
		return nullptr;
	}
	char PrevLet = a[0];
	if (t.find(a[0]) == t.end())
	{
		cout << "this word is not in trie" << endl;
		return nullptr;
	}
	a.erase(0, 1);
	if (a.empty() && IsEndOfWord)
	{
		cout << "word successfully found in trie" << endl;
		return this;
	}
	else if (a.empty())
	{
		cout << "this word is not in trie" << endl;
		return nullptr;
	}
	t.at(PrevLet)->FindWord(a);
}


void trie::DeleteWord(string& a) {
	trie* obj = this->FindWord(a);
	
	if (obj == nullptr)
	{
		cout << "can't delete non-existent word" << endl;
		return;
	}
	obj->IsEndOfWord = false;
	if (obj->t.size() > 0) return;
	char LetterForDelete;
	obj = obj->ParentClimb(LetterForDelete);
	obj->t.at(LetterForDelete)->~trie();
	if (!obj->IsEndOfWord) {
		obj->t.erase(LetterForDelete);
		return;
	}
	obj->t.at(LetterForDelete)->t.clear();
}

trie* trie::ParentClimb(char& letter) {
	
	if (t.size() > 1||IsEndOfWord) {
		return this;
	}
	letter = LetterFromParent;
	trie* trieP;
	trieP = parent->ParentClimb(letter);
	return trieP;
}
trie::~trie() {
	for (char i = 'a'; i < 'z'; i++) {
		if (t.find(i) != t.end())
			t.at(i)->~trie();
	}
}