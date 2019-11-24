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
		int n;
		cin >> n;

		set<int> st;
		for(int i = 1; i <= n; ++i) st.insert(i);

		vector<int> a(n), perm(n);
		
		for(auto &x : a) cin >> x;

		bool ok = true;

		for(int i = 0; i < n; ++i){
			if(i == 0){
				perm[0] = a[0];
				st.erase(a[0]);
				continue;
			}

			if(a[i] == a[i - 1]){
				if(*st.begin() > a[i]){
					ok = false;
					break;
				}
				perm[i] = *st.begin();
				st.erase(st.begin());
			}
			else{
				perm[i] = a[i];
				st.erase(perm[i]);
			}
		}

		ok &= st.empty();

		if(!ok) cout << -1 << "\n";
		else{
			for(auto &x : perm) cout << x << " ";
			cout << "\n";
		}
	}
	
	return 0;
}