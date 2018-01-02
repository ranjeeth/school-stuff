#include<iostream>

using namespace std;
const int MAXV=30;

int main()
{
	int G[MAXV][MAXV],M[MAXV][MAXV],T[MAXV][MAXV],P[MAXV][MAXV];
	int ne,mi=0;
	int p,q,m,nv;
	

	while(cin>>ne)
	{

		for(int i=0; i < MAXV ; ++i)
			for(int j=0; j < MAXV ; ++j)
			{
				G[i][j] = 0;
				M[i][j] = 0;
				P[i][j] = 0;
			}

				
		m = -1;
		for(int i=0; i < ne ; ++i)
		{
			cin>>p>>q;
			G[p][q] += 1;
			P[p][q] += 1;
			M[p][q] += 1;
			m = ( p > m) ? p : m;
			m = ( q > m) ? q : m; 	
		}
		nv = m + 1;
		
		//paths of length l (rather slow)	
		for(int l=2; l <= nv  ; ++l)
		{
			for(int i=0; i < nv ; ++i)
				for(int j=0; j < nv ; ++j)
				{
					T[i][j] = 0;
					for(int k=0; k < nv; ++k)
						T[i][j] += P[i][k]*G[k][j]; 
				}		

			for(int i=0; i < nv ; ++i)
				for(int j=0; j < nv ; ++j)
				{
					P[i][j] = T[i][j];
					M[i][j] += P[i][j];
				}						
		}


		for(int i=0; i < nv ; ++i)
			for(int j=0; j < nv ; ++j)
				for( int k=0; k < nv ; ++k)
					if(M[i][k] && M[k][j] && M[k][k])
						M[i][j] = -1;	

		cout<<"matrix for city "<<mi<<endl;
		for(int i=0; i < nv ; ++i)
		{
			cout<<M[i][0];
			for(int j=1; j < nv ; ++j)
				cout<<" "<<M[i][j];
			cout<<endl;
		}	
		++mi;
	}
}
