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
lli n;
vector<string> v;

string find_string(vector<string> v)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0; j<n;j++){
			if(v[j][0]){}
		}
	}
	return s;
}

void testcase(int t){
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		v.push_back(s);
	}

	if(n<=4)
	{
		check(v);
		for(int i=0;i<4-n;i++)
		{
			printf("AAAA\n");
		}
		for(int i=0;i<v.size();i++)
		{
			sort(v.begin,v.end());
			cout<<v[i]<<endl;
		}
		cout<<endl;
	}

	else
	{
		s=find_string(v);
		cout<<s<<endl;
	}

}

int32_t main(){
	fast_io();
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		testcase(i);
	}
}