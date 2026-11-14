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

int n, q, a[N];
struct fen {
    vector <long long> bit;
    int n;
    void init(int sz) {
        n = sz + 10;
        bit.resize(n);
    }

    void up(int x, ll val) {
        for (; x <= n; x += x& - x) bit[x] += val;
    }

    ll get (int x) {
        ll ans = 0;
        for (; x > 0; x -= x & - x) ans += bit[x];
        return ans;
    }

    ll get (int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
}T[N];

vector <int> appear[200003];

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

    cin >> n >> q;
    For (i, 1, n) cin >> a[i], appear[a[i]].push_back(i);

    For (i, 1, n) {
        if (appear[i].size() > 0) {
            T[i].init(appear[i].size());
            for (int j = 0; j < appear[i].size(); j++) {
                T[i].up(j + 1, 1ll * appear[i][j] * appear[i][j]);
            }
        }
    }

    long long t, l, r, x, p;
    ll last = 0;
    For(jj, 1, q) {
        ll tt, ln, rn, xn;
        cin >> tt;
        t = tt;
        if (t == 1) {
            cin >> p;
            p = (p + last - 1) % (n - 1) + 1;
        }
        else cin >> ln >> rn >> xn;
        l = (ln + last - 1) % n + 1;
        r = (rn + last - 1) % n + 1;
        x = (xn + last - 1) % n + 1;
        if (l > r) swap(l, r);

        if (t == 1) {
            if (a[p] == a[p + 1]) continue;
            int pos = -1;
            int low = 0;
            int high = appear[a[p]].size() - 1;
            while (low <= high) {
                int mid = low + high >> 1;
                if (appear[a[p]][mid] <= p) {
                    pos = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            appear[a[p]][pos] += 1;
            T[a[p]].up(pos + 1, 2 * p + 1);
            pos = -1;
            low = 0;
            high = appear[a[p + 1]].size() - 1;
            while (low <= high) {
                int mid = low + high >> 1;
                if (appear[a[p + 1]][mid] <= p + 1) {
                    pos = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            appear[a[p + 1]][pos] -= 1;
            T[a[p + 1]].up(pos + 1, -2 * p - 1);
            swap(a[p], a[p + 1]);
        }
        else if (t == 2) {
            int lp = -1;
            int low = 0;
            int high = appear[x].size() - 1;
            while (low <= high) {
                int mid = low + high >> 1;
                if (appear[x][mid] >= l) {
                    lp = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            if (lp == -1) {
                last = 0;
                cout << 0 << '\n';
                continue;
            }


            int hp = -1;
            low = 0;
            high = appear[x].size() - 1;
            while (low <= high) {
                int mid = low + high >> 1;           
                if (appear[x][mid] <= r) {
                    hp = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }

            cerr << hp << '\n';

            last = T[x].get(lp + 1, hp + 1);
            cout << last << '\n';

        }
        else {
            last = T[x].get(l, r);
            cout << last << '\n';
        }
    }



    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
