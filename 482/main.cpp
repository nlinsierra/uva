#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <numeric>
#include <sstream>

using namespace std;


bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}


int main() {
	ifstream cin("input.txt");ofstream cout("output.txt");
	int n;
	string s;
	cin >> n;
	getline(cin, s);
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		string s1, s2, s;
		int idx;
		getline(cin, s1); getline(cin, s2);
		istringstream ss1(s1), ss2(s2);
		vector<pair<int, string> > a;
		while (!ss1.eof()) {
			ss1 >> idx;
			ss2 >> s;
			a.push_back(make_pair(idx, s));
		}
		sort(a.begin(), a.end(), cmp);
		for_each(a.begin(), a.end(), [&cout](pair<int, string> v) {
			cout << v.second << endl;
		});
		if (i != n - 1) cout << endl;
	}


	return 0;
}