#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		int ** A,**S,**P;
		A = new int * [m];
		S = new int * [m];
		P = new int * [m];
		for(int i=0; i < m ; ++i)
		{
			A[i] = new int [n];
			S[i] = new int [n];
			P[i] = new int [n];
		}

		for(int i=0; i < m ; ++i)
			for(int j=0; j < n ; ++j)
				cin>>A[i][j];	
		

		for(int i=0; i < m ; ++i) 
				S[i][n-1] = A[i][n-1];


		// tabular solution S[p][q] holds length of the minimum wt. path
		// to row p of column q from some row of column n-1
		// P holds path (lexicographically smallest)
		int d,p,min,mind;
		for(int j=n-2; j >= 0 ; --j)
		{
			for(int i=0; i < m ; ++i)
			{
				min = RAND_MAX;
				mind = -2;

				for(d = -1; d <= 1; ++d )
				{
					if( m != 1)
						p =   ( i + d + m ) % m;
					else p = i;

					if( min > S[p][j+1])
					{
						min = S[p][j+1];
						mind = p;	
					}
					else if ( min == S[p][j+1] )	
					{
						if( mind > p)
							mind = p;
					}
					
					S[i][j] = min + A[i][j];
					P[i][j] = mind;
				}
			}
		}
	
		int mini = 0;
		for(int i=1; i < m ; ++i)
			if(S[mini][0] > S[i][0])
				mini = i;

		int r = mini;
		cout<<r+1;
		for(int j=1; j < n; ++j)
		{
			r = P[r][j-1];
			cout<<" "<<r+1;
		}
		cout<<endl;
		
		cout<<S[mini][0]<<endl;

	
		for(int i=0; i < m ; ++i)
		{
			delete [] A[i];
			delete [] S[i];
			delete [] P[i];
		}

		delete [] A;
		delete [] S;
		delete [] P;
	}
}
