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
            int n, x, a, b;
            cin >> n >> x >> a >> b;
            if(a > b) swap(a, b);
            int take = min(x, n - b);
            x -= take;
            b += take;
            take = min(x, a - 1);
            a -= take;
            cout << b - a << endl;
        }

        return 0;
    }