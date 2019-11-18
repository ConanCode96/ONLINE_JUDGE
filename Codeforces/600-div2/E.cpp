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
const int MX = (int)1e5 + 10;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}


int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<int> dp(m + 1, (int)1e9);
	dp[0] = 0;

	vector<pair<int, int>> vs(n);
	for(auto &[x, y] : vs)
		cin >> x >> y;

	sort(all(vs));

	for(int i = 0; i < n; ++i){
		int p, s;
		tie(p, s) = vs[i];

		int mn = max(1, p - s);
		int mx = min(m, p + s);
		int best_prefix = (int)1e9;
		int post_coupled = 1 + (2 * (p - 1));
		for(int idx = 1; idx <= m; ++idx){
			if(idx < mn){ //left end and its right mirror
				int diff = mn - idx;
				best_prefix = min(best_prefix, dp[idx - 1] + diff);
				dp[idx] = min(dp[idx], best_prefix);
				int mirror = min(m, mx + diff);
				dp[mirror] = min(dp[mirror], best_prefix);
			}
			else if(idx > max(mx, post_coupled)) { //right, after the mirror
				int diff = idx - mx;
				dp[idx] = min(dp[idx], diff);
			}
			else if(idx >= mn && idx <= mx){ //inside
				dp[idx] = min(dp[idx], dp[mn - 1]);
			}
		}
	}

	cout << dp[m] << endl;

	return 0;
}