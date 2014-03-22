#include<iostream>
#include<fstream>
#include<sstream>
#include <map>
#include <string>

using namespace std;

int n = 0, cnt = 0, pos = 0;
string s, result = "error";
map<char, pair<int, int> > m;

pair<int, int> expr() {
	pair<int, int> m1, m2;
	if (s[pos] == '(') {
		++pos; 
		m1 = expr(); 
		++pos;
		m2 = expr();
		++pos;
		if (m1.second != m2.first) result = "error";
		cnt += m1.first*m1.second*m2.second;
		return make_pair(m1.first, m2.second);
	}
	else return m[s[pos]];
}

int main() {
	ifstream cin("input.txt"); ofstream cout("output.txt");

	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		m[c] = make_pair(x,y);
	}
	while (!cin.eof()) {
		cnt = 0; result = ""; pos = 0;
		cin >> s;
		if (cin.eof()) break;
		expr();
		if (result == "error") cout << "error" << endl;
		else cout << cnt << endl;
	}
	return 0;
}