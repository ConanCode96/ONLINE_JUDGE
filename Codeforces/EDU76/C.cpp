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
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int a[n];
        vector<int> pos[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            --a[i];
            pos[a[i]].push_back(i);
        }

        int res = n + 1;
        
        for(int i = 0; i < n; ++i){
            if(pos[i].size() >= 2){
                for(int j = 0; j + 1 < pos[i].size(); ++j){
                    res = min(res, pos[i][j + 1] - pos[i][j] + 1);
                }
            }
        }

        if(res == n + 1) res = -1;
        cout << res << endl;

    }

    return 0;
}