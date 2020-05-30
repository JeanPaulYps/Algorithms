#include <bits/stdc++.h>

using namespace std;

void solve (int G, string &s)
{
	string chunk;
	string::reverse_iterator it;
	int index, size = ((int) s.size())/G ;
//	cout << size << "\n";
	for(int i = 0; i < G; i++)
	{
		chunk.assign(s.begin() + size*i, s.begin() + size*(i+1));
		index = size*i;
//		cout << index << " " << chunk.size() << "\n";
		for(it = chunk.rbegin() ;it != chunk.rend(); it ++)
		{
			s[index] = *it;
			index++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout << "Hello\n";
	//string s = "FA0ETASINAHGRI0NATWON0QA0NARI0";
	
//	solve(5, s);
//	cout << s << "\n";

	int G;
	string s;
	cin >> G;
	while (G)
	{
		cin >> s;
		solve(G, s);
		cout << s << "\n";
		cin >> G;
	}

}
