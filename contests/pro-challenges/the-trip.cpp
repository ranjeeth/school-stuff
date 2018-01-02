#include<iostream>



int main()
{
	int n, s;
	float A[1000];

	while(cin>>n && n > 0)
	{	
		s = 0;
		for(int i=0; i < n ; ++i)
		{
			cin >> A[i];
			s += A[i]; 
		}
			
	}

}
