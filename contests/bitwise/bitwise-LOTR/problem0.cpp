#include<iostream>
#include<list>

using namespace std;


int main()
{
	int N,n;
	cin>>N>>n;

	list<list<int> > E;
	list<int> t1,t2;
	int a,b;

	bool af,bf;
	
	cin>>a>>b;
	t1.push_back(a);
	t2.push_back(b);

	E.push_back(t1);
	E.push_back(t2);
	
	
	for(int i=1; i < N ; ++i)
	{
		list<list<int> >::iterator k;
		list<list<int> > EN;
		cin>>a>>b;
		
		for(k = E.begin(); k != E.end() ; k++)
		{
			list<int>::iterator t;
			af = bf = true;	
			for(t = (*k).begin(); t != (*k).end() ; t++)
			{
				if(*t == -a)
					af = false;
				if(*t == -b)
					bf = false;
			}

			list<int> nt1,nt2;
			nt1 = nt2 = *k;
			nt1.push_back(a);
			nt2.push_back(b);
			if(af)EN.push_back(nt1);
			if(bf)EN.push_back(nt2);
		}
		E = EN;
	}

		
	list<list<int> >::iterator k;

	k = E.begin();
	
		list<int>::iterator t;
		(*k).sort();

		if( (*k).back()  < 0 )
			cout<<0<<endl;
		else
		{
			cout<<1<<endl;
			(*k).unique();
			t = (*k).begin();

			while(*t < 0)
				++t;
			
			for(int p=1; p <= n ; ++p)
			{
				if(*t == p)
				{
				cout<<1<<endl;
				++t;
				}
				else
				cout<<0<<endl;
			}
		}
}
