#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>

using namespace std;

int n = 0;
int count = 0;
map<string, int> Phones;
int Letters[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, -1, 7, 7, 8, 8, 8, 9, 9, 9, -1};


int main() {
	ifstream cin("input.txt");ofstream cout("output.txt");
	cin >> n;
	for (int i = 0; i < n; ++i) {
		Phones.clear();
		int k = 0;
		string tmp;
		cin >> k;
		getline(cin, tmp);
		for (int j = 0; j < k; ++j) {
			string s = "", result = "";
			getline(cin, s);
			for (int  l = 0; l < s.length(); ++l) {
				if (s[l] >= 'A' && s[l] <= 'Z') result += char(Letters[s[l] - 'A'] + '0');
				else if (s[l] >= 'a' && s[l] <= 'z') result += char(Letters[s[l] - 'a'] + '0');
				else if (s[l] >= '0' && s[l] <= '9') result += s[l];
				if (result.length() == 3) result += '-';
			}

			Phones[result]++;		
		}
		int count = 0;
		for (auto it = Phones.begin(); it != Phones.end(); ++it) 
			if (it->second != 1) {
				cout << it->first << " " << it->second << endl;
				++count;
			}
		if (count == 0) cout << "No duplicates." << endl;
		if (i != n - 1) cout << endl;
	}
	

	return 0;
}