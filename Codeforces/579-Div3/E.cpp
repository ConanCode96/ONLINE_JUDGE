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
   

    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    sort(a, a + n);

    int it = 1;
    int res = 0;
    vector<int> vis(150005);
    for(int i = 0; i < n; ++i){
        if(a[i] > 1 && !vis[a[i] - 1]){
            vis[a[i] - 1] = true;
            res++;
        }
        else if(!vis[a[i]]){
            vis[a[i]] = true;
            res++;
        }
        else if(!vis[a[i] + 1]){
            vis[a[i] + 1] = true;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}