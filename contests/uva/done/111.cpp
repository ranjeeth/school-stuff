#include<iostream>

using namespace std;

int main()
{
	int n,c; cin>>n;
	int t[n],r[n];
	//find original order from ranking
	for(int i=0; i < n; ++i) { cin>>c; t[c-1] = i;}
	
	int L[n+1][n+1];
	while(true)
	{
		//find students order
		for(int i=0; i < n ; ++i) 
		{ 
			if(!(cin>>c)) return 0; 
			else r[c-1] = i;
			L[i][0] = L[0][i] = 0;
		}

		//find length of longest common subsequence
		for(int i=1; i <= n ; ++i)
			for(int j=1; j <= n ; ++j)
			{
				int max = (L[i][j-1] < L[i-1][j]) ?  L[i-1][j] : L[i][j-1];
				if(r[i-1] == t[j-1] && max < L[i-1][j-1] + 1)
					max = L[i-1][j-1] + 1;
				L[i][j] = max;
			}
		cout<<L[n][n]<<endl;
	}
}
