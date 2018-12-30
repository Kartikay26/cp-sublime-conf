// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#include "prettyprint.hpp"
#define debug(...) cout << "debug: " << #__VA_ARGS__ " = " << make_tuple(__VA_ARGS__) << endl
#define debuga(arr, n) dbga(arr, n, #arr)
#else
#define debug(...)
#define debuga(arr, n)
#endif
typedef long long int ll;
#define int ll
template<typename T> void dbga(T* a, int n, string s){
	cout << "debug: " << s << " = [";
	while(n--){cout << *a++ << (n?", ":"");} cout << "]\n";
}
#define F first
#define S second
#define float double
const int inf = LLONG_MAX;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

char a[N];

int32_t main(){
	fast_io();
	// TECHNIQUE: COORDINATE COMPRESSION
	int n; cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}
	set<int> s(all(vec));
	map<int, int> mp;
	int cnt = 1;
	for(auto x: s){
		mp[x] = cnt++;
	}
	for(auto &x: vec){
		x = mp[x];
	}
	cout << vec;
}