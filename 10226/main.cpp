#include<iostream>
#include<fstream>
#include<sstream>
#include <map>
#include <string>
#include <stack>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>

using namespace std;

int n = 0;
map<string, int> Trees;


int main() {
	ifstream cin("input.txt"); ofstream cout("output.txt");
	string s;

	cin >> n;
	getline(cin, s);
	getline(cin, s);
	for (int i = 0; i < n; ++i) {
		int count = 0;
		Trees.clear();
		while (true) {
			getline(cin, s);
			if (s == "") break;
			if (cin.eof()) break;
			Trees[s]++;
			count++;
		}
		for (auto it = Trees.begin(); it != Trees.end(); ++it)
			cout << it->first << " " << fixed << setprecision(4) << double(it->second) * 100.0 / double(count) << endl;
		if (i != n - 1)cout << endl;
	}	
	
	return 0;
}