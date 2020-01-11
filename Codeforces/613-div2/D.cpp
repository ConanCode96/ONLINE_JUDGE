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

int play(const vector<int>& a, int bit){

	if(bit == -1) return 0;

	vector<int> cnt[2];
	for(auto &x : a){
		int bb = x >> bit & 1;
		cnt[bb].push_back(x);
	}

	if(cnt[1].size() == 0) return play(a, bit - 1); // all zeros
	if(cnt[0].size() == 0) return play(a, bit - 1); // all ones, can be zeros setting X ^= 1 << bit

	// we have both, so this bit is a must, either go with flipping or not

	return min(play(cnt[0], bit - 1), play(cnt[1], bit - 1)) + (1 << bit);
}

int nodeCnt;
int Trie[32 * MX][2];

void insert(int x){
	int node = 0;
	for(int bit = 29; bit >= 0; --bit){
		int d = x >> bit & 1;
		auto &nxt = Trie[node][d];
		if(nxt == -1) nxt = ++nodeCnt;
		node = nxt;
	}
}

int goBoy(int node, int bit){

	// if(bit == -1) return 0;

	int z = Trie[node][0];
	int o = Trie[node][1];

	if(z == -1 && o == -1) return 0;

	if(z == -1) return goBoy(o, bit - 1);
	else if(o == -1) return goBoy(z, bit - 1);
	else return min(goBoy(z, bit - 1), goBoy(o, bit - 1)) + (1 << bit);

}

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> a(n);

	memset(Trie, 0xff, sizeof Trie);

	for(auto &x : a) cin >> x, insert(x);

	// cout << play(a, 29) << endl;

	cout << goBoy(0, 29) << endl;

	return 0;
}