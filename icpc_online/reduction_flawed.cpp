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

const int N = 1e6+1;

void deleteOne(multiset<int> &m, int a){
	if (m.count(a) >= 1) {
		int c = m.count(a);
		m.erase(a);
		c--;
		for (int i = 0; i < c; ++i) {
			m.insert(a);
		}
	}
}

void testcase(int t){
	int n, k;
	cin >> n >> k;
	multiset<int> mst;
	int maxs = 0;
	if (n == 1) {
		int x; cin >> x; maxs = x;
		cout << maxs << endl;
		return;
	}
	if (n == 2) {
		int x,y; cin >> x >> y;
		if(y<x) swap(x,y);
		if(x<=k){
			cout << x+y << endl;
		} else {
			cout << k+y-x+k << endl;
		}
		return;
	}
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x <= k) {
			maxs += x;
		} else {
			mst.insert(x);
		}
	}
	debug(mst);
	while(mst.size() >= 3){
		auto it = mst.end();
		--it;
		auto it_x = (--it);
		auto it_y = (--it);
		int x = *it_x;
		int y = *it_y;
		int b = x-y+k;
		deleteOne(mst, x);
		deleteOne(mst, y);
		maxs += k;
		if(b>k){
			mst.insert(b);
		} else {
			maxs += b;
		}
		debug(x,y,b);
		debug(mst);
	}
	int last = *(mst.begin());
	maxs += last;
	cout << maxs << endl;
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		testcase(i);
	}
}