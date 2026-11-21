#include <bits/stdc++.h>
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define For(i,a,b) for(int i = a; i <= b; i++)
#define Ford(i,a,b) for(int i = a; i >= b; i--)
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define RRH(v) v.resize(unique(all(v)) - v.begin())

using namespace std;
const int  N = 2200007;
const int M = 1e9+7;
const ll oo = 3e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long GetRandom(long long l, long long r) {
    return uniform_int_distribution<long long> (l, r)(rng);
}

int n, q, c[N];
vector <ii> g[N];
int in[N], out[N];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    #define TASK ""
    if (fopen (".inp", "r")) {
        freopen (".inp", "r", stdin);
        freopen (".out", "w", stdout);
    }
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    int cntnode;
    cin >> n >> q;
    cntnode = n;
    For (i, 1, n) cin >> c[i];
    For (i, 1, n) in[i] = ++cntnode, out[i] = ++cntnode;
    For (i, 1, n) g[in[c[i]]].push_back({i, 0}), g[i].push_back({out[c[i]], 0});

    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 1) {
            g[out[u]].push_back({in[v], 1});
            g[out[v]].push_back({in[u], 1});
        }
        else {
            if (u == v) continue;
            int ni = ++cntnode, no = ++cntnode;
            g[ni].push_back({in[u], 0});  g[ni].push_back({in[v], 0});
            g[out[u]].push_back({no, 0}); g[out[v]].push_back({no, 0});
            in[v] = ni; out[v] = no;
            in[u] = ++cntnode; out[u] = ++cntnode; 
        }
    }

    deque <int> dq;
    vector <int> dist(cntnode + 10, N);
    dist[1] = 0;
    dq.push_back(1);

    while (dq.size()) {
        int y = dq.front();
        dq.pop_front();
        for (auto [v, w]: g[y]) {
            if (dist[y] + w < dist[v]) {
                dist[v] = dist[y] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }

    For (i, 1, n) {
        if (dist[i] > n + 10) {
            dist[i] = -1;
        }
        cout << dist[i] << " ";
    }
    


    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
