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

    int n, m, d;
    cin >> n >> m >> d;

    int c[m];
    int suffix_sum = 0;
    for(int i = 0; i < m; ++i){
        cin >> c[i];
        suffix_sum += c[i];
    }

    vector<int> res(n);

    int p_it = 0;
    int at = -1;

    while(p_it < m){
        at = min(at + d, n - 1 - suffix_sum + 1);
        suffix_sum -= c[p_it];
        while(c[p_it]--) res[at++] = p_it + 1;
        at--;
        p_it++;
    }

    if(at + d >= n){
        cout << "YES" << endl;
        for(auto &x : res)
            cout << x << " ";
    }
    else{
        cout << "NO" << endl;
    }

    
    return 0;
}