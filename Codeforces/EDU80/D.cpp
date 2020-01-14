#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 
  
#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

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
const int MX = (int)1e5 + 10;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}

int mn[(int)3e5 + 10][256];
int best[265];
int owner[256];

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;

	memset(best, 0xff, sizeof best);
	memset(owner, 0x7f, sizeof owner);
	memset(mn, 0x7f, sizeof mn);

	int mx = 1 << m;

	int a[n][m];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
		for(int msk = 0; msk < mx; ++msk){
			for(int j = 0; j < m; ++j){
				if(msk >> j & 1)
					mn[i][msk] = min(mn[i][msk], a[i][j]);
			}
			if(mn[i][msk] > best[msk]){
				best[msk] = mn[i][msk];
				owner[msk] = i;
			}
		}
	}

	int res = -1;
	int l = -1, r = -1;

	for(int i = 0; i < n; ++i){
		for(int msk = 0; msk < mx; ++msk){
			int comp = (mx - 1) ^ msk;
			// assert((comp & msk) == 0);
			int cur = min(best[comp], mn[i][msk]);
			if(cur > res){
				res = cur;
				l = i;
				// assert(comp < mx);
				r = owner[comp];
			}
		}
	}

	cout << l + 1 << " " << r + 1 << endl;

	return 0;
}