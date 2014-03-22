#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <numeric>

using namespace std;

string s = "";


int main() {
	ifstream cin("input.txt");ofstream cout("output.txt");
	while(true) {
		cin >> s;
		if (s == "#") break;
		if (!next_permutation(s.begin(), s.end())) cout << "No Successor" << endl;
		else cout << s << endl;
	}
	

	return 0;
}