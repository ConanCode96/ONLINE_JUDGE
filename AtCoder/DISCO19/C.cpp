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

	int h, w, k;
	cin >> h >> w >> k;

	char a[h][w];
	int res[h][w];
	memset(res, 0, sizeof res);
	int it = 1;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cin >> a[i][j];
			if(a[i][j] == '#')
				res[i][j] = it++;
		}
	}

	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			if(res[i][j] != 0){
				int color = res[i][j];
				int kx = i - 1;
				while(kx >= 0 && !res[kx][j]) res[kx][j] = color, kx--;
				int lf = j - 1, rg = j + 1;
				while(lf >= 0 && !res[i][lf]){
					int up = i;
					while(up >= 0 && !res[up][lf]) res[up][lf] = color, up--;
					lf--;
				}
				while(rg < w && !res[i][rg]){
					int up = i;
					while(up >= 0 && !res[up][rg]) res[up][rg] = color, up--;
					rg++;
				}
			}
		}
	}

	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			if(res[i][j] == 0) res[i][j] = res[i - 1][j];
			cout << res[i][j] << " \n"[j == w - 1];
		}
	}


	
	return 0;
}