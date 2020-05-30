#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int N;
	cin >> N;
	string v [20];
	string set [20];
	int con = 1;
	while (N)
	{
		for (int i = 0; i < N; i++)
			cin >> v[i];

		for (int i = 0; i < N/2; i++)
		{
			set[i] = v[2*i];
			set[N - i - 1] = v[2*i + 1];
		}
		if (N%2 == 1)
			set[N/2] = v[N-1];
		
		cout << "SET " << con << "\n";
		for (int i = 0; i < N; i++)
			cout << set[i] << "\n";
		con ++;
		cin >> N;
	}

}