#include<iostream>
#include<string>

using namespace std;
string ans;
int minmoves;
char bgc[4] = "BGC";

inline void swap(int &p,int &q){int t = p ; p = q; q = t;}



//brute force (and even a mad way doing it!! :) )
void permute(int * ind,int i,int b[][3])
{

        if(i == 2)
        {
                int moves = b[1][ind[0]]+b[2][ind[0]]+b[0][ind[1]]+b[2][ind[1]]+b[0][ind[2]]+b[1][ind[2]];

        	if(moves < minmoves)
        	{
        	        string curr;
        	        for(int j=0;j<3;++j) curr += bgc[ind[j]];
        	        ans = curr;
        	        minmoves = moves;
        	}
		if(moves == minmoves)
                {
                	string curr;
                	for(int j=0;j<3;++j) curr += bgc[ind[j]];
                	if(ans > curr) ans = curr;
                }

        	return;
        }

        for(int k = i; k < 3 ; ++k)
        {
                swap(ind[i],ind[k]);
                        permute(ind,i+1,b);
                swap(ind[i],ind[k]);
        }
}




int main()
{
	int nBottles[3][3],index[3]={0,1,2};
	while(1)
	{
		minmoves = RAND_MAX;
		for(int i=0; i < 3 ; ++i)for(int j=0; j < 3 ; ++j) if (!(cin>>nBottles[i][j])) return 0;
		permute(index,0,nBottles);
		cout<<ans<<" "<<minmoves<<endl;
	}

}
