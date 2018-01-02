
#include<iostream>
using namespace std;
const int MAX_BOXES = 30;
const int MAX_DIM = 10;

void print_path( int *** W, int *** P , int i, int j , int k)
{
			if(k >= 0)
			{
			int q;	
			q = P[i][j][k];
			if( q != -1)  
			{
				print_path(W,P,i,q,k-1);
				cout<<q+1<<" ";
				print_path(W,P,q,j,k-1);
			}
			}
}

//something similar to Floyd Warshall but see 103_n2 for better solution
int main()
{

	int k,n;
	int B[MAX_BOXES][MAX_DIM];
	bool E[MAX_BOXES][MAX_BOXES];
	//tabular solution ; W holds length and P the path
	int *** W, ***P;
	W = new int ** [MAX_BOXES]; P = new int ** [MAX_BOXES];
	for(int i=0; i < MAX_BOXES ; ++i){ W[i] = new int * [MAX_BOXES]; P[i] = new int * [MAX_BOXES]; }
	for(int i=0; i < MAX_BOXES ; ++i)
		for (int j=0; j < MAX_BOXES ; ++j)
			{
				W[i][j] = new int [MAX_BOXES - 1];
				P[i][j] = new int [MAX_BOXES - 1];
			}

	while(cin>>k>>n)
	{
		// read the boxes
		for(int i=0; i < k ; ++i) for(int j=0; j < n ; ++j) cin>>B[i][j];

		//bring the boxes to a canonical form
		for(int i=0; i < k ; ++i)
			for(int j=1; j < n ; ++j)
			{
				int l,key = B[i][j]; 	// simple insertion sort
				for(l = j; l > 0 && B[i][l-1] > key ; --l) B[i][l] = B[i][l-1];
				B[i][l] = key; 
			}	

		// build an adjacency matrix 
		for(int i=0; i < k ; ++i)
			for( int j=0; j < k ; ++j )
			{
			bool fits = true; for( int l = 0; fits && l < n ; ++l) fits = ( B[i][l] < B[j][l]) ? true : false;
			E[i][j] = fits;
			}
		
		// initial paths
		for(int i=0; i < k ; ++i)
			for(int j=0; j < k; ++j)
			{
				W[i][j][0] = (E[i][j] == 1) ? 1 : 0;
				P[i][j][0] = -1;
			}


		int i,j;
		// a tabular solution		 
		for(int l=1; l < k-1 ; ++l)
		{
			for(i=0; i < k ; ++i)
				for(j=0; j < k; ++j)
				{
					int max=W[i][j][l-1],maxp=P[i][j][l-1];
					for( int p = 0; p < k ; ++p)
					{
					
				if((W[i][p][l-1] && W[p][j][l-1]) && max < ( W[i][p][l-1] + W[p][j][l-1]) )
						{
							max = W[i][p][l-1] + W[p][j][l-1];
							maxp = p;
						}		
					}

					W[i][j][l] = max;
					P[i][j][l] = maxp;	
				}
		}
	
		int max = 0,maxi=0,maxj=0;

		for(int i=0; i < k ; ++i)
			for(int j=0; j < k; ++j)
				if(W[i][j][k-2] > max)
				{
					max = W[i][j][k-2];
					maxi = i;
					maxj = j;
				}

		cout<<max+1<<endl;
		cout<<maxi+1<<" ";
		print_path(W, P, maxi, maxj, k-2);
		if(maxi != maxj)
			cout<<maxj+1;
		cout<<endl;
	}
	
	for(int i=0; i < MAX_BOXES ; ++i)
		for (int j=0; j < MAX_BOXES ; ++j)
			{
				delete [] W[i][j];
				delete [] P[i][j];
			}
	for(int i=0; i < MAX_BOXES ; ++i){ delete [] W[i]; delete [] P[i]; }
	delete [] W;
	delete [] P;
}
