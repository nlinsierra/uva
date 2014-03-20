#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int n = 0, MinPebble = 12;
string Game;

bool pred(char c) { return c == 'o'; }

int Min(int a, int b) { return (a < b) ? a : b; };

void doAll(string CurGame) {
	for (int i = 0; i < 2; ++i)
		if (CurGame[i] == 'o' && CurGame[i+1] == 'o' && CurGame[i+2] == '-') {
			CurGame[i] = '-'; CurGame[i+1] = '-'; CurGame[i+2] = 'o';
			doAll(CurGame);
			CurGame[i] = 'o'; CurGame[i+1] = 'o'; CurGame[i+2] = '-';
		}
	for (int i = 2; i < CurGame.length() - 2; ++i) {
		if (CurGame[i] == 'o' && CurGame[i+1] == 'o' && CurGame[i+2] == '-') {
			CurGame[i] = '-'; CurGame[i+1] = '-'; CurGame[i+2] = 'o';
			doAll(CurGame);
			CurGame[i] = 'o'; CurGame[i+1] = 'o'; CurGame[i+2] = '-';
		}
		if (CurGame[i] == 'o' && CurGame[i-1] == 'o' && CurGame[i-2] == '-') {
			CurGame[i] = '-'; CurGame[i-1] = '-'; CurGame[i-2] = 'o';
			doAll(CurGame);
			CurGame[i] = 'o'; CurGame[i-1] = 'o'; CurGame[i-2] = '-';
		}
	}
	for (int i = CurGame.length() - 2; i < CurGame.length(); ++i) {		
		if (CurGame[i] == 'o' && CurGame[i-1] == 'o' && CurGame[i-2] == '-') {
			CurGame[i] = '-'; CurGame[i-1] = '-'; CurGame[i-2] = 'o';
			doAll(CurGame);
			CurGame[i] = 'o'; CurGame[i-1] = 'o'; CurGame[i-2] = '-';
		}
	}
	MinPebble = Min(MinPebble, count_if(CurGame.begin(), CurGame.end(), pred));
}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	
	cin >> n;
	for (int test = 0; test < n; ++test) {
		string Game;
		cin >> Game;
		MinPebble = 12;
		doAll(Game);
		cout << MinPebble << endl;
	}

	return 0;
}