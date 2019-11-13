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

    // auto check = [](ll x, ll y){
    //     int cnt = 0;
    //     while(x > 1){
    //         while(x % 2 == 0){
    //             cnt++, x /= 2, x *= 3;
    //         }
    //         if(x & 1) x--;
    //     }
    //     return x >= y;
    // };

    while(t--){
        int x, y;
        cin >> x >> y;

        // if(x >= y || check(x, y)){
        //     puts("YES");
        //     continue;
        // }

        // int px = 1;
        // while(px < x) px *= 2;
        // if(px > x) px /= 2;


        if((x == 1 && y > 1) || (x == 2 && y > 3) || (x == 3 && y > 3)) puts("NO");
        else puts("YES");
    }
    

    return 0;
}