#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>

using namespace std;

int N, val = 1;
vector<int> Cubes(21);
vector<vector<long long> > Results(10010, vector<long long>(21, -1));

int gen() { return val*val*(val++); }

int getMaxIdx(int v) {
	for (int i = 0; i < Cubes.size(); ++i) if (Cubes[i] > v) return i;
	return Cubes.size() - 1;
}

long long doAll(int Sum, int MaxValIdx) {
	if (Sum < Cubes[MaxValIdx]) return 0;
	if (Sum == Cubes[MaxValIdx]) Results[Sum][MaxValIdx] = 1;		
	else if (MaxValIdx == 0) Results[Sum][MaxValIdx] = 1;		
	if (Results[Sum][MaxValIdx] != -1) return Results[Sum][MaxValIdx];
	long long Res = 0;
	for (int i = 0; i <= MaxValIdx; ++i) 
		Res += doAll(Sum - Cubes[MaxValIdx], i);
	Results[Sum][MaxValIdx] = Res;
	return Res;
}

int main() {
	ifstream cin("input.txt");ofstream cout("output.txt");
	generate(Cubes.begin(), Cubes.end(), gen);
	while (!cin.eof()) {		
		cin >> N;
		if (cin.eof()) break;
		long long SumCount = 0;			
		for (int i = 0; i < Cubes.size(); ++i) SumCount += doAll(N, i);
		cout << SumCount << endl;
	}

	return 0;
}