// By OMAR ELAWADY
// https://codeforces.com/contest/1253/submission/65207478

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 81;
const int M = 100001;
int dp[M];
int x[N];
int s[N];
int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0;i < n;i++){
    cin >> x[i] >> s[i];
    x[i]--;
  }
  for(int i = 0;i < m;i++){
    dp[i] = i + 1;
    for(int j = 0;j < n;j++){
      int cnt = i - (x[j] + s[j]);
      cnt = max(cnt, 0);
      int p = x[j] - s[j] - 1;
      p = min(p, i - 2 * (i - x[j]) - 1);
      if(p >= i)continue;
      if(p < 0)
        dp[i] = min(dp[i], cnt);
      else
        dp[i] = min(dp[i], cnt + dp[p]);
    }
  }
  cout << dp[m - 1];
  return 0;
}