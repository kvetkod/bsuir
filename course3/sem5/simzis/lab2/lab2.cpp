#include<iostream>
#include<string>
using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

string Encryption(string word, int key){
    string password="";
    for(int i = 0; i < word.length(); i++){
        for(int j = 0; j < alphabet.length(); j++){
            if(word[i] == ' ') continue;
            if(word[i] == alphabet[j]){
                int index = (j + key) % alphabet.length();
                password += alphabet[index];
            }
        }
    }
    return password;
}

string Decryption(string word, int key){
    string password = "";
    for(int i = 0; i < word.length(); i++){
        for(int j = 0; j < alphabet.length(); j++){
            if(word[i] == alphabet[j]){
                int index = (j - key + alphabet.length()) % alphabet.length();
                password += alphabet[index];
            }
        }
    }
    return password;
}


void Attack(string password, string word){
    for(int i = 1; i <= alphabet.length(); i++){
        string first_word = Decryption(password, i);
        cout << word << " " << first_word << " for key=" << i << endl;
        if(word!=first_word) {
            cout << "next key" << endl;
        }
        else {
            cout << "done" << endl; 
            return;
            }
    }
}

int main(){
    string word; int key;
    cout << "Введите строку для шифрования" << endl;
    cin >> word;
    cout << "Введите ключ для шифрования" << endl;
    cin >> key;
    string password = Encryption(word, key);
    cout << "строка зашифрованная:" << endl;
    cout << password << endl;
    cout << "строка расшифрованная" << endl;
    cout << Decryption(password, key) << endl;
    Attack(password, word);
    return 0;
}