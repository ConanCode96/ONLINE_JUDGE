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

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int bb = b - a;
	int cc = c - d;

	bool ok = (bb >= 0 ||(bb == -1 && c + d == 0));
	ok &= (cc >= 0 ||(cc == -1 && a + b == 0));

	if(!ok){
		cout << "NO" << endl;
		return 0;
	}

	string lf;
	while(a) lf += "01", a--, b--;
	if(b == -1) lf += "0", b++;

	string rg;
	while(d) rg = "23" + rg, c--, d--;
	if(c == -1) rg = "3" + rg, c++;

	string md;
	int sz = min(b, c);
	while(sz--) md += "21", b--, c--;

	if(b == 1) lf = "1" + lf, b--;
	if(c == 1) rg = rg + "2", c--;

	ok &= abs(bb - cc) <= 1;

	if(a + b + c + d == 0){
		cout << "YES" << endl;
		string res = (lf + md + rg);
		for(auto &cx : res) cout << cx << " ";
		cout << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}