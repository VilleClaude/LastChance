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
const int  N = 1e6+7;
const int M = 1e9+7;
const ll oo = 3e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long GetRandom(long long l, long long r) {
    return uniform_int_distribution<long long> (l, r)(rng);
}

int n, timedfs = 0, tin[N], tout[N], euler[N], sz[N], mx[N];
vector <int> g[N];
ll ans = 0;
void dfs(int u, int par) {
    tin[u] = ++timedfs;
    euler[timedfs] = u;
    sz[u] = 1;
    mx[u] = 0;
    for (int v: g[u]) {
        if (v == par) continue;
        dfs(v, u);
        sz[u] += sz[v];
        mx[u] = max(mx[u], v);
    }
    tout[u] = timedfs;
}

int bit[N];

void up(int x, int val) {
    for (; x <= n; x += x& - x) bit[x] += val;
}

int get (int x) {
    int ans = 0;
    for (; x > 0; x -= x& - x) ans += bit[x]; 
    return ans;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}

void solve() {
    cin >> n;
    ans = 0;
    timedfs = 0;
    For (i, 1, n) g[i].clear();
    For (i, 1, n - 1) {
        int u, v; cin >> u >> v;
        u++;
        v++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    For (i, 0, n + 10) bit[i] = 0;
    For (i, 1, n) sort(all(g[i]));

    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        int u = euler[i];
        int pos = i + sz[u];
        if (pos <= n) {
            if (euler[pos] > mx[u]) {
                ans++;
            }
        }    
    }

    for (int i = n; i >= 2; i--) {
        ans += get(tin[i], tout[i]);
        up(tin[i], 1);
    }

    cout << ans << '\n';

}

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

    int t; cin >> t;
    while (t--) solve();


    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
