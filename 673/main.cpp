#include<iostream>
#include<fstream>
#include<sstream>
#include <map>
#include <string>
#include <stack>

using namespace std;

int n = 0;

bool check(string s) {
	stack<char> parenthes;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(' || s[i] == '[') parenthes.push(s[i]);
		else if (s[i] == ')' && !parenthes.empty() && parenthes.top() == '(') parenthes.pop();
		else if (s[i] == ']' && !parenthes.empty() && parenthes.top() == '[') parenthes.pop();
		else return false;
	}
	if (!parenthes.empty()) return false;
	return true;
}

int main() {
	ifstream cin("input.txt"); ofstream cout("output.txt");
	string s;
	cin >> n;
	getline(cin, s);
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		if (check(s)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}