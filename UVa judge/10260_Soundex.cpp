#include <bits/stdc++.h>

using namespace std;

vector <string> codex = {"", "BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"};

int get_digit(char letter)
{
    for (int i = 1; i < (int) codex.size(); i++)
    {
        if (codex[i].find(letter) != string::npos)
        {
            return i;
        }
    }
    return 0;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string line, text;
    int digit, digit_prev;
    while(getline(cin, line))
    {
        digit = get_digit(line[0]);
        if (digit) cout << digit;
        for (int i = 1; i < (int) line.size(); i ++)
        {
            digit_prev = get_digit(line[i - 1]);
            digit = get_digit(line[i]);
            if (digit && (digit_prev != digit) )
                cout << digit;
        }

        cout << "\n";
    }

}