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

int x, y;
ll dp[32][2][2][2][2];

ll calc(int idx, int Ax, int Ay, int Bx, int By){
	
	if(idx == -1) return 1;

	ll &res = dp[idx][Ax][Ay][Bx][By];
	if(res != -1) return res;

	// debug() << idx << " " << Ax << " " << Ay << " " << Bx << " " << By;

	res = 0;

	int dx = (x >> idx) & 1;
	int dy = (y >> idx) & 1;

	int Amn = Ax ? dx : 0;
	int Amx = Ay ? dy : 1;

	int Bmn = Bx ? dx : 0;
	int Bmx = By ? dy : 1;

	for(int i = Amn; i <= Amx; ++i){
		for(int j = Bmn; j <= Bmx; ++j){
			if(i & j) continue;
			res += calc(idx - 1, Ax & (i == Amn), Ay & (i == Amx), Bx & (j == Bmn), By & (j == Bmx));
		}
	}

	return res;
}

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);


    int t;
    cin >> t;

    while(t--){
        cin >> x >> y;
        memset(dp, 0xff, sizeof dp);
        cout << calc(30, 1, 1, 1, 1) << endl;
    }
	
	return 0;
}