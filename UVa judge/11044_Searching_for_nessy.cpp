#include <bits/stdc++.h>

using namespace std;

int get_number_of_radars_per_direction (int n)
{
    return n % 3 == 0 ? n/3 : (n/3) + 1;
}



int main ()
{
    int N,n,m, i;
    cin >> N;
    while (N --)
    {
        cin >> n >> m;
        printf("%d\n", get_number_of_radars_per_direction(n - 2) * get_number_of_radars_per_direction(m - 2));
    }
    
}