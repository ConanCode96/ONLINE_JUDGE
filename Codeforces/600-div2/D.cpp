#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int mod = (int)1e9 + 7;
const int MX = (int)2e5 + 10;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}

//UNION-Find

int mn[MX], mx[MX];

int find(int x, std::vector<int>& ds){
  return ds[x] < 0 ? x : ds[x] = find(ds[x], ds);
}

void unite(int x, int y, std::vector<int>& ds){
  int xx = find(x, ds);
  int yy = find(y, ds);
  if(xx != yy){
    if(ds[xx] > ds[yy]) swap(xx, yy);
    ds[xx] += ds[yy];
    mn[xx] = min(mn[xx], mn[yy]);
    mx[xx] = max(mx[xx], mx[yy]);
    ds[yy] = xx;
  }
}


int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;

    vector<int> ds(n, -1);

    for(int i = 0; i < n; ++i) mn[i] = mx[i] = i;

    while(m--){
        int x, y;
        cin >> x >> y;
        --x, --y;
        unite(x, y, ds);        
    }

    int res = 0;
    for(int i = 0; i < n; ++i){
        int par = find(i, ds);
        int lim = mx[par];
        if(abs(ds[par]) != mx[par] - mn[par] + 1){
            for(int k = mn[par]; k <= lim; ++k){
                int pak = find(k, ds);
                int pai = find(par, ds);
                if(pak != pai){
                    res++;
                    unite(par, k, ds);
                }
                lim = max(lim, mx[pak]);
            }
        }
    }
    
    cout << res << endl;

    return 0;
}