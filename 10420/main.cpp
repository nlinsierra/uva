#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>

using namespace std;

int n = 0;
map<string, int> WomenCount;


int main() {
	ifstream cin("input.txt");ofstream cout("output.txt");
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		WomenCount[s]++;
		getline(cin, s);
	}
	for (auto it = WomenCount.begin(); it != WomenCount.end(); ++it) cout << it->first << " " << it->second << endl;

	return 0;
}