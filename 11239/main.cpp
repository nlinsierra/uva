#include<iostream>
#include<fstream>
#include<sstream>
#include <map>
#include <string>
#include <stack>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

map<string, map<string, int> > Projects;
map<string, map<string, int> > Students;

bool pred(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}


int main() {
	ifstream cin("input.txt"); ofstream cout("output.txt");
	string last_project = "";
	vector<pair<int, string> > result;
	while (true) {
		string s;
		getline(cin, s);
		if (s == "0") break;
		if (s == "1") {
			for (auto it = Projects.begin(); it != Projects.end(); ++it) {
				int count = it->second.size();
				for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
				if (Students[it2->first].size() != 1) --count;
				result.push_back(make_pair(count, it->first));
			}
			sort(result.begin(), result.end(), pred);
			for (int i = 0; i < result.size(); ++i)
				cout << result[i].second << " " << result[i].first << endl;
			Projects.clear();
			Students.clear();
			result.clear();
			continue;
		}
		if (s[0] >= 'A' && s[0] <= 'Z') {
			last_project = s;
			Projects[last_project] = map<string, int>();
		}
		else {
				Students[s][last_project]++;
				Projects[last_project][s]++;
		}		
	}	
	
	return 0;
}