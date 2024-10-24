#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;

class Generate{
private:
    int p = 7489;
    int g;
    void factorization();
    int createnumbers();
    vector<int> numbers;
public:
    void Task();
};

void Generate::factorization() {
    int n = p-1;

    while (n % 2 == 0) {
        numbers.push_back(2);
        n /= 2;
    }
    

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            numbers.push_back(i);
            n /= i;
        }
    }
    

    if (n > 2) {
        numbers.push_back(n);
    }
    

}

int Generate::createnumbers(){
    for (int g = 2; g < p; g++) {
        std::set<int> numbers;
        for (int i = 1; i < p; i++) {
            
            int number = 1;
            for (int j = 0; j < i; j++) {
                number = (number * g) % p;
            }
            numbers.insert(number);
        }
        
        
        if (numbers.size() == p - 1) {
            bool isPrimitive = true;
            for (int i = 1; i < p; i++) {
                if (numbers.find(i) == numbers.end()) {
                    isPrimitive = false;
                    break;
                }
            }
            if (isPrimitive) {
                return g; 
            }
        }
    }
    return -1; 
}

void Generate::Task(){
    g = createnumbers();
    int a, b, A, B , key1, key2;
    cout << "g:" << g << endl;
    do{
        cout << "введите число а:" << endl;
        cin >> a;
    }while(a < 2 || a > g);
    do{
        cout << "введите число b:" << endl;
        cin >> b;
    }while(b < 2 || b > g);
    A = static_cast<int>(pow(g, a)) % p;
    B = static_cast<int>(pow(g, b)) % p;
    key1 = static_cast<int>(pow(B, a)) % p;
    key2 = static_cast<int>(pow(A, b)) % p;
    cout << "Ключ а:" << key1 << endl;
    cout << "Ключ b:" << key2 << endl;
}

int main(){
    Generate a, b;
    b.Task();
    return 0;
}