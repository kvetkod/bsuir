#include"Arr.h"
#include<algorithm>

void Arr::Add(string e) {
	if (e[0] == '{' || e[0] == '<') {
		string b = e;
		sort(e.begin(), e.end());
		for (int i = 0; i < e.length(); i++) {
			if (e[i] == '{' || e[i] == '}' || e[i] == ',' || e[i] == '<' || e[i] == '>') {
				e.erase(i, 1);
				i--;
			}
		}
		int j = 0;
		for (int i = 0; i < b.length(); i++) {
			if ((b[i] >= 'a' && b[i] <= 'z') || (b[i] >= '0' && b[i] <= '9')) {
				b[i] = e[j];
				j++;
			}
		}
		info.push_back(b);
	}
	else info.push_back(e);
}
void Arr::Print() {
	cout << "{";
	for (int i = 0; i < info.size(); i++) {
		cout << info[i];
		if (i == info.size() - 1) break;
		else cout << ", ";
	}
	cout << "};" << endl;
}
int Arr::contains(string e) {
	int n=0;
	for (int i = 0; i < info.size(); i++) {
		if (info[i] == e) n++;
	}
	return n;
}
void Arr::Del(string e, int i, int& v) {
	if (i == v - 1) return;
	int p = 1;
	for (int j = i+1; j < v; j++) {
		if (e == info[j]) {
			for (int k = j; k < v; k++) {
				if (k == v - 1) info.erase(info.end() - 1);
				else {
					info[k] = info[k + 1];
				}
			}
			v--; j--;

		}
	}
}
void Arr::SummetricDifference(Arr set) {
	Arr result; int v = info.size(), l = set.info.size(), p = 0;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < l; j++) {
			if (info[i] == set.info[j]) {
				p = 1;
				if (contains(info[i]) != set.contains(set.info[j])) {
					int n;
					n = abs(contains(info[i]) - set.contains(set.info[j]));
					for (int k = 0; k < n; k++) {
						result.Add(info[i]);
					}
				}
				Del(info[i], i, v);
				set.Del(info[j], j, l);
			} 
		
		}
		if (p == 0) {
			result.Add(info[i]);
		}
		p = 0;
	}
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < v; j++) {
			if (set.info[i] == info[j]) {
				p = 1;
				if (contains(set.info[i]) != set.contains(info[j])) {
					int n;
					n = abs(contains(set.info[i]) - set.contains(info[j]));
					for (int k = 0; k < n; k++) {
						result.Add(set.info[i]);
					}
				}
				set.Del(info[i], i, l);
				Del(info[j], j, v);
			}

		}
		if (p == 0) {
			result.Add(set.info[i]);
		}
		p = 0;
	}
	result.Print();
}
bool Arr::check(string e) {
	if (info.size() == 0) return true;
	for (int i = 0; i < info.size(); i++) {
		if (e == info[i]) return false;
	}
	return true;
}

int Arr::Max_C(vector<int>counter) {
	int max = 0;
	for (int i = 0; i < counter.size(); i++) {
		if (max < counter[i]) {
			max = counter[i];
		}
	}
	return max;
}
int Arr::Min_C(vector<int>counter) {
	int min = Max_C(counter);
	for (int i = 0; i < counter.size(); i++) {
		if (min > counter[i]) {
			min = counter[i];
		}
	}
	return min;
}
Arr Arr::Union(vector<Arr>set) {
	Arr rez;
	int size = set.size(), s1 = set[0].info.size(), s2;
	vector<int>counter(size); string e; int l = 0;
	for (int i = 0; i < set.size(); i++) {
		s1 = set[i].info.size();
		for (int j = 0; j < s1; j++) {
			for (int k = 0; k < size; k++) {
				counter[k] = 0;
			}
			e = set[i].info[j];
			counter[i] = set[i].contains(e);
			set[i].Del(e, j, s1);
			for (int k = 0; k < set.size(); k++) {
				if (k != i) {
					s2 = set[k].info.size();
					for (int a = 0; a < s2; a++) {
						if (set[k].info[a] == e) {
							counter[k] = set[k].contains(e);
							set[k].Del(e, a, s2);
						}
					}
				}
			}
				if (rez.check(e)) {
					for (int a = 0; a < Max_C(counter); a++) {
						rez.Add(e);
					}
				}
		}
	}
	return rez;
}

Arr Arr::Cross(vector<Arr>set) {
	Arr rez;
	int size = set.size(), s1 = set[0].info.size(), s2;
	vector<int>counter(size); string e; int l = 0;
	for (int i = 0; i < set.size(); i++) {
		s1 = set[i].info.size();
		for (int j = 0; j < s1; j++) {
			for (int k = 0; k < size; k++) {
				counter[k] = 0;
			}
			e = set[i].info[j];
			counter[i] = set[i].contains(e);
			set[i].Del(e, j, s1);
			for (int k = 0; k < set.size(); k++) {
				if (k != i) {
					s2 = set[k].info.size();
					for (int a = 0; a < s2; a++) {
						if (set[k].info[a] == e) {
							counter[k] = set[k].contains(e);
							set[k].Del(e, a, s2);
						}
					}
				}
			}
			if (rez.check(/*set, */e)) {
				if (Min_C(counter) != 0) {
					for (int a = 0; a < Min_C(counter); a++) {
						rez.Add(e);
					}
				}
			}
			//rez.Print(rez.info.size());
		}
	}
	return rez;
}


void Arr::SummetricDifferences(vector<Arr>set) {
	Arr r1, r2;
	r1=r1.Union(set);
	r2=r2.Cross(set);
	r1.SummetricDifference(r2);
}