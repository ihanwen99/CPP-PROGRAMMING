#include<iostream>
using namespace std;

#include<vector>
class Josephus {
	int n, m;
	vector<int> people;
public:
	Josephus(int nn, int mm) :n(nn), m(mm) {
		for (int i = 1; i <= nn; i++) { people.push_back(i); }
	}

	void simulate() {
		int pos = 0;
		pos = (pos + this->m) % people.size();
		cout << people[pos] << endl;
		people.erase(people.begin() + pos);

		while (!people.empty()) {
			pos = (pos + this->m-1) % people.size();
			cout << people[pos] << endl;
			people.erase(people.begin() + pos);
		}
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	Josephus obj(n, m);
	obj.simulate();
	return 0;
}