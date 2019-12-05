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

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> p(n);
		for(auto &x : p) cin >> x;

		int g = 0, s = 0, b = 0;		

		if(n == 1){
			cout << g << " " << s << " " << b << "\n";
			continue;
		}

		int lst = n / 2 - 1;
		while(lst >= 0 && p[lst] == p[n / 2]) lst--;

		if(lst < 0){
			cout << g << " " << s << " " << b << "\n";
			continue;
		}

		n = lst + 1;
		p.resize(n);
		// debug() << p;

		int it = 0;
		vector<int> red;
		while(it < n){
			int roll = it;
			while(roll < n && p[roll] == p[it]) roll++;
			red.push_back(roll - it);
			it = roll;
		}

		// debug() << red;

		g = red[0];
		it = 1;
		int sum = 0;
		while(it < red.size() && sum <= g) sum += red[it++];
		s = sum;
		
		b = accumulate(all(red), 0) - g - s;

		if(b <= g) b = 0;
		
		if(g == 0 || b == 0 || s == 0) g = b = s = 0;
		cout << g << " " << s << " " << b << "\n";
	}
	
	return 0;
}