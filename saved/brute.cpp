// kartikay26
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
typedef long long int ll;
#define int ll
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, k;
vi a;
vi ans;
int m = -1;

void brute(int start, int sum_built = 0){
	if (start < k) {
		for (int i = 1; i < n; ++i) {
			int used = 0;
			for (int j = 0; j < start; ++j) {
				if(a[j] == i){ used = 1; break; }
			}
			if(used) continue;
			a[start] = i;
			brute(start+1, sum_built+i);
			if (sum_built+i > n) {
				return;
			}
		}
	} else {
		if (sum_built == n) {
			int z = 1;
			for(auto i : a){
				z *= (i*i - i);
			}
			if(z>m){
				ans = a;
				m = z;
			}
		}
	}
}

int32_t main(){
	fast_io();
	cin >> n >> k;
	a.resize(k);
	brute(0);
	cout << "Ans: [";
	for(auto i : ans){
		cout << i << ", ";
	}
	cout << "] Product: ";
	cout << m << endl;
}