#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
	int n; cin>>n;
	int a[n+1][n+1];
	string s;
	char c;
	//find cumulative sums of elements in each row

	for(int i=0; i < n; ++i) a[0][i] = a[i][0] = 0;
	for(int i=1; i <= n; ++i)
		for(int j=1; j <= n; ++j)
		{
			cin>>s;
			istringstream istr(s);		

			istr>>c>>a[i][j];

			if(c == 'h')
				a[i][j] *= -2;
			if(c == 'a')
				a[i][j] *= 1;
			if(c == 'u')
				a[i][j] *= 0;
				
			a[i][j] += a[i][j-1];
		}

	
	//apply maximum subsequence algorithm across rows
	int m,t;
	m = 0;
	for(int ci=1; ci <= n ; ++ci)
		for(int cj=ci ; cj <= n; ++cj)	
		{
			t = 0;
			for(int k=1; k <= n ; ++k)
			{
				t += (a[k][cj] - a[k][ci-1]);

				if( t < 0)
					t = 0;
				else if(t > m)
					m = t;
			}			
		}

	cout<<m<<endl;
}
