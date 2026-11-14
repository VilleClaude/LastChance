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

int n, a[N];

int bit[N];
void up(int x, int val) {
    for (; x <= n + 100; x+= x&-x) bit[x] += val;
}

int get (int x) {
    int ans = 0;
    for (; x > 0; x -= x& - x) ans += bit[x];
    return ans;
}

int get (int l, int r) {
    return get(r) - get(l - 1);
}

void solve() {
    cin >> n;
    For (i, 1, n) cin >> a[i];
    For (i, 0, n + 100) bit[i] = 0;
    map <int, int> ma;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ma[a[i]] != 0) up(ma[a[i]], -1);
        ma[a[i]] = i;
        up(i, 1);
        int low = 1;
        int high = i;
        int res = i;
        while (low <= high) {
            int mid = low + high >> 1;
            if (get(mid, i) == (i - mid + 1)) {
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        } 
        ans += (i - res + 1);
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
    while (t--) {
        solve();
    }


    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
