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

int cnt[10];
int dp[10][480][480][12];
int POS_NEEDED , NEG_NEEDED;

int calc(int digit, int pos, int neg, int rem){

	if(pos > POS_NEEDED || neg > NEG_NEEDED) return 0;

	if(digit == 10)
		return pos == POS_NEEDED && neg == NEG_NEEDED && rem == 0;

	int &res = dp[digit][pos][neg][rem];
	if(res != -1) return res;

	res = 0;

	for(int i = 0; i <= cnt[digit]; ++i){
		int np = pos + i;
		int ng = neg + cnt[digit] - i;
		int rm = (rem + (i - (cnt[digit] - i)) * digit) % 11;
		rm = (rm + 11) % 11;
		res |= calc(digit + 1, np, ng, rm);
	}

	return res;
}


int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		int sum = 0;
		for(int d = 1; d <= 9; ++d){
			cin >> cnt[d];
			int take = max(cnt[d] - 100, 0);
			cnt[d] -= take / 2 * 2;
			sum += cnt[d];
		}
		NEG_NEEDED = sum / 2;
		POS_NEEDED = sum - NEG_NEEDED;
		memset(dp, 0xff, sizeof dp);
		int res = calc(0, 0, 0, 0);
		cout << (res ? "YES" : "NO") << "\n";
	}
	
	return 0;
}