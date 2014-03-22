#include<iostream>
#include<fstream>
#include<sstream>
#include <map>
#include <string>
#include <stack>
#include <vector>
#include <iterator>

using namespace std;

int pos = 0;
vector<int> toys;
stack<int> nests;

vector<vector<int> > lns;

int move(int cur_toy) {
	int sum = 0;
	++pos;
	while (pos != toys.size() && toys[pos] != -cur_toy) {
		if (toys[pos] < 0) {
			int cur_res = move(toys[pos]);
			if (cur_res == -1) return -1;
			sum += cur_res;
			++pos;
		}
		else return -1;
	}
	if (sum >= -cur_toy) return -1;
	return -cur_toy;
}

int main() {
	ifstream cin("input.txt"); ofstream cout("output.txt");
	
	while (!cin.eof()) {
		string s;
		getline(cin, s);
		if (cin.eof()) break;
		istringstream iss(s);
		istream_iterator<int> it(iss), eos;
		toys.clear();		
		copy(it, eos, back_inserter(toys));
		pos = 0;
		if (toys[0] > 0) cout << ":-( Try again." << endl;
		else if (move(toys[0]) != -1) cout << ":-) Matrioshka!" << endl;
		else cout << ":-( Try again." << endl;
	}
	
	
	return 0;
}