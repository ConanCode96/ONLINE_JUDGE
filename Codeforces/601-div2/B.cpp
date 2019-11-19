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

	int t;
	cin >> t;

	while(t--){
		int n, m;
		cin >> n >> m;


		int a[n];
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}

		if(m < n || n == 2){
			cout << -1 << "\n";
			continue;
		}

		int res = 0;
		int best = (int)1e9;
		pair<int, int> p;
		vector<pair<int, int>> v;

		m -= n;

		for(int i = 0; i < n; ++i){
			v.push_back({i, (i + 1) % n});
			res += 2 * a[i];
		}

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(i == j) continue;
				if(a[i] + a[j] < best){
					best = a[i] + a[j];
					p = {i, j};
				}
			}
		}

		while(m--)
			v.push_back(p), res += best;

		cout << res << "\n";
		
		for(auto& [x, y] : v)
			cout << x + 1 << " " << y + 1 << "\n";

	}

	return 0;
}