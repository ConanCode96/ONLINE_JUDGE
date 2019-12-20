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
const int MX = (int)3e5 + 10;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}

int dp[22][MX];
vector<int> primes, cost, sp(MX), lst[MX], pos(MX, -1);

int calc(int idx, int x){

	if(idx == -1) return x;

	int &res = dp[idx][x];
	if(res != -1) return res;

	res = calc(idx - 1, x);

	int p = lst[x][idx];
	int loc = pos[p];
	if(loc == -1) // prime not found
		return res;

	int cc = 0;
	while(x % p == 0){
		x /= p;
		cc += cost[loc];
		res = min(res, cc + calc(idx - 1, x));
	}

	return res;
}

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, q;
	cin >> n >> q;
	primes.resize(n);
	cost.resize(n);
	int it = 0;
	for(auto &x : primes){
		cin >> x;
		pos[x] = it++;
	}
	for(auto &x : cost) cin >> x;

	for(int i = 2; i < MX; ++i){
		if(sp[i]) continue;
		for(int j = i; j < MX; j += i){
			sp[j] = i;
			lst[j].push_back(i);
		}
	}

	memset(dp, 0xff, sizeof dp);

	while(q--){
		int x;
		cin >> x;
		int sz = lst[x].size();
		int res = calc(sz - 1, x);
		cout << res << "\n";
	}

	return 0;
}