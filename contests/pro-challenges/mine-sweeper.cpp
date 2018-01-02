#include<iostream>

using namespace std;

int main()
{
	int m,n,f=0;
	int A[102][102];
	char c;
	while((cin>>n>>m) && (m != 0 || n != 0))
	{	
		++f;
		if(f > 1)
			cout<<endl;
		cout<<"Field #"<<f<<":"<<endl;

		for ( int i = 1 ; i <= n ; ++i)
			for ( int j = 1 ; j <= m ; ++j)
				A[i][j] = 0;

		for ( int i = 1 ; i <= n ; ++i)
			for ( int j = 1 ; j <= m ; ++j)
			{
				cin>>c;
				if(c == '*')
				{
					A[i][j] = -1;
					for(int k = -1; k <= 1 ; ++k)
						for(int l = -1; l <= 1 ; ++l)
						A[i+k][j+l] = ( A[i+k][j+l] != -1 ) ? A[i+k][j+l] + 1 : -1;
				}
			}
	
		for ( int i = 1 ; i <= n ; ++i)
		{
			for ( int j = 1 ; j <= m ; ++j)
			{
				if( A[i][j] == -1)
					cout<<'*';
				else cout<<A[i][j];
			}
			cout<<endl;
		}
	}
}
