#include <iostream> 
#include <string> 
#include <vector> 
#include<fstream> 
using namespace std;
int GetSizeFromFile(string FileName, int x) {
    int i, j;
    char str[255];
    ifstream file("example\\" + FileName + ".txt", ios::out);
    if (!file.is_open()) {
        cout << "Error opening the file\n";
    }
    file.getline(str, 255);
    char* buf;
    char* Tem = NULL;
    buf = strtok_s(str, " \n", &Tem);
    int prom[255];
    i = 0;
    while (buf != NULL) {
        prom[i] = atoi(buf);
        i++;
        buf = strtok_s(NULL, " \n", &Tem);
    }
    return prom[x];
}
int GetElements(string FileName, int x, int y) {
    int i, j;
    char str[255];
    ifstream file("example\\" + FileName + ".txt", ios::out);
    if (!file.is_open()) {
        cout << "Error opening the file\n";
    }
    file.getline(str, 255);
    char* buf;
    char* Tem = NULL;
    buf = strtok_s(str, " \n", &Tem);
    int prom[255];
    i = 0;
    while (buf != NULL) {
        prom[i] = atoi(buf);
        i++;
        buf = strtok_s(NULL, " \n", &Tem);
    }
    int n, m, k; k = 2;
    n = prom[0];
    m = prom[1];
    int** a;
    a = new int* [n];
    for (i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = prom[k];
            k++;
        }
    }
    int p = a[x][y];
    return p;
    for (i = 0; i < n; i++) {
        delete[]a[i];
    }
    delete[]a;
}
string WhatFile() {
    cout << "Choose file: \n 1. ex1.txt \n 2. ex2.txt  \n 3. ex3.txt \n 4. ex4.txt \n ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {return "ex1"; break; }
    case 2: {return "ex2"; break; }
    case 3: {return "ex3"; break; }
    case 4: {return "ex4"; break; }
    }
}
int main() {
    int i, j, n, n1, n2, m, k, choice;
    int prom1[255];
    string File1;
    string File2;
    File1 = WhatFile();
    File2 = WhatFile();
    n1 = GetSizeFromFile(File1, 0);
    m = GetSizeFromFile(File1, 1);
    n2 = GetSizeFromFile(File2, 0);
    k = GetSizeFromFile(File2, 1);
    int** a, ** b;

    a = new int* [n1];
    for (i = 0; i < n1; i++) {
        a[i] = new int[m];
    }
    for (i = 0; i < n1; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = GetElements(File1, i, j);
        }
    }
    b = new int* [n2];
    for (i = 0; i < n2; i++) {
        b[i] = new int[k];
    }
    for (i = 0; i < n2; i++) {
        for (j = 0; j < k; j++) {
            b[i][j] = GetElements(File2, i, j);
        }
    }
    cout << "first graph:" << endl;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << "second graph:" << endl;
    for (i = 0; i < n2; i++) {
        for (j = 0; j < k; j++) {
            cout << b[i][j];
        }
        cout << endl;
    }
    if (n1 > n2 || n1 == n2) {
        n = n1;
    }
    else if (n1 < n2) {
        n = n2;
    }
    int p = 2 * m, s = 2;
    vector<vector<int>>c(p, vector<int>(s));
    for (i = 0; i < p; i++) {
        for (j = 0; j < s; j++) {
            c[i][j] = 0;
        }
    }
    int q = 2 * k;
    vector<vector<int>>d(q, vector<int>(s));


    int w = 0, z = 0;
    for (i = 0; i < m; i++) {
        w = 0;
        for (j = 0; j < n1; j++) {
            if (a[j][i] == 1) {
                c[z][w] = j + 1;

                w++;
            }
            if (a[j][i] == 2) {
                c[z][w] = j + 1;
                c[z][w + 1] = j + 1;
            }
        }
        z++;
    }
    for (j = m - 1; j > -1; j--) {
        w = 0;
        for (i = n1 - 1; i > -1; i--) {
            if (a[i][j] == 1) {
                c[z][w] = i + 1;
                w++;
            }
            if (a[i][j] == 2) {
                c[z][w] = i + 1;
                c[z][w + 1] = i + 1;
            }
        }
        z++;
    }


    z = 0;
    for (i = 0; i < k; i++) {
        w = 0;
        for (j = 0; j < n2; j++) {
            if (b[j][i] == 1) {
                d[z][w] = j + 1;

                w++;
            }
            if (b[j][i] == 2) {
                d[z][w] = j + 1;
                d[z][w + 1] = j + 1;
            }
        }
        z++;
    }
    for (j = k - 1; j > -1; j--) {
        w = 0;
        for (i = n2 - 1; i > -1; i--) {
            if (b[i][j] == 1) {
                d[z][w] = i + 1;
                w++;
            }
            if (b[i][j] == 2) {
                d[z][w] = i + 1;
                d[z][w + 1] = i + 1;
            }
        }
        z++;
    }


    int v = pow((p + q), 2);
    vector<vector<int>>e(v, vector<int>(s));
    for (i = 0; i < v; i++) {
        for (j = 0; j < s; j++) {
            e[i][j] = 0;
        }
    }
    int h = 0, g = 0;
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            if (c[i][1] == d[j][0]) {
                e[h][g] = c[i][0];
                g++;
                e[h][g] = d[j][1];
                h++;
                g = 0;
            }
        }
    }
    for (i = 0; i < v; i++) {
        for (j = 0; j < s; j++) {
            if (e[i][j] == 0) {
                e.erase(e.begin() + i);
                v--;
                i--;
            }
        }
    }

    z = v;
    vector<vector<int>>f(z, vector<int>(s));
    for (i = 0; i < z; i++) {
        for (j = 0; j < s; j++) {
            f[i][j] = e[i][j];
        }
    }

    int l = 0; g = 1;
    bool met = false;
    for (i = 0; i < v; i++) {
        met = false;
        for (j = 0; j < z; j++) {
            if ((e[i][l] == f[j][l] && e[i][g] == f[j][g]) || (e[i][l] == f[j][g] && e[i][g] == f[j][l])) {
                if (met) {
                    f.erase(f.begin() + j);
                    z--;
                }
                else {
                    met = true;
                }
            }
        }
    }
    int** result;
    result = new int* [n];
    for (i = 0; i < n; i++) {
        result[i] = new int[z];
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < z; j++) {
            result[i][j] = 0;
        }
    }
    w = 0; g = 0;
    for (i = 0; i < z; i++) {
        for (j = 0; j < s; j++) {
            result[f[i][j] - 1][g] += 1;

        }
        g++;
    }
    cout << "result:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < z; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }



    for (i = 0; i < n2; i++) {
        delete[]b[i];
    }
    for (i = 0; i < n1; i++) {
        delete[]a[i];
    }
    for (i = 0; i < n; i++) {
        delete[]result[i];
    }
    delete[]a; delete[]b; delete[]result;
}