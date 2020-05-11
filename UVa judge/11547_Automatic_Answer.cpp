#include <bits/stdc++.h>
//#define DEBUG

using namespace std;

int main ()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    int t;
    long long n, result;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n;
        result = (((((n*567)/9)+7492)*235)/47)-498;
        //cout << result << "\n";
        if (result > (long long) 9 || result < (long long) -9)
            cout << abs((result/10)%10) << "\n";
    }
    
}