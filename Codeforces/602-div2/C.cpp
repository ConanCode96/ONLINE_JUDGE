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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vector<pair<int, int>> ops;
		stack<char> st;

		auto _reverse = [&](int x, int y){
			reverse(s.begin() + x, s.begin() + y + 1);
		};

		auto play = [&](int i, char c){
			for(int j = i + 1; j < n; ++j){
				if(s[j] == c){
					_reverse(i, j);
					ops.push_back({i + 1, j + 1});
					break;
				}
			}
		};


		char sx[] = {'(', ')'};

		bool met = false;

		for(int i = 0; i < n; ++i){
			int par = i & 1;
			
			if(k == 1 && !par){
				if(s[i] == ')') play(i, '(');
				sx[0] = ')';
				sx[1] = '(';
				continue;
			}

			if(s[i] != sx[par]){
				play(i, sx[par]);
			}
		
			if(!st.empty() && st.top() == '(' && s[i] == ')') st.pop();
			else st.push(s[i]);
			if(st.empty()) k--;
		}

		debug() << s;
		cout << ops.size() << "\n";
		for(auto &[x, y] : ops) cout << x << " " << y << "\n";
	}
	
	return 0;
}