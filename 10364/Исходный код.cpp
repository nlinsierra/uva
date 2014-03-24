#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <tuple>
#include <cmath>
#include <sstream>


using namespace std;

vector<int> sticks(0);

vector<int> states(0);

int n = 0, m = 0, side_sum = 0;

bool is_set(int i, int mask) {
	return mask & (1 << i);
}

void set(int i, int &mask) {
	mask |= (1 << i);
}

void unset(int i, int &mask) {
	mask ^= (1 << i);
}

bool is_all_set(int mask) {
	return mask == (1 << m) - 1;
}

int doAll(int mask, int sum, int side_count) {	
	if (states[mask] != -1) return states[mask];
	if (side_count > 4) states[mask] = false;
	else if (sum == 0 && is_all_set(mask) && side_count == 4) states[mask] = true;
	else if (sum == 0 && !is_all_set(mask)) states[mask] = doAll(mask, side_sum, side_count + 1);
	else {
		for (int i = 0; i < m; ++i) {
			if (!is_set(i, mask) && sticks[i] <= sum) {
				set(i, mask);
				if (doAll(mask, sum - sticks[i], side_count)) {
					states[mask] = true;
					return true;
				}
				unset(i, mask);
			}
		}
		states[mask] = false;
	}
	return states[mask];
}


int main() {
	ifstream cin("input.txt"); ofstream cout("output.txt");
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		sticks.resize(m);
		states.clear();
		states.resize(1 << m, -1);
		for (int j = 0; j < m; ++j) cin >> sticks[j];
		int sum = accumulate(sticks.begin(), sticks.end(), 0);
		if (sum % 4 != 0) {
			cout << "no" << endl;
			continue;
		}
		side_sum = sum / 4;
		if (doAll(0, side_sum, 1)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}