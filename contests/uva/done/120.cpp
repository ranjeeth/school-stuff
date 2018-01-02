#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

enum {END,NEWLINE,NUMBER};
int N = 40;

void swap(int &p, int &q){ int t=p; p = q; q = t;}

int main()
{
	int S[N];
	int n,k;
	char s[1024];
	bool sorted;
	while( gets(s) != NULL ) 
	{

		int pos = 0;
		n=0;
		while( s[pos] != 0 ) 
		{
		 	while( s[pos] < '0' || s[pos] > '9' ) pos++;
		   	int num=0;
		   	while( s[pos] >= '0' && s[pos] <= '9' )
				num = num*10 + s[pos++]-'0';
   			S[n++] = num;
		} 

		cout<<S[0];
		for(int i=1; i < n; ++i)
			cout<<" "<<S[i];
		cout<<endl;

		sorted = false; 
		for( int i=n-1; !sorted && i > 0; --i)
		{
				k=0;
				sorted = true;
				for(int j=1; j <= i; ++j)
					if(S[k] <= S[j]) // note <= rather than < 
						 k = j;
					else sorted = false; 
	
					//flip at k if necessarry
					if(k < i)
					{
						// is the first flip necessary
						if(k > 0)
						{
							for(int q=0; q <= k/2 ; ++q)
								swap(S[q],S[k - q]);
							cout<< n - k <<" ";
						}
	
						//flip at i to get it back required place
						for(int q=0; q <= i/2 ; ++q)
							swap(S[q],S[i - q]);
						cout<< n - i <<" ";
					}
		}

		cout<<0<<endl;
	}
}
