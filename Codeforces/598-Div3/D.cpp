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

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;
        ll k;
        cin >> k;

        string s;
        cin >> s;

        // vector<int> ch[2];
        // for(int i = 0; i < n; ++i){
        //     ch[s[i] - '0'].push_back(i);
        // }

        string res;

        int cnt = 0;

        for(auto c : s){
            if(c == '1'){
                cnt++;
                continue;
            }
            
            int shift = min(cnt + 0LL, k);

            // cout << shift << " " << cnt << endl;

            k -= shift;
            int pref = cnt - shift;
            cnt -= pref;


            if(pref > 0)
                res += string(pref, '1');
            res += '0';
        }

        res += string(cnt, '1');

        cout << res << "\n";

    }
    
    return 0;
}