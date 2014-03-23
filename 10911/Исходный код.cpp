#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;

vector<double> Dists(65536, -1);
vector<pair<double, double> > Coords;
int n = 0;

bool is_set(int i, int mask) {
	return ((mask & (1 << i)) >> i);
}

void set(int i, int &mask) {
	mask |= (1 << i);
}

void unset(int i, int &mask) {
	mask ^= (1 << i);
}

bool is_all(int mask) {
	return mask == (1 << 2*n) - 1;
}

double calc_dist(int mask) {
	if (is_all(mask)) return 0.0;
	if (Dists[mask] != -1) return Dists[mask];
	double dist = 0.0, cur_dist = 0.0, cur_min_dist = 1e10;
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = i + 1; j < 2 * n; ++j) {
			if (i != j && !is_set(i, mask) && !is_set(j, mask)) {
				dist = sqrt((Coords[i].first - Coords[j].first)*(Coords[i].first - Coords[j].first) + (Coords[i].second - Coords[j].second)*(Coords[i].second - Coords[j].second));
				set(i, mask); set(j, mask);
				cur_dist = dist + calc_dist(mask);
				if (cur_dist < cur_min_dist) cur_min_dist = cur_dist;
				unset(i, mask); unset(j, mask);				
			}
		}
	}
	Dists[mask] = cur_min_dist;
	return Dists[mask];
}

int main() {
	ifstream cin("input.txt"); ofstream cout("output.txt");
	int count = 0;
	while (!cin.eof()) {
		++count;
		cin >> n;
		if (n == 0) break;
		Dists.clear();
		Dists.resize(65536, -1);
		Coords.clear();
		string name;
		double x, y;
		for (int i = 0; i < 2 * n; ++i) {
			cin >> name >> x >> y;
			Coords.push_back(make_pair(x, y));
		}
		cout << "Case " << count << ": " << fixed << setprecision(2) << calc_dist(0) << endl;
	}
	
	return 0;
}