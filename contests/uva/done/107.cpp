#include<iostream>
#include<math.h>

using namespace std;


bool exact( int a, int k, int n )
{
	int p  = 1;
	for(int i=0 ; i < n ; ++i)
		p *= k;
	return ( a == p);
}

//simple given (N+1)**k and N**k find N and k and print the required values
//handle cases N=1 and k = 0 separately
int main()
{
	int k,a,b,p,q;
	double pd,qd;
	bool done;

	while(cin>>a>>b && ( a != 0 || b != 0))
	{

		if(a > 1)
		{
			for( k=1; ;++k )
			{
				pd =  pow(double(a),1.0/(double)k);
				qd =  pow(double(b),1.0/(double)k);

				if( pd - floor(pd) > 0.5)
					p = (int)(floor(pd) + 1);
				else 				
					p = (int)(floor(pd));

				if( qd - floor(qd) > 0.5)
					q = (int)(floor(qd) + 1);
				else 				
					q = (int)(floor(qd));
			
				if(exact(a,p,k) && exact(b,q,k))
						if( q + 1 == p)
							break;

			}

			//cout<<q<<" "<<k<<endl;
			if( q != 1)
				cout<<(b-1)/(q-1)<<" "<<a*p-b*q<<endl;
			else
				cout<<k<<" "<<a*p-b*q<<endl;
		}
		else
			cout<<0<<" "<<1<<endl;
	}
}
