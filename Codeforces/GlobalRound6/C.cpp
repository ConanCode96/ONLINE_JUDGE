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

	int r, c;
	cin >> r >> c;

	if(r + c == 2) return puts("0");

	vector<vector<int>> res(r, vector<int>(c));

	res[0][0] = 2;

	int mn = min(r, c);

	if(c >= r){
		for(int j = 1; j < mn; ++j) res[0][j] = 2 + (2 * j) - 1;
		for(int i = 1; i < mn; ++i) res[i][0] = 2 + (i * 2);

		int it = 0;
		for(int j = mn; j < c; ++j) res[0][j] = mn * 2 + ++it;
	}
	else{
		for(int j = 1; j < c; ++j) res[0][j] = 2 + (2 * j);
		for(int i = 1; i < r; ++i) res[i][0] = 2 + (i * 2) - 1;

		int it = 0;
		for(int i = mn; i < r; ++i) res[i][0] = mn * 2 + ++it;
	}

	auto lcm = [](int x, int y){
		return x / __gcd(x, y) * 1LL * y;
	};

	for(int i = 1; i < r; ++i){
		for(int j = 1; j < c; ++j){
			// res[i][j] = lcm(res[i - 1][j], res[i][j - 1]);
			res[i][j] = lcm(res[i][0], res[0][j]);
		}
	}

	// set<int> st;
	// vector<int> row(r), col(c);
	// for(int i = 0; i < r; ++i){
	// 	for(int j = 0; j < c; ++j){
	// 		assert(res[i][j] <= (int)1e9);
	// 		row[i] = __gcd(row[i], res[i][j]);
	// 		col[j] = __gcd(col[j], res[i][j]);
	// 	}
	// }

	// for(auto &x : row) st.insert(x);
	// for(auto &x : col) st.insert(x);

	// assert((int)st.size() == r + c);
	// assert(*st.rbegin() == (r + c));

	for(auto &rx : res){
		for(auto &ele : rx){
			cout << ele << " ";
		}
		cout <<"\n";
	}

	return 0;
}