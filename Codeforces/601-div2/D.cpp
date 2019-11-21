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
		int n, m, k;
		cin >> n >> m >> k;

		vector<char> alpha(62);
		int it = 0, tn = 10, tx = 26;
		while(tn--) alpha[it++] = '0' + tn;
		while(tx--) alpha[it++] = 'a' + tx; tx = 26;
		while(tx--) alpha[it++] = 'A' + tx;
		assert(it == 62);
		
		int cnt = 0;
		vector<string> s(n);
		for(auto &xx : s){
			cin >> xx;
			cnt += count(all(xx), 'R');
		}

		int each = cnt / k;
		int rem = cnt % k;

		it = 0;
		int have = 0;

		char res[n][m];
		for(int i = 0; i < n; ++i){
			if(i & 1){
				for(int j = m - 1; j >= 0; --j){
					res[i][j] = alpha[it];
					have += s[i][j] == 'R';
					if(have == each + (it < rem))
						it = min(k - 1, ++it), have = 0;
				}
			}
			else{
				for(int j = 0; j < m; ++j){
					res[i][j] = alpha[it];
					have += s[i][j] == 'R';
					if (have == each + (it < rem))
						it = min(k - 1, ++it), have = 0;
				}
			}
		}

		for(auto &row : res){
			for(auto cell : row){
				cout << cell;
			}
			cout << endl;
		}

	}
	
	return 0;
}