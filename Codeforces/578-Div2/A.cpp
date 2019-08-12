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

    string s;
    cin >> s;

    bool status[10] = {false};

    for(auto &c : s){
        if(isdigit(c)){
            status[c - '0'] = false;
        }
        else if(c == 'L'){
            for(int i = 0; i < 10; ++i){
                if(!status[i]){
                    status[i] = true;
                    break;
                }
            }
        }
        else{
            for(int i = 9; i >= 0; --i){
                if(!status[i]){
                    status[i] = true;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < 10; ++i){
        cout << status[i];
    }

    
    return 0;
}