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


int greedyLIS(const vector<int>& v){    //Memory -> O(n), Time -> O(nLogn)
    int n = v.size();
    vector<int> ret;
    for(int i=0; i<n; i++){
        auto it = lower_bound(ret.begin(), ret.end(), v[i]);
        if(it == ret.end()) ret.push_back(v[i]);
        else *it = v[i];
    }
    return (int)ret.size();
}

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v1(a), v2(b), v3(c);
    for(auto &x : v1) cin >> x;
    for(auto &x : v2) cin >> x;
    for(auto &x : v3) cin >> x;

    sort(all(v1));
    sort(all(v2));
    sort(all(v3));

    vector<int> v;
    copy(all(v1), back_inserter(v));
    copy(all(v2), back_inserter(v));
    copy(all(v3), back_inserter(v));

    cout << (a + b + c) - greedyLIS(v) << endl;

    return 0;
}