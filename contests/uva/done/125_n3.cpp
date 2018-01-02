#include<iostream>

using namespace std;
const int MAXV=30;

int main()
{
	int G[MAXV][MAXV];
	int ne,mi=0;
	int p,q,m,nv;
	
	while(cin>>ne)
	{

		for(int i=0; i < MAXV ; ++i)
			for(int j=0; j < MAXV ; ++j)
				G[i][j] = 0;

				
		m = -1;
		for(int i=0; i < ne ; ++i)
		{
			cin>>p>>q;
			G[p][q] += 1;
			// keep track of the largest vertex
			m = ( p > m) ? p : m;
			m = ( q > m) ? q : m; 	
		}
		nv = m + 1;


		//similar to floyd-warshall		
		for(int k=0; k < nv; ++k)
			for(int i=0; i < nv ; ++i)
				for(int j=0; j < nv ; ++j)
					G[i][j] += G[i][k] * G[k][j]; 


		// find the cycles in the graph
		for(int i=0; i < nv ; ++i)
			for(int j=0; j < nv ; ++j)
				for( int k=0; k < nv ; ++k)
					if(G[i][k] && G[k][j] && G[k][k])
						G[i][j] = -1;	


		//print the result
		cout<<"matrix for city "<<mi<<endl;
		for(int i=0; i < nv ; ++i)
		{
			cout<<G[i][0];
			for(int j=1; j < nv ; ++j)
				cout<<" "<<G[i][j];
			cout<<endl;
		}
	
		++mi;
	}
}
