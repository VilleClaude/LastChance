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

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        sort(all(a));

        ll ans = 1;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && a[j + 1] == a[j] + 1) j++;
            int L = j - i + 1;
            if (L & 1) ans = ans * ((L + 1) / 2) % M;
            i = j + 1;
        }
        cout << ans << '\n';
    }

    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
