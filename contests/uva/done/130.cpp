#include<iostream>

using namespace std;

const int MAX_PEOPLE = 100;

struct node
{
	int id, next;
};

int main()
{
	int n,k,m,l,a,b,c,d,t;
	node P[MAX_PEOPLE];

	while( cin>>n>>k && n && k)
	{
		for(int i=0; i < n ; ++i)
		{
			P[i].id = i + 1;
			P[i].next = i + 1;	
		}
		P[n-1].next = 0;
		

		a = n-1; 
		b = 0;
		l = n;

		while(l > 1)	
		{

			// find the one to be killed
			for( m = 1; m < k ; ++m)
			{
				a = b;
				b = P[b].next;		
			}
			
			
			//kill him
			P[a].next  = P[b].next;
			l = l - 1;

			// find the one who buries 
			c = a;
			d = P[a].next;
			for( m = 1; m < k ; ++m)
			{
				c = d;
				d = P[d].next;
			}	
			
			// put him at the place of the one killed (if he is already not there)	
			if( d != a)
			{
				P[c].next = P[d].next;
				P[d].next = P[a].next;
				P[a].next = d;
			}
	
			//reset the pointers
			a = d;
			b = P[d].next;
		} 

		//find where the count should start	
		if( n != 1)	
		{
			m = (n + 1 - (P[b].id - 1) ) % n ;
			if(m == 0)
				m = n;
		}
		else m = 1; 

		cout<<m<<endl;
	}
}
