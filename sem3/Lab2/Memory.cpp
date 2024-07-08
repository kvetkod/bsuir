#include"Memory.h"

Memory::Memory(int all_) {
	all = free = all_;
}

void Memory::MemoryCapture(int n) {
	free -= n;
}

void Memory::Information(){
	cout << "All you memory:" << all << endl;
	cout << "Free:" << free << endl;
}

int Memory::GetFree() {
	return free;
}