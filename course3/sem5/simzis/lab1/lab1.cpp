#include<iostream>
#include<string>
#include<ctime>
#include<locale>
#include<vector>
#include<cmath>
using namespace std;
wstring alphabet = L"ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮйцукенгшщзхъфывапролджэячсмитьбю1234567890";

wstring RandomString(int length){
    alphabet = L"ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮйцукенгшщзхъфывапролджэячсмитьбю1234567890";
    wstring result = L"";
    for(int i = 0; i < length; i++){
        wchar_t symbol = alphabet[rand()%alphabet.length()];
        result += symbol;
    }
    return result;
}

void Check(wstring password){
    wstring word = password;
    vector<int> counts;
    for(int i = 0; i < alphabet.size(); i++){
        counts.push_back(0);
    }
    for(int i = 0; i < word.length(); i++){
        int count = 1;
        if(i!=word.length()-1){
            for(int j = i+1; j < word.length(); j++){
                if(word[i] == word[j]) {
                    count++;
                    word.erase(j, 1);
                    j--;
                }
            }
        }
        for(int j = 0; j < alphabet.length(); j++){
            if(alphabet[j] == word[i]) {
                counts[j] = count;
                break;
            }
        }
  
    }
    wcout << L"в алфавите:" << endl;
    for(int i = 0; i < alphabet.length(); i++){
        wcout << alphabet[i] << " " << counts[i] << endl;
    }
    return;
}

void FindTime(wstring password, int length){
    long double n = pow(alphabet.length(), length);
    long double time = n / (2 * 1000000);
    wcout << L"время для подбора пароля длины" << " " << length << L": " << time;
}

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(nullptr));
    int length;
    wcout << L"Введите кол-во символов:"<< endl;
    cin >> length;
    wstring password = RandomString(length);
    wcout << password << endl;
    Check(password);
    FindTime(password, length);
}