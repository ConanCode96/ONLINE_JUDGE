#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;


int find(int x, std::vector<int>& ds){
  return ds[x] < 0 ? x : ds[x] = find(ds[x], ds);
}

void unite(int x, int y, std::vector<int>& ds){
  int xx = find(x, ds);
  int yy = find(y, ds);
  if(xx != yy){
    if(ds[xx] > ds[yy]) swap(xx, yy);
    ds[xx] += ds[yy];
    ds[yy] = xx;
  }
}

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> ds(n, -1);
    for(int i = 0; i < k; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        unite(x, y, ds);
    }
    
    int res = 0;
    for(int i = 0; i < n; ++i){
        if(ds[i] < 0) res += (ds[i] * -1) - 1;
    }

    cout << k - res << endl;

    return 0;
}