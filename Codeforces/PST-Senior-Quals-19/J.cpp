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

vector<int> fact;

int bp(int x, int e){
	int res = 1;
	while(e){
		if(e & 1) mul(res, x);
		mul(x, x);
		e >>= 1;
	}
	return res;
}

int ncr(int n, int r){
	int res = 1;
	for(int i = n; i > n - r; --i){
		mul(res, i);
	}
	mul(res, bp(fact[r], mod - 2));
	return res;
}

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, k;
	cin >> n >> m >> k;

	fact.resize(n + 1);
	fact[0] = 1;
	int kn = 1;
	for(int i = 1; i <= n; ++i){
		fact[i] = (fact[i - 1] * 1LL * i) % mod;
		mul(kn, k);
	}

	int numofways = ncr(m, n);

	// debug() << fact[n] << " " << kn << " " << numofways;

	int res = fact[n];
	mul(res, numofways);
	mul(res, kn);

	cout << res << endl;

	return 0;
}