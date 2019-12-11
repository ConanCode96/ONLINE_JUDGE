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

		vector<pair<int, int>> g[n];
		vector<int> ed(n - 1);

		for(int id = 0; id + 1 < n; ++id){
			int x, y, z;
			cin >> x >> y >> z;
			--x, --y;
			// edges[id] = {x, y};
			ed[id] = z;
			// degree[x]++, degree[y]++;
			g[x].emplace_back(make_pair(y, id));
			g[y].emplace_back(make_pair(x, id));
		}
		sort(all(ed), greater<int>());

		vector<int> values(n), cost(n - 1);
		for(int i = 0; i < n; ++i) cin >> values[i];
		sort(all(values));

		deque<int> dq(all(values));
		// vector<bool> used(n - 1);
		// queue<int> q;

		// for(int i = 0; i < n; ++i)
		// 	if(degree[i] == 1)
		// 		q.push(i);

		int res = 0;

		// while(not q.empty()){
		// 	int x = q.front();
		// 	q.pop();

		// 	for(auto &p : g[x]){
		// 		int y = p.X;
		// 		int id = p.Y;
		// 		if(used[id]) continue;

		// 		// assert(!ed.empty());

		// 		while(!dq.empty() && dq.front() < ed.back()) dq.pop_front(), dq.push_back((int)1e9), res++;
		// 		// debug() << dq;

		// 		cost[id] = ed.back();
		// 		ed.pop_back(); // already used edge cost
		// 		used[id] = true;

		// 		degree[y]--;
		// 		if(degree[y] == 1) q.push(y);
		// 	}

		// 	int vx = dq.front();
		// 	dq.pop_front();
		// 	values[x] = vx; // the optimal value for this node?
		// }

		while(!ed.empty()){
			while(!dq.empty() && dq.front() < ed.back()) 
				dq.pop_front(), dq.push_back((int)1e9), res++;
			dq.pop_front();
			ed.pop_back();
		}

		cout << res << "\n";

		// debug() << cost;
		// debug() << values;
		// assert(res <= n);
	}

	return 0;
}