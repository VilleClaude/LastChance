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
const int M = 998244353;
const ll oo = 3e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long GetRandom(long long l, long long r) {
    return uniform_int_distribution<long long> (l, r)(rng);
}

ll f[100][100], pw[100];
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
    
    int n; cin >> n;
    vector<int> a(n + 1);
    For (i, 1, n) cin >> a[i];       

    pw[0] = 1;
    For (i, 1, n) pw[i] = pw[i - 1] * 2 % M;

    f[1][0] = 1;
    For (i, 1, n - 1)
        For (d, 0, i - 1) if (f[i][d])
            For (nd, 1, d + 1)
                f[i + 1][nd] = (f[i + 1][nd] + f[i][d] * pw[nd - 1]) % M;

    ll ans = 0;
    For (d, 0, n - 1) ans = (ans + f[n][d]) % M;  
    cout << ans << '\n';



    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
