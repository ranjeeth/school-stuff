#include<iostream>

using namespace std;

int main()
{
	int n,m1=0,m2=0,m=0;
	
	cin>>n;

	int v[n];
	int d[n];
	
	for(int i=0; i<n; ++i)
	{
		cin>>v[i];
	}

	d[0] = v[0];
	d[1] = v[0]+v[1];

	for(int i=2 ;i < n; ++i)
	{
		m=0;

		if(i-3 >= 0)
			m1= d[i-3] + v[i] + v[i-1];
		else
			m1 = v[i] + v[i-1];

		m2 = v[i] + d[i-2];

		m = ( m1 > m2 ) ? m1 : m2;

		if(m > d[i-1])
			d[i]=m;
		else
			d[i]=d[i-1];
	}

	cout<<d[n-1]<<endl;
}
