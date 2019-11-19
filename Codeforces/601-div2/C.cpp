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

	int m = n - 2;

	map<pair<int, int>, vector<int>> mp;

	vector<vector<int>> org(m);

	vector<int> pos[n + 1];

	for(int i = 0; i < m; ++i){
		vector<int> a(3);
		int sum = 0;
		for(auto &x : a){
			cin >> x;
			pos[x].push_back(i);
			sum += x;
		}

		org[i] = a;
		
		for(int j = 0; j < 3; ++j){
			for(int k = 0; k < 3; ++k){
				if(j == k) continue;
				mp[{a[j], a[k]}].push_back(sum - a[j] - a[k]);
			}
		}
	}
	
	int st = 0;
	int idx = 0;
	pair<int, int> lst;

	int _ = 0;
	for(int i = 1; i <= n; ++i){
		if(pos[i].size() == 1){
			idx = pos[i][0];
			st = i;
			_++;
		}
	}
	assert(_ == 2);

	for(auto &[p, v] : mp){
		assert(v.size() <= 2);
	}

	vector<int> tx;
	for(auto x : org[idx]){
		if(x != st) tx.push_back(x);
	}

	// sort(all(tx));

	vector<int> nxt = mp[{tx[0], tx[1]}];

	int nn;
	for(auto x : nxt){
		if(x != st) nn = x;
	}

	// debug() << nn;

	vector<int> v(n);

	v[0] = st;
	v[1] = tx[0]; 
	v[2] = tx[1];
	v[3] = nn;

	if(mp[{v[2], v[3]}].size() == 1) swap(v[1], v[2]);
	assert((mp[{v[2], v[3]}]).size() == 2);

	for(int i = 4; i < n; ++i){
		tx[0] = v[i - 2];
		tx[1] = v[i - 1];
		nxt = mp[{tx[0], tx[1]}];
		// nn;
		for(auto x : nxt){
			if(x != v[i - 3]) nn = x;
		}
		v[i] = nn;
	}

	for(auto &x : v) cout << x << " ";

	return 0;
}