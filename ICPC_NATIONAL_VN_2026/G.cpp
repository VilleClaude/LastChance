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

long long lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

void solve() {
    int n; cin >> n;
    vector <long long> b(n);
    for (int i = 1; i < n; i++) cin >> b[i];
    vector <long long> ans(n);
    ans[0] = b[1];
    ans[n - 1] = b[n - 1];
    for (int i = 1; i < n - 1; i++) {
        ans[i] = lcm(b[i], b[i + 1]);
    }

    for (int i = 1; i < n; i++) {
        if (__gcd(ans[i - 1], ans[i]) != b[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << '\n';
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
    while (t--) {
        solve();
    }


    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
