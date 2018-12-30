/*
 * RBTREE NODES
 */

#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#else
#define debug(...) 0
#endif
typedef long long int lli;
#define int lli
typedef vector<int> vi;
typedef pair<int, int> pii;

void testcase(int t){
	string s;
	cin >> s;
	vector<pii> robots;
	for (int i = 0; i < int(s.size()); ++i) {
		char x = s[i];
		if(x!='.') robots.push_back({i+1, s[i]-'0'});
	}
	for (int i = 0; i < int(robots.size()-1); ++i) {
		pii r1 = robots[i];
		pii r2 = robots[i+1];
		int r1_right = min(r1.first + r1.second, int(s.size()));
		int r2_left = max(r2.first - r2.second, 1ll);
		if (r1_right >= r2_left) {
			cout << "unsafe" << endl;
			return;
		}
	}
	cout << "safe" << endl;
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		testcase(i);
	}
}