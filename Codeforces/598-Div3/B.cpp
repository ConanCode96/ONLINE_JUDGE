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

        int a[n];
        int pos[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            --a[i];
            pos[a[i]] = i;
        }

        bool used[n] = {};

        for(int i = 0; i < n; ++i){
            int x = pos[i];
            while(x > 0 && a[x] < a[x - 1] && !used[x - 1]){
                used[x - 1] = true;
                swap(a[x], a[x - 1]);
                pos[a[x - 1]] = x - 1;
                pos[a[x]] = x;
                --x;
            }
        }

        for(int i = 0; i < n; ++i){
            cout << a[i] + 1 << " \n"[i == n - 1];
        }


    }

    
    return 0;
}