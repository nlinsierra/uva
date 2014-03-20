#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>

using namespace std;

vector<int> Durations;
int N, k, MinUnused = 1e9, MinMask = 0;

int getBit(int i, int val) {
	return val & (1 << i);
}


int Sum(int Mask) {	
	int sum = 0;
	for (int i = 0; i < k; ++i) { 
		if (getBit(i, Mask)) sum += Durations[i];
	}
	return sum;
}

int main() {
	//ifstream cin("input.txt");ofstream cout("output.txt");
	
	while (!cin.eof()) {		
		cin >> N >> k;
		if (cin.eof()) break;
		MinUnused = 1e9;
		Durations.resize(k);
		for (int i = 0; i < k; ++i) cin >> Durations[i];
		for (int i = 0; i < (2 << k); ++i) {
			int sum = Sum(i);
			if (sum <= N && N - sum <= MinUnused) { MinUnused = N - sum; MinMask = i; }
		}		
		for (int i = 0; i < k; ++i) if (getBit(i, MinMask)) cout << Durations[i] << " ";
		cout << "sum:" << Sum(MinMask) << endl;
	}

	return 0;
}