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
	cout << "debug: " << s << "= [";
	while(n--){cout << *a++ << (n?", ":"");} cout << "]\n";
}
#define F first
#define S second
typedef vector<int> vi;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int N = 1e6+1;

int sumMultiplesToN(int k, int n){
	int p = n/k;
	// sum of p natural numbers
	return p*(p+1)/2 * k;
}

int32_t main(){
	fast_io();
	// test:
	// cout << sumMultiplesToN(1, 10) << endl; // should be 55
	// cout << sumMultiplesToN(2, 10) << endl; // should be 30
	cout << sumMultiplesToN(3, 1000) + sumMultiplesToN(5, 1000) - sumMultiplesToN(15, 1000) << endl;
}