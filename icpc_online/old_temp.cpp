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


void testcase(int t){
	int n, k;
	cin >> n >> k;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(all(a));
	int start = 0, end = n-2;
	debug(start,end,a);
	while(start < end-1){
		while(a[start]<=k and start < end){
			start++;
		}
		if (start == end) {
			break;
		}
		int &x = a[start];
		int &y = a[end];
		int new_ = y - x + k;
		x = k;
		y = new_;
		if(new_ <= k){
			end--;
		}
		debug(start,end,a);
	}
	if (a[end] > k) {
		int &x = a[end];
		int &y = a[n-1];
		int new_ = y - x + k;
		x = k;
		y = new_;
	}
	int max_sum = accumulate(all(a), 0);
	cout << max_sum << endl;
}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		testcase(i);
	}
}