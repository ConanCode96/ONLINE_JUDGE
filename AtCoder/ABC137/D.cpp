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

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);
    set<int> st;
    for(int i = 0; i < m; ++i) st.insert(i);
    for(int i = 0; i < n; ++i){
        cin >> a[i].Y >> a[i].X;
    }

    sort(all(a), [&](pair<int, int> x, pair<int, int> y){
        if(x.X != y.X) return x.X > y.X;
        else return x.Y > y.Y;
    });

    int res = 0;

    for(int i = 0; i < n; ++i){
        if(st.empty()) break;
        auto it = st.lower_bound(m - a[i].Y);
        if(it == st.end() || *it > m - a[i].Y) it--;
        if(it != st.end() && *it <= m - a[i].Y){
            res += a[i].X;
            st.erase(it);
        }
    }

    cout << res << endl;
 
    return 0;
}