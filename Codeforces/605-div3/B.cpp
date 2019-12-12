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

	int q;
	cin >> q;

	while(q--){
		string s;
		cin >> s;

		int L = count(all(s), 'L');
		int R = count(all(s), 'R');
		int U = count(all(s), 'U');
		int D = count(all(s), 'D');

		int n = s.size();

		int hzx = min(L, R);
		int vty = min(U, D);

		if(hzx + vty >= 1){
			int sz = 2;
			if(hzx && vty) sz = 2 * (hzx + vty);
			cout << sz << "\n";
			string res;
			if(sz == 2){
				hzx = min(hzx, 1);
				vty = min(vty, 1);
				res += string(hzx, 'L');
				res += string(vty, 'U');
				res += string(hzx, 'R');
				res += string(vty, 'D');
			}
			else{
				res += string(hzx, 'L');
				res += string(vty, 'U');
				res += string(hzx, 'R');
				res += string(vty, 'D');
			}
			cout << res << "\n";
		}
		else{
			cout << 0 << "\n\n";
		}
	}

	return 0;
}