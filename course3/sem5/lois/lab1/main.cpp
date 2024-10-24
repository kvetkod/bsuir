#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include <algorithm>
#include<sstream>
using namespace std;

class FuzzyInference{
private:
    int k = 1;
    vector<map<string, map<string,double>>> list;
    vector<string> premize;
    vector<vector<vector<double>>> result;
    void readfromfile(string name);
    vector<vector<double>> implication(int i);
    vector<vector<double>> t_norma(int index, map<string, double> ar);
    void sup(int index, vector<vector<double>> res, string write);
    bool check(string one, string two);
    bool contains(vector<map<string, map<string,double>>> list,  map<string, double>& new_ar);
public:
    void Operation(string file);
};

bool FuzzyInference::contains(vector<map<string, map<string,double>>> list, map<string, double>& new_ar) {
    for (const auto& outer_map : list) {
        for (const auto& inner_pair : outer_map) {
            if (inner_pair.second == new_ar) {
                return true; // Найдено совпадение
            }
        }
    }
    return false; // Совпадение не найдено
}

bool FuzzyInference::check(string one, string two){
    int size1, size2;
    if (one == two) return true;
    for(int i = 0; i < list.size(); i++){
        for(const auto& j : list[i]){
            if(j.first == one){
                size1 = j.second.size();
            }
            if(j.first == two){
                size2 = j.second.size();
            }
        }
    }
    if(size1 == size2) return true;
    return false;
}

void FuzzyInference::readfromfile(string name){
    vector<string> lines;
    fstream file(name);
    string line;
    if(file.is_open()){
        while(getline(file, line))
            lines.push_back(line);
    }
    for(int i = 0; i < lines.size(); i++){
        //cout<<lines[i]<<endl;
        string name;
        map<string, double> f_array;
        for(int j = 0; j < lines[i].length(); j++){
            if(lines[i][j] == ' ') break;
            if(j == 0 && lines[i][j+1] == '=') {
                name += lines[i][j];
                j++;
                continue;
            }
            else if(j == 0 && lines[i][j+1] != '='){
                name += lines[i][j];
                name += lines[i][j+3];
                premize.push_back(name);
                break;
            }
            if(lines[i][j] == '<'){
                string key = "";
                key += lines[i][j+1];
                string number = "";
                int k;
                for(k = j+3; k < lines[i].size(); k++){
                    if(lines[i][k] == '>') break;
                    number += lines[i][k];
                }
                j = k;
                double number_b;
                stringstream ss;
                ss << number;
                ss >> number_b;
                f_array.insert({key, number_b});
            }   
        }
        if(name == "") continue;
        if(name.size()>1) continue;
        map<string, map<string,double>> result;
        result.insert({name, f_array});
        list.push_back(result);
    }
}

vector<vector<double>> FuzzyInference::implication(int i){
    vector<vector<double>> res;
    map<string, double> first;
    map<string, double> second;
    string first_ar, second_ar;
    first_ar += premize[i][0]; 
    second_ar += premize[i][1];
    for(int i = 0; i < list.size(); i++){
        for(const auto& pair : list[i]){
            if(pair.first == first_ar){
                first = pair.second;
            }
            if(pair.first == second_ar){
                second = pair.second;
            }
        }
    }
    for(const auto& i : first){
        vector<double> line;
        for(const auto& j : second){
            double number = 1 - i.second + j.second;
            if(number < 1) line.push_back(number);
            else line.push_back(1);
        }
        res.push_back(line);
    }

    return res;
}

vector<vector<double>> FuzzyInference::t_norma(int index, map<string, double> ar){
    vector<vector<double>> res = result[index];
    int i = 0, size = res[0].size();
    for(int j = 0; j < size; j++){
        i = 0;
        for(const auto& k : ar){
            double num = res[i][j] + k.second - 1;
            if(num > 0) res[i][j] = num;
            else res[i][j] = 0;
            i++;
        }
    }
    return res;
}

void FuzzyInference::sup(int index, vector<vector<double>> res, string write){
    map<string, map<string, double>> new_ar;
    string names = "abcdefghijklmnop";
    int size = res[0].size(); double max;
    map<string, double> arr;
    for(int j = 0; j < size; j++){
        max = res[0][j];
        for(int i = 0; i < res.size(); i++){
            if(res[i][j] > max) max = res[i][j];
        }
        string name;
        name += names[j];
        arr.insert({name, max});
    }
    char ch = to_string(k)[0];
    string n = "I";
    n += ch;
    

    

    

    if(!contains(list, arr)) {
        cout << n << "=" << write << "={";
        auto last = arr.end();
        for(const auto& i : arr){
            cout << "<"<< i.first <<"," << i.second << ">";
            if(i.first != last->first) cout << ",";
        }
        cout << "}"<<endl;
        k++;
        new_ar.insert({n, arr});
        list.push_back(new_ar);
    }
}

void FuzzyInference::Operation(string name){
    readfromfile(name);
    for(int i = 0; i < premize.size(); i++){
        result.push_back(implication(i));
    }
    string two;
    for(int i = 0; i < list.size(); i++){
        for(int j = 0; j < premize.size(); j++){
            auto ar = list[i].begin();
            two = "";
            two += premize[j][0];
            if(check(ar->first, two)){
                string writel = "sup(";
                writel = writel + ar->first + "/~\\(" + two + "~>" + premize[j][1] + "))"; 
                sup(j, t_norma(j, ar->second), writel);
            }
        }
    }
}



int main(){
    FuzzyInference a;
    a.Operation("test1.txt");
    return 0;
}