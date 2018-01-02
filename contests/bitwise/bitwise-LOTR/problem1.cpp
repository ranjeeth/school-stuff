#include<iostream>

using namespace std;

void transfer(unsigned int n,unsigned int s,unsigned int t)
{
	if(!n)
		return;
		
	if((s%3) + 1 == t)
	{
		unsigned int i = t%3+1;
		transfer(n-1,s,i);
		cout<<s<<"  "<<t<<endl;
		transfer(n-1,i,t);
	}
	else
	{
		unsigned int i = s%3+1;
		transfer(n-1,s,t);		
		cout<<s<<"  "<<i<<endl;
		transfer(n-1,t,s);	
		cout<<i<<"  "<<t<<endl;
		transfer(n-1,s,t);		
	}
	
}


int main()
{
	unsigned int n,t,s = 1,i;
	cin>>n>>t;
	transfer(n,s,t);
}
