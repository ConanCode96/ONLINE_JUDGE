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

	int T;
	cin >> T;
	while(T--){
		string s, t;
		cin >> s >> t;
		int n = s.size();
		int m = t.size();
		int sz = max(n, m);

		reverse(all(s));
		while(s.size() < sz) s.push_back('0');
		reverse(all(s));

		reverse(all(t));
		while (t.size() < sz) t.push_back('0');
		reverse(all(t));
		
		int res = 0;
		int ones_streak = 0;
		bool non_zero = false;
		for(int i = 0; i < sz; ++i){
			ones_streak += (s[i] == '1');
			if(t[i] == '1'){
				non_zero = true;
				if(s[i] == t[i]){
					res = max(res, ones_streak + 1);
					ones_streak = 0; //because s[i] = '0'
				}
				else
					ones_streak++;
			}
			else if(s[i] == '0') ones_streak = 0;
			// debug() << i  << " " << ones_streak;
		}

		if(non_zero) res = max(res, 1);

		cout << res << "\n";
	}

	return 0;
}