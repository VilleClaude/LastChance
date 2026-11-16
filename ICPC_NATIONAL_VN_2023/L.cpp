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
const int  N = 1e4+7;
const int M = 1e9+7;
const ll oo = 3e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long GetRandom(long long l, long long r) {
    return uniform_int_distribution<long long> (l, r)(rng);
}

int n, m, k, a[N], cnt[N], cntg[N];
int w[N];

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
    cin >> n >> m >> k;
    For (i, 1, m) cin >> a[i];
    For (f, 1, m) {
        For (i, 1, m) cntg[i] = 0;
        For (i, 1, n) cnt[i] = 0; 
        
        int R = min(m, f + k - 1); 
        For (l, f, R) {
            int team = a[l];
            if (l > f) {
                w[team] = max(w[team], cntg[cnt[team] + 1] + 1);
            }
            cnt[team]++;
            cntg[cnt[team]]++;
        }

        For (i, 1, n) {
            w[i] = max(w[i], cntg[cnt[i] + 1] + 1);
        }
    }

    For (i, 1, n) cout << w[i] << " ";



    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
