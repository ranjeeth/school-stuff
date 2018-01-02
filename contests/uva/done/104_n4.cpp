#include<iostream>

using namespace std;

const int MAX_DIM = 20;


void print_seq(int ***P, int i, int j, int l)
{
	if(l >= 0)
	{
		int q = P[i][j][l];
		if( q != -1)
		{
			print_seq(P,i,q,0);
			cout<<q+1<<" ";
			print_seq(P,q,j,l-1);	
		}
	}
}

//someting similar to Floyd Warshall but of higher complexity
int main()
{
	double E[MAX_DIM][MAX_DIM],n;
	double *** W; int ***P;
	W = new double ** [MAX_DIM]; P = new int ** [MAX_DIM];

	for(int i=0; i < MAX_DIM ; ++i){ W[i] = new double * [MAX_DIM]; P[i] = new int * [MAX_DIM];}

	for(int i=0; i < MAX_DIM ; ++i)
		for (int j=0; j < MAX_DIM ; ++j)
			{
				W[i][j] = new double [MAX_DIM];
				P[i][j] = new int [MAX_DIM];
			}

	
	while(cin>>n)
	{
		for(int i=0; i < n; ++i) { for(int j=0; j < n; ++j) if(j != i) cin>>E[i][j]; E[i][i] = 1.0;}
		
		// initial paths
		for(int i=0; i < n ; ++i) for(int j=0; j < n ; ++j)
			{ W[i][j][0] = E[i][j]; P[i][j][0] = -1;}
	
	
		bool done = false;
		// a tabular solution		 
		for(int l=1; l < n && !done ; ++l)
		{
			for(int i=0; i < n ; ++i)
				for(int j=0; j < n; ++j)
				{
					double max = 0.0; int maxp = -1;
					for(int k=0; k < n ; ++k)
					{
						
							if( max < W[i][k][0] * W[k][j][l-1] )
							{	
								max = W[i][k][0] * W[k][j][l-1];
								maxp = k;
							}
					}
					W[i][j][l] = max;
					P[i][j][l] = maxp;
				}


			for(int i=0; i < n && !done ; ++i)
				if(W[i][i][l] > 1.01)
				{
					cout<<i+1<<" ";
					print_seq(P,i,i,l);
					cout<<i+1<<endl;	
					done = true;
				}
		}
		if(!done)
			cout<<"no arbitrage sequence exists"<<endl;

	}
	
	for(int i=0; i < MAX_DIM ; ++i)
		for (int j=0; j < MAX_DIM ; ++j)
			{
				delete [] W[i][j];
				delete [] P[i][j];
			}
	for(int i=0; i < MAX_DIM ; ++i){ delete [] W[i]; delete [] P[i]; }
	delete [] W;
	delete [] P;
}

