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
const int MX = (int)2e5 + 10;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}

int tree[MX];

void upd(int idx){
    for(; idx < MX; idx += idx & -idx)
        tree[idx]++;
}
int qry(int idx){
    int ret = 0;
    for( ;idx > 0; idx -= idx & -idx)
        ret += tree[idx];
    return ret;
}

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);


	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";

		int n;
		cin >> n;

		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			upd(x);
			int l = 1, r = (i + 1);
			while(l <= r){
				int md = (l + r) / 2;
				int here = (i + 1) - qry(md - 1);
				// debug() << imie(here) << " " << md;
				if(here >= md) l = md + 1;
				else r = md - 1;
			}
			cout << r << " \n"[i == n - 1];
		}
		memset(tree, 0, sizeof tree);
	}

	
	return 0;
}