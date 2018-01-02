#include<iostream>

using namespace std;

struct card
{
	char suit,rank;
};

bool cmp(card &a, card &b)
{
	return (a.suit == b.suit) || (a.rank == b.rank);
}


int main()
{
	char c;
	card piles[52][52];
	int pile_sz[52];

	while(cin>>c && c != '#')
	{
		cin.putback(c);
		int npiles = 52,max_piles = -1, cards_read=0;
		bool move;

		while(cards_read < 52)
		{

			++max_piles;
			cin>>piles[max_piles][0].suit>>piles[max_piles][0].rank;
			pile_sz[max_piles] = 1;
			++cards_read;
			move = true;

			while(move)
			{	
				move  = false;	
			
				for(int i=1; i <= max_piles; ++i )
				{
					if(pile_sz[i] > 0)
					{
					int l,t,cnt;
	
					for(l=i-1; l >= 0 && (pile_sz[l] == 0) ; --l )
						;	
					for(t=l-1,cnt=0; t >= 0 && (pile_sz[t] == 0); --t )
						;	
					for(t=t-1,cnt=0; t >= 0 && (pile_sz[t] == 0); --t )
						;	
	
					if( (t >= 0) && cmp(piles[i][pile_sz[i]-1], piles[t][pile_sz[t]-1]))
						{
							--pile_sz[i];
							if(pile_sz[i] == 0)
								--npiles;
							++pile_sz[t];
							piles[t][pile_sz[t]-1] = piles[i][pile_sz[i]];
							move = true;
							break;
						}

	
					if( (l >= 0) && cmp(piles[i][pile_sz[i]-1], piles[l][pile_sz[l]-1]))
						{
							--pile_sz[i];
							if(pile_sz[i] == 0)
								--npiles;
							++pile_sz[l];
							piles[l][pile_sz[l]-1] = piles[i][pile_sz[i]];
							move = true;
							break;
						}
					
					}
				}
			}
		}
						
		cout<<npiles<<" pile";
		if(npiles > 1)
			cout<<"s";
		cout<<" remaining:";
		for(int i=0; i < 52; ++i)
			if(pile_sz[i] > 0)
				cout<<" "<<pile_sz[i];
		cout<<endl;
	}
}
