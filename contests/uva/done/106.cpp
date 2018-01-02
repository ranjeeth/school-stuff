#include<iostream>
#include<math.h>

using namespace std;

int gcd2(int m, int n)
{
	if( n == 0)
		return m;
	else return gcd2(n,m%n);	
}

int main()
{

	int n;
	while(cin>>n)
	{
		int r = (int) ceil(  sqrt( (double) n) );
	
		int s,t,x,y,z,k;
		int table[n+1],sum=0,cnt=0;

		for(int i=1; i <= n; ++i) table[i] = 0;

		//generate the triples

		for(s=1; s < r ; ++s)
			for( t=1; t < s; ++t)
			{
					
				if(gcd2(s,t) == 1 && (s%2 != t%2) )
				{
					// all triples unique since x is even and y is odd and s > t
					x = 2*s*t;
					y = s*s - t*t;
					z = s*s + t*t;
					
					// any triple is a multiple of primitive triple
					if( z <= n)
					{
						++cnt;
						for(k=1; k*z <= n ;++k)
						{
							table[k*x] = 1;
							table[k*y] = 1;
							table[k*z] = 1;
						}
					}
				}
			}

		
		for(int i=1; i <= n ; ++i)
			sum += table[i];

		cout<<cnt<<" "<<n - sum<<endl;
	}
}
