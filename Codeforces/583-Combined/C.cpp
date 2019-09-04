#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define X first
#define Y second
#define all(x) x.begin(), x.end()

const int MX = (int)1e5 + 10;
// const int mod = (int)1e9 + 7;

int main(){

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    stack<char> st;
    int bal = 0;

    for(auto c : s){
        bal += c == '(';
        bal -= c == ')';
        if(c == ')' && !st.empty() && st.top() == '(') st.pop();
        else st.push(c);
    }

    puts(bal == 0 && (st.empty() || st.size() == 2) ? "Yes" : "No");


    return 0;
}