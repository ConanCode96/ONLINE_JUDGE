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

long long modpower(long long a, long long b)
{
	if (b == 0)
		return 1ll;
	long long x = modpower(a, b / 2ll);
	x = (x * x) % mod;
	if (b & 1)
		return (x * a) % mod;
	return (x % mod);
}

struct combination
{
	vector<long long> fact, inv;
	combination(int sz) : fact(sz + 1), inv(sz + 1)
	{
		fact[0] = 1ll;
		inv[0] = 1ll;
		for (long long i = 1; i <= sz; ++i)
		{
			fact[i] = (fact[i - 1] * i) % mod;
			inv[i] = modpower(fact[i], mod - 2ll);
		}
	}
	long long choose(int n, int k) const
	{
		if (k < 0 || n < k)
			return 0;
		return ((((fact[n] * inv[k]) % mod) * inv[n - k]) % mod);
	}
};

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;

	combination comb(1e5 + 10);

	while(T--){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		int cnt1[2], cnt2[2];
		for(int i = 0; i < 2; ++i){
			cnt1[i] = count(all(s), '0' + i);
			cnt2[i] = count(all(t), '0' + i);
		}
		int mx = 0;
		int extra = n;
		for(int i = 0; i < 2; ++i){
			int cur = min(cnt1[i], cnt2[i ^ 1]);
			extra = min(extra, cur);
			mx += cur;
		}

		int res = 0;
		do{
			add_self(res, comb.choose(n, mx));
			mx -= 2;
		}
		while(extra--);

		cout << res << "\n";
	}

	return 0;
}