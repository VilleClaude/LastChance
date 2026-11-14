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

int n, a, b, ans = 0;
void dfs(int cura, int curb) {
    if (cura > a or curb > b) return;
    if (max(cura, curb) >= n and abs(cura - curb) >= 2) {
        if (cura == a and curb == b) ans++;
        return;
    }
    dfs(cura + 1, curb);
    dfs(cura, curb + 1);
}

void solve() {
    cin >> n >> a >> b;
    ans = 0;
    dfs(0, 0);
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

    int t;

    cin >> t;
    while (t--) solve();


    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
