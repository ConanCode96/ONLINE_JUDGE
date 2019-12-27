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

const int mod = 998244353;
const int MX = (int)1e6 + 10;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}

vector<int> inv(MX);

int bp(int x, int exp){
	int res = 1;
	while(exp){
		if(exp & 1) mul(res, x);
		mul(x, x);
		exp >>= 1;
	}
	return res;
}

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> cnt(MX, 0);
	vector<vector<int>> a(n);

	for(int i = 0; i < n; ++i){
		int k; cin >> k;
		a[i].resize(k);
		for(auto &x : a[i]) cin >> x, cnt[x]++;
	}

	for(int i = 0; i < MX; ++i)
		inv[i] = bp(i, mod - 2);

	int res = 0;
	for(int i = 0; i < n; ++i){
		int cur = inv[n];
		int k = a[i].size();
		mul(cur, inv[k]);

		int nxt = 0;
		for(auto &x : a[i]){
			int kk = cnt[x];
			mul(kk, inv[n]);
			add_self(nxt, kk);
		}

		mul(cur, nxt);
		add_self(res, cur);
	}

	cout << res << "\n";

	return 0;
}