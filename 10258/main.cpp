#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
#include <numeric>
#include <sstream>

using namespace std;

string s = "";



vector<pair<int, map<int, pair<int, bool> > > > RankList;

bool problems_pred(pair<int, bool> v) { return v.second == true; }

int cnt_if(map<int, pair<int, bool> >::iterator begin, map<int, pair<int, bool> >::iterator end, bool (*cond)(pair<int, bool>)) {
	int count = 0;
	for (auto it = begin; it != end; ++ it)
		if (cond(it->second)) ++count;
	return count;
} 

int accumulate_if(map<int, pair<int, bool> >::iterator begin, map<int, pair<int, bool> >::iterator end, bool (*cond)(pair<int, bool>)) {
	int sum = 0;
	for (auto it = begin; it != end; ++ it)
		if (cond(it->second)) sum += it->second.first;
	return sum;
}

bool cmp(pair<int, map<int, pair<int, bool> > > a, pair<int, map<int, pair<int, bool> > > b) {
	int count1 = cnt_if(a.second.begin(), a.second.end(), problems_pred); 
	int count2 = cnt_if(b.second.begin(), b.second.end(), problems_pred); 
	if (count1 != count2) return count1 > count2;
	int sum1 = accumulate_if(a.second.begin(), a.second.end(), problems_pred);
	int sum2 = accumulate_if(b.second.begin(), b.second.end(), problems_pred);
	if (sum1 != sum2) return sum1 < sum2;
	return a.first < b.first;
}

int find_contestant(vector<pair<int, map<int, pair<int, bool> > > >::iterator begin, vector<pair<int, map<int, pair<int, bool> > > >::iterator end, int contestant) {
	for (auto it = begin; it != end; ++it) if (it->first == contestant) return it - begin;
	return -1;
}

int main() {
	ifstream cin("input.txt");ofstream cout("output.txt");
	int n;
	string s;
	cin >> n;
	getline(cin, s);
	getline(cin, s);
	for (int i = 0; i < n; ++i) {		
		int CurContestant, CurProblem, CurTime;
		char Type;
		istringstream ss;
		RankList.clear();
		do {
			getline(cin, s);
			if (s == "") break;
			ss.str(s);
			ss >> CurContestant >> CurProblem >> CurTime >> Type;
			int idx = find_contestant(RankList.begin(), RankList.end(), CurContestant);
			if (idx == -1) {
				RankList.push_back(make_pair(CurContestant, map<int, pair<int, bool> >()));
				idx = RankList.size() - 1;
			}
			switch (Type) {
			case 'C':				
				if (!RankList[idx].second[CurProblem].second) {			
					RankList[idx].second[CurProblem].first += CurTime;
					RankList[idx].second[CurProblem].second = true;
				}				
				break;
			case 'I':
				if (!RankList[idx].second[CurProblem].second) RankList[idx].second[CurProblem].first += 20;
				break;
			default: 
				break;
			}
		} while (s != "");
		sort(RankList.begin(), RankList.end(), cmp);
		for (auto it = RankList.begin(); it != RankList.end(); ++it) {
			int count = cnt_if(it->second.begin(), it->second.end(), problems_pred);
			int penalty = accumulate_if(it->second.begin(), it->second.end(), problems_pred);
			cout << it->first << " " << count << " " << penalty << endl;
		}
		if (i != n - 1) cout << endl;
	}


	return 0;
}