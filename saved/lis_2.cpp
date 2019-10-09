// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = "; _dbg(__VA_ARGS__);
#define debuga(arr, n) _dbga(arr, n, #arr)
#else
#define debug(...)
#define debuga(arr, n)
#endif
typedef long long int ll;
#define int ll
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

int dp[10];

int32_t main(){
	fast_io();
	
	vi vec = {9, 4, 7, 5, 1, 6, 0, 10};
	int n = vec.size();

	debug(vec);

	cout << "ALGO 1\n";
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if(vec[i] > vec[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
		debuga(dp,n);
	}

	cout << "ALGO 2\n";
	set<int> st;
	set<int>::iterator it;
	for (int i = 0; i < n; ++i) {
		st.insert(vec[i]);
		it = st.find(vec[i]);
		it++;
		if(it != st.end())
			st.erase(it);
		debug(st);
	}

	return 0;
}