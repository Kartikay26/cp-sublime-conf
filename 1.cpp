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
const int N = 1e6+1;

int v, e;
map<int, vector<int>> graph;

int extra_edges = 0;
int connected = 0;

set<int> vis;

void dfs(int x, int p = -1){
    connected++;
    vis.insert(x);
    for (int y : graph[x]) {
        if (y == p) {
            continue;
        }
        if (vis.count(y)) {
            debug(x,y);
            extra_edges++;
        } else {
            dfs(y, x);
        }
    }
}


int32_t main(){
    cin >> v >> e;

    for (int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> comps;

    for (int i = 1; i <= v; ++i) {
        connected = 0;
        if(!vis.count(i))
        {
            dfs(i);
            comps.push_back(connected);
        }
    }

    sort(comps.begin(), comps.end());

    extra_edges /= 2;

    debug(extra_edges);
    debug(comps);

    // we will close two edges ..

    vector<int> new_comps;

    if (extra_edges >= 2) {
        new_comps = comps;
    }

    if (extra_edges == 1) {
        int split = 0;
        for(int i : comps) {
            if (i != 1 && split < 1) {
                new_comps.push_back(i-1);
                new_comps.push_back(1);
                split++;
            } else {
                new_comps.push_back(i);
            }
        }
    }

    if (extra_edges == 0) {
        int split = 0;
        for(int i : comps) {
            if (i != 1 && split < 2) {
                new_comps.push_back(i-1);
                new_comps.push_back(1);
                split++;
            } else {
                new_comps.push_back(i);
            }
        }
    }

    debug(new_comps);
    
    long long ans = 0;
    for (int i : new_comps) {
        ans += i * 1ll * (i-1);
    }

    cout << ans << endl;

    return 0;
}