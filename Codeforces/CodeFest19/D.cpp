#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;

vector<ll> acc, tree;
int n;

void upd(int idx, int val){
    
    for(; idx <= n; idx += idx & -idx)
        tree[idx] += val;
}

ll qry(int idx){
    
    ll ret = 0;
    for( ;idx > 0; idx -= idx & -idx)
        ret += tree[idx];
        
    return ret;
    
}

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    ll a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    acc.resize(n + 1);
    tree.resize(n + 1);

    iota(all(acc), 0);
    partial_sum(all(acc), acc.begin());

    vector<int> ans(n);
    for(int i = n - 1; i >= 0; --i){
        int l = 1, r = n;
        while(l <= r){
            int mid = (l + r) / 2;
            ll res = acc[mid] - qry(mid - 1) - mid;
            if(res <= a[i])
                l = mid + 1;
            else
                r = mid - 1;
        }

        ll res = acc[r] - qry(r - 1) - r;
        // cout << r << " " << res << endl;
        assert(res == a[i]);

        ans[i] = r;
        upd(r, r);
    }


    for(auto &x : ans) cout << x << " ";
    cout << endl;    

    return 0;
}