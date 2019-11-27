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


int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int m, n, k, t;
	cin >> m >> n >> k >> t;

	vector<int> soldiers(m);
	for(auto &x : soldiers) cin >> x;
	sort(all(soldiers));
	reverse(all(soldiers));

	vector<pair<int, int>> g[n + 2];

	while(k--){
		int x, y, d;
		cin >> x >> y >> d;
		g[x].push_back({y, d});
	}

	auto check = [&](int x){
		int mn = soldiers[x - 1];
		int res = 0;
		bool left_behind = false;
		int it = 0;
		int mx = it;
		int sold = it;
		while(it <= n){
			mx = max(it, mx);
			int mxx = -1;
			for(auto &[st_off, pw] : g[it]){
				if(pw > mn) mxx = max(st_off, mxx);
			}
			mx = max(mx, mxx);
			if(it == mx){// equal
				if(mxx == it || left_behind){
					left_behind = false;
					res += 2 * (it - (sold - 1));
				}
				sold = it;
				sold++;
			}
			else{
				left_behind = true;
			}
			it++; res++;
		}	
		return res <= t;
	};

	int l = 1, r = m;
	while(l <= r){
		int md = (l + r) / 2;
		if(check(md)) l = md + 1;
		else r = md - 1;
	}

	cout << r << endl;

	return 0;
}