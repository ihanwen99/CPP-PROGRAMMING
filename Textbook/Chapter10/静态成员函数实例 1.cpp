#include<iostream>
using namespace std;

class goods {
	int curr_weight;
	static int total_weight;
public:
	goods(int w);
	~goods();
	int weight();
	static int totalweight();
};

int goods::total_weight = 0;

goods::goods(int w) {
	curr_weight = w;
	total_weight += w;
}

goods::~goods() {
	total_weight -= curr_weight;
}
int goods::weight() {
	return curr_weight;
}

int goods::totalweight() {
	return total_weight;
}

int main() {
	goods g(1);
	cout << g.weight() << ' ' << g.totalweight() << endl;
	return 0;
}