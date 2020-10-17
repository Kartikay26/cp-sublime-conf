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

struct SimpleGraph {
    int v = 0, e = 0;
    map<int, vi> adj;
    SimpleGraph(){}
    set<int> vis;
    void readGraph(){
        cin >> v >> e;
        for (int i = 0; i < e; ++i) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b); adj[b].push_back(a);
        }
    }
    void dfs(int node, 
             function<void(int node, int parent)> f_before = [](int, int){},
             function<void(int node, int parent)> f_after = [](int, int){},
             int parent = -1)
    {
        if (vis.count(node)) return;
        vis.insert(node);
        f_before(node, parent);
        for(auto next : adj[node]){
            dfs(next, f_before, f_after, node);
        }
        f_after(node, parent);
    }
};

int32_t main(){
    fast_io();

    SimpleGraph g;
    g.readGraph();

    int dist[g.v+1];
    clr(dist);
    for (int i = 1; i <= g.v; ++i) {
        g.dfs(i, [&](int i, int p){
            if (p != -1)
                dist[i] = dist[p]+1;
        }, [&](int i, int p){

        });
    }

    debug(arr(dist+1, g.v));

    return 0;
}