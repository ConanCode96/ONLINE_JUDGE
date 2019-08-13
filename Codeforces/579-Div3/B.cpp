#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;

int main(int argc, char* argv[]){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
   

    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;

        int a[4 * n];
        for(int i = 0; i < 4 * n; ++i){
            cin >> a[i];
        }

        sort(a, a + 4 * n);

        deque<int> dq(a, a + 4 * n);
        
        int sz = -1;

        bool ok = true;

        while(n--){
            int a = dq.back();
            dq.pop_back();
            int c = dq.back();
            dq.pop_back();

            int b = dq.front();
            dq.pop_front();
            int d = dq.front();
            dq.pop_front();

            if(a != c || b != d || (sz != -1 && a * b != sz)){
                ok = false;
                break;
            }
            else{
                sz = a * b;
            }
        }

        puts(ok ? "YES" : "NO");
    }

    return 0;
}