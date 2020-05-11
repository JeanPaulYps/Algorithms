#include <bits/stdc++.h>
//#define DEBUG

using namespace std;

string get_country (string s)
{
    if (s == "HELLO")
        return "ENGLISH";
    else if (s == "HOLA")
        return "SPANISH";
    else if (s == "HALLO")
        return "GERMAN";
    else if (s == "BONJOUR")
        return "FRENCH";
    else if (s == "CIAO")
        return "ITALIAN";
    else if (s == "ZDRAVSTVUJTE")
        return "RUSSIAN";
    else
        return "UNKNOWN";
}

int main ()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef DEBUG
        freopen("in.txt","r",stdin);
    #endif
    string s;
    int con = 1;
    cin >> s;
    while (s != "#")
    {
        cout << "Case " << con << ": " << get_country(s) << "\n";
        cin >> s;
        con ++;
    }
    
}