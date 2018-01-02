



#include <iostream>

using namespace std;

int main()
{
	long i,j,n;

	//brute force
	while(cin>>i>>j)
	{
		long max=0;
		cout<<i<<" "<<j<<" ";
	if(i>j){	// interchange i and j incase they are out of order
		long t=j; j=i; i=t;
	}

	for(long t=i;t<=j;t++)
	{
		long c=1;
		n=t;
		while(n!=1)
		{
			c++;
			if(n%2==1) n=3*n+1;
			else n/=2;
		}
		if(c>max) max=c;
	}
	cout<<max<<endl;
	}
}
