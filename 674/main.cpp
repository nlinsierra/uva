#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>

using namespace std;

const int TypesNum = 5;

int Coins[TypesNum] = {1, 5, 10, 25, 50};
int Cents;
vector<vector<int> > Results(8000, vector<int>(TypesNum, -1));

int getMaxIdx(int v) {
	for (int i = 0; i < TypesNum; ++i) if (Coins[i] > v) return i;
	return TypesNum;
}

int doAll(int CurCents, int MaxIdx) {
	if (CurCents < Coins[MaxIdx]) return 0;
	if (CurCents == Coins[MaxIdx]) Results[CurCents][MaxIdx] = 1;
	if (MaxIdx == 0) Results[CurCents][MaxIdx] = 1;
	if (Results[CurCents][MaxIdx] != -1) return Results[CurCents][MaxIdx];
	int Res = 0;
	for (int i = 0; i <= MaxIdx; ++i) Res += doAll(CurCents - Coins[MaxIdx], i);
	Results[CurCents][MaxIdx] = Res;
	return Res;
}


int main() {
	ifstream cin("input.txt");ofstream cout("output.txt");
	
	while(!cin.eof()) {
		cin >> Cents;
		if (cin.eof()) break;
		int Sum = 0;
		for (int i = 0; i < TypesNum; ++i) Sum += doAll(Cents, i);
		cout << Sum << endl;
	}

	return 0;
}