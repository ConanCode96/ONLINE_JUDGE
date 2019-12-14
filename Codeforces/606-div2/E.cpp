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
const int MX = (int)2e5 + 10;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}

vector<int> g[MX];
vector<bool> vis;
vector<int> visitor;

void dfs(int x, int v, int stopAt){
	vis[x] = true;
	visitor[x] += v;
	if(x == stopAt) return;
	for(auto &y : g[x]){
		if(vis[y]) continue;
		dfs(y, v, stopAt);
	}
}

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while(t--){
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		--a, --b;

		// memset(g, 0, sizeof g);
		for(int i = 0; i < n; ++i) g[i].clear();
		
		while(m--){
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		visitor.resize(n);
		fill(all(visitor), 0);

		vis.resize(n);
		fill(all(vis), false);
		dfs(a, 1, b);

		vis.resize(n);
		fill(all(vis), false);
		dfs(b, 2, a);

		int cnt[4] = {};
		for(int i = 0; i < n; ++i) cnt[visitor[i]]++;
		// debug() << visitor;
		// debug() << cnt[0] << " " << cnt[1];
		cout << cnt[1] * 1LL * cnt[2] << "\n";
	}

	return 0;
}