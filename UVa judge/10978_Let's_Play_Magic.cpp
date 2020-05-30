#include <bits/stdc++.h>

using namespace std;

vector <string> cards;
int con;


void intialize (int size)
{
    cards.clear();
    for(int i = 0; i < size; i++)
        cards.push_back("?");
}

void insert_card(string card, string alias, int N)
{
    int card_size = (int) card.size();
    while (card_size)
    {
        con ++;
        if (cards[con % N] == "?")
        {
            card_size --;
            if(card_size == 0)
                cards[con % N] = alias;
        }
    
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,n;
    string alias, card;
    cin >> N;
    while(N)
    {
        con = -1;
        intialize(N);
        for(int i = 0; i < N; i++)
        {
            cin >> alias >> card;
            insert_card(card, alias, N);        
        }
        for(int i = 0; i < N; i++)
        {
            if (i != N - 1)
                cout << cards[i] << " ";
            else
                cout << cards[i] << "\n";
        
        }
        cin >> N;
    }

}