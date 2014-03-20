#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int N = 0;
vector<vector<int> > Heights;
int x = 0, y = 0, MaxLength = 0;
string Name;

void doAll(int i, int j, int CurLength) {
	if (Heights[i][j] == -1) return;
	if (i > x || j > y) return;
	CurLength += 1;
	MaxLength = max(MaxLength, CurLength);
	if (Heights[i][j] < Heights[i-1][j]) doAll(i-1, j, CurLength);
	if (Heights[i][j] < Heights[i][j-1]) doAll(i, j-1, CurLength);
	if (Heights[i][j] < Heights[i+1][j]) doAll(i+1, j, CurLength);
	if (Heights[i][j] < Heights[i][j+1]) doAll(i, j+1, CurLength);
}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	
	cin >> N;
	for (int test = 0; test < N; ++test) {
		
		MaxLength = 0;
		cin >> Name >> x >> y;
		Heights.resize(0);
		Heights.resize(x + 2, vector<int>(y + 2, -1));
		for (int i = 1; i <= x; ++i)
			for (int j = 1; j <= y; ++j) {
				cin >> Heights[i][j];				
			}
		for (int i = 1; i <= x; ++i)
			for (int j = 1; j <= y; ++j) {
				doAll(i, j, 0);
			}
		cout << Name << ": " << MaxLength << endl;
	}

	return 0;
}