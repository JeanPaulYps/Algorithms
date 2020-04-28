#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    string message;
    cin >> n;
    while (n != 0)
    {
        int key [n];
        for (int i = 0; i < n; i ++)
            cin >> key[i];
        cin.ignore(256, '\n');
        getline(cin, message);
        // cout << message << endl;
        if (message.size() % n  != 0)
            for (int i = 0; i < message.size() % n; i ++)
                message.push_back(' ');
        string result;
        char characters [n];
        for (int i = 0; i < message.size()/n ; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                result.push_back(message.at(i*n + key[j] - 1));
            }
        }
        cout << "\'" << result << "\'" << endl;  
        cin >> n;
    }
}
