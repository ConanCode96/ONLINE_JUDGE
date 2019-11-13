#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
const int mod = (int)1e9 + 7;

void add_self(int &x, int y){x += y; if(x >= mod) x -= mod;}
void sub_self(int &x, int y){x -= y; if(x < 0) x += mod;}
void mul(int &x, int y){x = x * 1LL * y % mod;}


int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, s;
    cin >> n >> m >> s;

    vector<int> shouldBeFixed(s);

    // broken cells
    while(n--){
        int x, y;
        cin >> x >> y;
        shouldBeFixed[--x]++, shouldBeFixed[y]--;
    }

    partial_sum(all(shouldBeFixed), shouldBeFixed.begin());

    int x[m], y[m], c[m];

    vector<int> st[s], nd[s];

    for(int i = 0; i < m; ++i){
        cin >> x[i] >> y[i] >> c[i];
        --x[i], --y[i];
        st[x[i]].push_back(i);
        nd[y[i]].push_back(i);
    }

    ll best[s]; // best cost up to index i, covering all broken cells, using some fixing segments
    memset(best, 0x7f, sizeof best);

    multiset<ll> ms;

    for(int i = 0; i < s; ++i){

        for(auto &idx : st[i]){
            ll pv = i ? best[i - 1] : 0;
            ms.insert(pv + c[idx]); // add cost, to be deleted later at the end of the segment
        }

        if (shouldBeFixed[i] && not ms.empty())
            best[i] = *ms.begin();
        
        if(shouldBeFixed[i] == 0) // no need to pay anymore for it
            best[i] = i ? best[i - 1] : 0;
        
        for(auto &idx : nd[i]){
            ll pv = x[idx] ? best[x[idx] - 1] : 0;
            auto it = ms.find(pv + c[idx]);
            assert(it != ms.end());
            ms.erase(it);
        }
    }

    ll res = best[s - 1];
    if(res > s * 1LL * 1e9) res = -1; 

    cout << res << endl;

    return 0;
}

/* Case that fails my first attempt!
1 3 3
1 3
1 3 10
1 2 1
3 3 1
*/