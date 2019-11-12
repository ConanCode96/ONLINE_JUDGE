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

    int n, m;
    cin >> n >> m;

    int x[m], y[m], c[m];

    vector<int> st[n], nd[n];

    for(int i = 0; i < m; ++i){
        cin >> x[i] >> y[i] >> c[i];
        --x[i], --y[i];
        st[x[i]].push_back(i);
        nd[y[i]].push_back(i);
    }

    ll best[n];
    memset(best, 0x7f, sizeof best);
    best[0] = 0;

    multiset<ll> ms;

    for(int i = 0; i < n; ++i){

        if (not ms.empty())
            best[i] = *ms.begin();

        for(auto &idx : st[i]){
            ms.insert(best[i] + c[idx]);
        }
        
        for(auto &idx : nd[i]){
            auto it = ms.find(best[x[idx]] + c[idx]);
            assert(it != ms.end());
            ms.erase(it);
        }
    }

    ll res = best[n - 1];
    if(res >= n * 1LL * 1e9) res = -1; 

    cout << res << endl;

    return 0;
}