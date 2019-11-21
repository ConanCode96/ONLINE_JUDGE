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

	int n;
	cin >> n;

	vector<int> a(n);
	for(int &x : a) cin >> x;

	ll sum = accumulate(all(a), 0ll);

	vector<ll> primes;

	ll p = 2;
	while(p * p <= sum){
		if(sum % p == 0) primes.push_back(p);
		while(sum % p == 0)
			sum /= p;
		p++;
	}
	if(sum != 1) primes.push_back(sum);

	ll res = (ll)9e18;

	for(auto pr : primes){
		ll here = 0;
		ll acc = 0;
		for(auto x : a){
			acc += x;
			here += min(acc % pr, pr - acc % pr);
		}
		res = min(res, here);
	}

	if(res == (ll)9e18) res = -1;

	cout << res << endl;

	return 0;
}