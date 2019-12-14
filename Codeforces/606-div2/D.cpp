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

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		string s[n];
		int same[2] = {0, 0};
		int zo = 0, oz = 0;
		vector<int> zo_pos, oz_pos;
		unordered_map<string, bool> oz_mp, zo_mp;
		for(int i = 0; i < n; ++i){
			cin >> s[i];
			if(s[i][0] == s[i].back()) same[s[i][0] - '0']++;
			else if(s[i][0] == '0'){ // zo
				zo_mp[s[i]] = true;
				zo_pos.push_back(i);
				zo++;
			}
			else{ //oz
				oz_mp[s[i]] = true;
				oz_pos.push_back(i);
				oz++;
			}
		}

		if(same[0] && same[1] && same[0] + same[1] == n){
			cout << -1 << "\n";
			continue;
		}

		int diff = abs(oz - zo);

		if(diff <= 1){
			cout << 0 << "\n\n";
			continue;
		}

		if(zo > oz){
			int av = 0;
			vector<int> v;
			for(auto &idx : zo_pos){
				string rev = s[idx];
				reverse(all(rev));
				bool ok = !oz_mp[rev];
				if(ok && abs(zo - oz) > 1)
					v.push_back(idx), zo--, oz++;
			}
			if(abs(zo - oz) <= 1){
				cout << v.size() << "\n";
				for(auto &x : v) cout << x + 1 << " ";
				cout << "\n";
			}
			else
				cout << -1 << "\n";
		}
		else{
			vector<int> v;
			for(auto &idx : oz_pos){
				string rev = s[idx];
				reverse(all(rev));
				bool ok = !zo_mp[rev];
				if(ok && abs(zo - oz) > 1)
					v.push_back(idx), oz--, zo++;
			}
			if(abs(zo - oz) <= 1){
				cout << v.size() << "\n";
				for(auto &x : v) cout << x + 1 << " ";
				cout << "\n";
			}
			else
				cout << -1 << "\n";
		}

	}

	return 0;
}