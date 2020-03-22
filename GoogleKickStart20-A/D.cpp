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

struct Node{
	int cnt;
	// bool isEnd;
	Node* ch[26];
	Node(){
		cnt = 0;
		// isEnd = false;
		memset(ch, 0, sizeof ch);
	}
};

struct Trie{
	Node* rt;
	ll res;
	int K;
	Trie(){
		rt = new Node();
		res = 0;
	}

	void insert(const string& s){
		int n = s.size();
		Node* ptr = rt;
		// rt->cnt++;
		for(auto &c : s){
			auto &nxt = ptr->ch[c - 'A'];
			if(nxt == nullptr) nxt = new Node();
			nxt->cnt++;
			ptr = nxt;
		}
		// ptr->isEnd = true;
	}

	int go(Node* ptr, int idx = 0){
		
		int ret = 0;
		for(auto cx : ptr->ch){
			if(cx == nullptr) continue;
			if(cx->cnt >= K)
				ret += go(cx, idx + 1);
		}
		
		ptr->cnt -= ret;

		if(ptr->cnt >= K){
			// cout << idx << " " << ptr->cnt << endl;
			res += (ptr->cnt / K) * idx;
			ret += ptr->cnt / K * K;
		}
		
		return ret;
	}

};

int main(){

	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin >> T;
	for(int test = 1; test <= T; ++test){
		int n, k;
		cin >> n >> k;
		vector<string> a(n);
		Trie trie;
		trie.K = k;
		for(auto &x : a){
			cin >> x;
			trie.insert(x);
		}
		trie.go(trie.rt);

		ll res = trie.res;

		/* Wrong */
		
		// sort(all(a));
		// vector<int> bst(n / k, 1e9);
		// for(int i = 0; i < n; ++i){
		// 	int j = 0;
		// 	int m = a[i].size();
		// 	int match = 0;
		// 	while(j < m && j < a[i / k * k].size() && a[i][j] == a[i / k * k][j]) match++, j++;
		// 	bst[i / k] = min(bst[i / k], match);
		// }
		// res = 0;
		// for(auto &x : bst) res += x;

		cout << "Case #" << test << ": " << res << "\n";
	}

	return 0;
}