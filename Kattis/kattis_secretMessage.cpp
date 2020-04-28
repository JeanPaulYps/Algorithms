#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main ()
{
    int N;
    cin >> N;
    string message;
    while (N --)
    {
        cin >> message;
        int n = (int) ceil(sqrt(message.size()));
        char matrix [n][n];
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i*n + j) < message.size())
                    matrix[i][j] = message.at((i*n + j));
                else
                    matrix[i][j] = '*';
            }
        }
        char copy[n][n];
        for (int i = 0; i < n; i ++)
        {
            int column = n - i - 1;
            for (int  j = 0; j < n; j ++)
            {
                copy[j][column] = matrix[i][j];
            }
        }
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                if (copy[i][j] != '*')
                    cout << copy[i][j];
        if (N != 0)
            cout << endl;
    }
    /*
    int n = 4;
    char copy[n][n];
    //char matrix[n][n];
    char test [4][4] = {
        {'i','l','o','v'},
        {'e','y','o','u'},
        {'J','a','c','k'},
        {'*','*','*','*'}
    };
    //rotate the array
    for (int i = 0; i < n; i ++)
    {
        int column = n - i - 1;
        for (int  j = 0; j < n; j ++)
        {
            copy[j][column] = test[i][j];
        }
    }
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            cout << copy[i][j] << " ";
        }
        cout << endl;
    }*/

}