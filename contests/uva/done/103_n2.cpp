
#include<iostream>
using namespace std;
const int MAX_BOXES = 30;
const int MAX_DIM = 10;

void print_path(int *P, int *I, int i)
{
	if( P[i] != -1)
	{
		print_path(P,I,P[i]);
		cout<<" ";
	}
	cout<<I[i]+1;
}

//borrows idea from longest monotone sequence
int main()
{

	int k,n;
	int B[MAX_BOXES][MAX_DIM],I[MAX_BOXES],L[MAX_BOXES],P[MAX_BOXES];
	int S[MAX_DIM];
	bool E[MAX_BOXES][MAX_BOXES];

	while(cin>>k>>n)
	{
		// read the boxes
		for(int i=0; i < k ; ++i) { for(int j=0; j < n ; ++j) cin>>B[i][j]; I[i] = i; }

		//bring the boxes to a canonical form
		for(int i=0; i < k ; ++i)
			for(int j=1; j < n ; ++j)
			{
				int l,key = B[i][j]; 	// simple insertion sort
				for(l = j; l > 0 && B[i][l-1] > key ; --l) B[i][l] = B[i][l-1];
				B[i][l] = key; 
			}	


		//sort on the first dimension
		for(int i=0; i < k-1 ; ++i)
		{
			int min = i;
			for( int j=i+1; j < k ; ++j)
				if( B[j][0] < B[min][0])
					min = j;	
			//S = Bi; Bi = Bmin; Bmin = S //could have used pointers here but its ok
			for(int l=0; l < n; ++l) S[l] = B[i][l];
			for(int l=0; l < n; ++l) B[i][l] = B[min][l];
			for(int l=0; l < n; ++l) B[min][l] = S[l];
			int t = I[i]; I[i] = I[min]; I[min] = t;
		}

		// build an adjacency matrix 
		for(int i=0; i < k ; ++i)
			for( int j=0; j < k ; ++j )
			{
			bool fits = true; for( int l = 0; fits && l < n ; ++l) fits = ( B[i][l] < B[j][l]) ? true : false;
			E[i][j] = fits;
			}

		
		//find the longest increasing sequence
		L[0] = 1; P[0] = -1;
		for(int i=1; i < k ; ++i)
		{
			int max = 1; P[i] = -1;
			for( int j=0; j < i; ++j )
				if( E[j][i] && max < ( L[j] + 1))
				{
					max = L[j] + 1;
					P[i] = j;
				}
			L[i] = max;
		}

		int max = 0;
		for(int i=1; i < k; ++i ) if(L[max] < L[i]) max = i;
		cout<<L[max]<<endl;
		print_path(P,I,max);
		cout<<endl;	
	}	
}
