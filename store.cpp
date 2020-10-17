// kartikay26
#include <bits/stdc++.h>
using namespace std;
#define debug(x...) 
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
typedef long long int ll; typedef double db; typedef vector<ll> vi; typedef pair<ll, ll> pii;
#define int ll
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print(){cout << endl;} void prints(){}
template<typename T> void get(T* x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T> void get(T& x, int n){for (int i = 0; i < n; ++i) { cin >> x[i]; }}
template<typename T, typename... A> void print(T x,A... r){cout << x << " ";print(r...);}
template<typename T, typename... A> void prints(T x,A... r){cout << x << " ";prints(r...);}

const int mod = 1e9+7;
const int N = 1e3+1;

class DSU {
	public:
		vector<int> parent;
		vector<int> sizes;
		int nsets;
		DSU(int n):parent(n),sizes(n),nsets(n){
			for (int i = 0; i < n; ++i) {
				parent[i] = i; sizes[i] = 1;
			}
		}
		void join(int i, int j){
			i = find(i); j = find(j); if(i==j) return;
			if(sizes[i]<sizes[j]) swap(i,j);
			parent[i] = j;
			sizes[j] += sizes[i];
			nsets--;
		}
		int find(int i){
			while(i != parent[i])
				i = parent[i];
			return i;
		}
		int size(int i){
			i = find(i);
			return sizes[i];
		}
		bool compare(int i, int j){
			return find(i) == find(j);
		}
};

int n, m, k;
char grid[N][N];
bool vis[N][N];

DSU d(N*N);

int to_num(int x, int y){
	return x * m + y;
}

pair<int, int> to_coords(int num){
	return {num % m, num / m};
}

bool check_bounds(int i, int j){
	return (0 <= i and i < n and 0 <= j and j < m);
}

void dfs(int i, int j, int parent = -1){
	debug(i,j,parent);
	if (vis[i][j]){
		return;
	}
	vis[i][j] = 1;
	if (parent != -1){
		d.join(to_num(i, j), parent);
	}
	vector<pii> v = {{i+1, j}, {i,j+1}, {i-1,j}, {i, j-1}};
	for (auto [x, y] : v){
		if (check_bounds(x, y) and grid[x][y] == '.') dfs(x, y, to_num(i, j));
	}
}

void enter_grid(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			vector<pii> v = {{i+1, j}, {i,j+1}, {i-1,j}, {i, j-1}};
			int p = 0;
			for (auto [x, y] : v){
				if (check_bounds(x, y) and grid[x][y] == '*') p++;
			}
			d.sizes[to_num(i,j)] = p;
		}
	}
}


int32_t main(){
	fast_io();

	enter_grid();

	for (int i = 0; i < k; ++i) {
		int x, y; cin >> x >> y;
		x--; y--;
		dfs(x, y);
		int n = d.size(to_num(x, y));
		int ans = 0;
		cout << ans << endl;
	}

	return 0;
}