#include"Processor.h"


Processor::Processor(string model_, int cores_, int speed_, int cachememory_) {
	model = model_;
	speed = speed_;
	cores = cores_;
	cachememory = cachememory_;
}

void Processor::Information() {
	cout << "Model:" << model << endl;
	cout << "Speed:" << speed << endl;
	cout << "Count of cores:" << cores << endl;
}
void Processor::IncreaseSpeed(int n) {
	speed =speed+ n;
}
void Processor::ReduceSpeed(int n) {
	speed -= n;
}

int Processor::GetSpeed() {
	return speed;
}