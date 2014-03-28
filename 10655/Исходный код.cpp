#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <cmath>
#include <sstream>


using namespace std;

long long p, q, n;
string s;
vector<vector<long long> > c(65, vector<long long>(65, 0));

vector<long long> a(65, -1);

void gen() {
	for (int i = 0; i < 65; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
}

long long binpow(long long a, int x) {
	long long res = 1;
	while (x) {
		if (x & 1) res *= a;
		a *= a;
		x >>= 1;
	}
	return res;
}

long long doAll(int cur_n) {
	if (a[cur_n] != -1) return a[cur_n];
	if (cur_n == 0) return 1;
	long long res = binpow(p, cur_n);
	for (int i = 1; i <= cur_n >> 1; ++i) {
		res -= c[cur_n][i] * binpow(q, i) * doAll(cur_n - 2 * i);
	}
	a[cur_n] = res;
	return res;
}


int main() {
	ifstream cin("input.txt"); ofstream cout("output.txt");
	gen();
	while (true) {
		getline(cin, s);
		if (s == "0 0") break;
		istringstream iss(s);
		iss >> p >> q >> n;
		if (p == 0 && n % 2 == 0) {
			cout << binpow(-1, n / 2) * 2 * binpow(q, n / 2) << endl;
			continue;
		}
		if (p == 0 && n % 2 != 0) {
			cout << 0 << endl;
			continue;
		}
		if (q == 0) {
			cout << binpow(p, n) << endl;
			continue;
		}
		if (p == 2 && q == 1) {
			cout << 2 << endl;
			continue;
		}
		if (n == 0) {
			cout << 2 << endl;
			continue;
		}
		a.clear(); a.resize(65, -1);
		cout << doAll(n) << endl;
	}

	return 0;
}