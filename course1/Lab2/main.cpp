#include<iostream>
#include<fstream>
#include"trie.h"
using namespace std;
void test1() {
    trie mainTrie(nullptr, 0);
    string word;
    ifstream fin("D:\\words.txt");
    while (fin >> word)
        mainTrie.AddWord(word);
    fin.close();
    cout << endl;
    fin.open("D:\\deleteWords.txt");
    while (fin >> word)
        mainTrie.DeleteWord(word);
    cout << '\n';
    fin.close();
    fin.open("D:\\words.txt");
    while (fin >> word)
        mainTrie.FindWord(word);
    fin.close();
    cout << endl;
    fin.open("D:\\deleteWords.txt");
    while (fin >> word)
        mainTrie.FindWord(word);
    fin.close();
}
void test2() {
    trie mainTrie(nullptr, 0);
    string word;
    word = ' ';
    mainTrie.AddWord(word);
    mainTrie.FindWord(word);
}
void test3() {
    trie mainTrie(nullptr, 0);
    string word;
    word = "g1g2g3";
    mainTrie.AddWord(word);
}
int main() {
    //test1();
    //test2();
    test3();
}