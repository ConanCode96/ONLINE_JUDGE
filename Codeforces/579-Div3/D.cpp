#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;

vector<int> LC(string s){

    //KMP

    int n = int(s.size());
    std::vector<int> lcp(n);

    for(int i = 1, j = 0; i < n; ++i, ++j){
      while(j && s[j] != s[i]) j = lcp[j - 1];
      lcp[i] = j + (s[i] == s[j]);
    }

    return lcp;
}

int main(int argc, char* argv[]){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<int> LCP(n), LCS(n);


    for(int i = 0, j = 0; i < n; ++i){
        if(j < m && s[i] == t[j]) j++;
        LCP[i] = j;
    }

    for(int i = n - 1, j = m - 1; i >= 0; --i){
        if(j >= 0 && s[i] == t[j]) j--;
        LCS[i] = m - 1 - j;
    }


    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) / 2;

        bool ok = false;
        
        for(int i = 0; i + mid <= n; ++i){
            ok |= (i ? LCP[i - 1] : 0) + (i + mid < n ? LCS[i + mid] : 0) >= m;
        }

        if(ok) l = mid + 1;
        else r = mid - 1;
    }

    cout << max(0, r) << endl;

    return 0;
}